#include "sock-lib.h"

#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/

int main (int argc, char * argv[])
{
	int sockfd;			/* File Descriptor del socket por el que el
					servidor "escuchará" conexiones*/
	char frase[255];
	int sockdup; 
	
	int numbytes;/*Contendrá el número de bytes recibidos por read () */
	char buf[MAXDATASIZE];
	
	if( argc < 2 )
	{
	    fprintf(stderr,"uso: %s port\n",argv [0]);
	    exit(1);
	  
	}

	if ((sockfd = servidor_abrirConexion ( atoi(argv[1]))) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while(1)
	{
		sockdup = servidor_aceptarPedidos (sockfd);

		while( strcmp(frase, "fin\n") )
		{
		    /* Enviamos datos al cliente */
		    fgets(frase, 255, stdin);
		    if (write (sockdup, frase , sizeof (frase)) == -1)
		    {
			perror("Error escribiendo mensaje en socket");
			exit (1);
		    }
		    printf("Enviado: %s",frase);		    

		    if( strcmp(frase, "fin\n") != 0)
		    {
			/* Recibimos los datos del cliente */
			if ((numbytes = read (sockdup, buf, MAXDATASIZE)) <= 0)
			{
			    perror("error de lectura en el socket");
			    exit(1);
			}
			/* Visualizamos lo recibido */
			buf[numbytes] = '\0';
			printf("Recibido: %s",buf);
		    }
		}
		close(sockdup);
		strcpy(frase, "");
	}
	exit(0);
}
