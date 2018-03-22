#include "sock-lib.h"

#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/

int main (int argc, char * argv[])
{
	fd_set descriptoresLectura; 
	int maximo;

	while(1)
	{
		sockdup = servidor_aceptarPedidos (sockfd);
		
		
		FD_ZERO (&descriptoresLectura); 
		FD_SET (sockdup, &descriptoresLectura); 
		FD_SET (fileno(stdin), &descriptoresLectura); 
	
		if( fileno(stdin) < sockdup )
		  maximo = sockdup;
		else
		  maximo = fileno(stdin);

		while( strcmp(frase, "fin\n") )
		{
		    select (maximo+1, &descriptoresLectura, NULL, NULL, NULL);
		    if (FD_ISSET (sockdup, &descriptoresLectura)) 
		    {
			    /* Recibimos los datos del servidor */
			    if ((numbytes = read (sockdup, buf, MAXDATASIZE)) <= 0)
			    {
				    perror("error de lectura en el socket");
				    exit(1);
			    }
			    /* Visualizamos lo recibido */
			    buf[numbytes] = '\0';
			    printf("Recibido: %s",buf); 
                strcpy(frase, buf);
		    }
		    else if (FD_ISSET ( fileno(stdin) , &descriptoresLectura)) 
		    {
			    /* Recibimos los datos del servidor */
			    fgets(frase, 255, stdin);
			    /* Visualizamos lo recibido */
			    if (write (sockdup, frase , sizeof (frase)) == -1)
			    {
				    perror("Error escribiendo mensaje en socket");
				    exit (1);
			    }
			
			    printf("Enviado: %s",frase);
		    }
            		               
       
            FD_ZERO (&descriptoresLectura); 		        
            FD_SET (sockdup, &descriptoresLectura); 
	        FD_SET (fileno(stdin), &descriptoresLectura); 
            
		}
		close(sockdup);
        strcpy(frase, "");
	}
	exit(0);
}
