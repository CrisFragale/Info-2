#include "sock-lib.h"
 #include "cliente.h"

int main(int argc, char * argv[])
{
	int sockfd;  /*File Descriptor para sockets*/
	int numbytes;/*Contendrá el número de bytes recibidos por read () */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read ()*/
	int fin = 0;
	char frase[255];
	
	/*Para el select*/
	fd_set descriptoresLectura; 
	int maximo;

/* Tratamiento de la línea de comandos. */
	if (argc < 3)
	{
		fprintf(stderr,"uso: %s hostname port\n",argv [0]);
		exit(1);
        }

/*Me conecto al servidor*/
	sockfd = cliente_conectar (argv[1], atoi(argv[2]));

/*Pongo los files descriptors del teclado y el socket en un select para poder leer los dos*/
	FD_ZERO (&descriptoresLectura); 
	FD_SET (sockfd, &descriptoresLectura); 
	FD_SET (fileno(stdin), &descriptoresLectura); 
	
	if( fileno(stdin) < sockfd )
	  maximo = sockfd;
	else
	  maximo = fileno(stdin);

	while( strcmp(frase, "fin\n") )
	{
	    select (maximo+1, &descriptoresLectura, NULL, NULL, NULL);
	    if (FD_ISSET (sockfd, &descriptoresLectura)) 
	    {
		    /* Recibimos los datos del servidor */
		    if ((numbytes = read (sockfd, buf, MAXDATASIZE)) <= 0)
		    {
			    perror("error de lectura en el socket");
			    exit(1);
		    }
		    /* Visualizamos lo recibido */
		    buf[numbytes] = '\0';
		    printf("Recibido: %s",buf);
            strcpy(frase, buf);
	    }
	    if (FD_ISSET ( fileno(stdin) , &descriptoresLectura)) 
	    {
		    /* Recibimos los datos del servidor */
		    fgets(frase, 255, stdin);
		    /* Visualizamos lo recibido */
		    if (write (sockfd, frase , sizeof (frase)) == -1)
		    {
			    perror("Error escribiendo mensaje en socket");
			    exit (1);
		    }
		
		    printf("Enviado: %s",frase);
	    }
	
        FD_ZERO (&descriptoresLectura); 
        FD_SET (sockfd, &descriptoresLectura); 
        FD_SET (fileno(stdin), &descriptoresLectura); 
        	
    }
	
	
/* Devolvemos recursos al sistema */
	close(sockfd);
	return 0;
}
