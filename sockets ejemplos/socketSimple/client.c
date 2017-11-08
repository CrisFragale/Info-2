#include "sock-lib.h"

#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/

int main(int argc, char * argv[])
{
	int sockfd;  /*File Descriptor para sockets*/
	int numbytes;/*Contendrá el número de bytes recibidos por read () */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read ()*/
	char frase[255];
	

/* Tratamiento de la línea de comandos. */
	if (argc < 3)
	{
		fprintf(stderr,"uso: %s hostname port\n",argv [0]);
		exit(1);
        }

/*Me conecto al servidor*/
	sockfd = cliente_conectar (argv[1], atoi(argv[2]));


	while( strcmp(buf, "fin\n") )
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
	  
		if( strcmp(buf, "fin\n") != 0 )
		{
			/* Contestamos al servidor */
			fgets(frase, 255, stdin);
			if (write (sockfd, frase , sizeof (frase)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
		
			printf("Enviado: %s",frase);
		}
	}
	
	
/* Devolvemos recursos al sistema */
	close(sockfd);
	return 0;
}
