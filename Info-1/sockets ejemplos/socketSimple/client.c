#include "sock-lib.h"
#include "cristian.h"


int main(int argc, char * argv[])
{
	int sockfd; 
	mi_app_t mis_datos;

	init_mi_struct(&mis_datos,argv[3]); //nombre del J2

	if ((mis_datos.sockfd = cliente_conectar (argv[1], atoi(argv[2])) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}
	mi_allegro_init_windowed(800,600);

	if(init_aplicacion(&mis_datos) == 0)  // Inicializa juego
	{

		while(!mis_datos.quit)    // Dibuja hasta que se presiona escape
		{
		    while(tick < FPS_MS)
		    {
		        yield_timeslice();      // Esperar hasta que hayan pasado los ticks necesarios y el OS me dé lugar
		    }

		    while(tick >= FPS_MS)
		    {
		        // Hago logica tantas veces hasta que tick
		        // sea menor a FPS_MS como para que sea ejecutada
		        // FPS veces por segundo
		        if(logic_aplicacion(&mis_datos))
		        {
		           mis_datos.quit = 1;
		        }

		        tick -= FPS_MS;	// Decremento tick
		    }
		    draw_aplicacion(&mis_datos);
		    
		}
	}
	else
	{
		printf("No pudo iniciar timer\n");
	}

    mi_allegro_exit(&mis_datos);	// Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

    return 0;
} END_OF_MAIN()

	/* write ((sockfd, frase , sizeof (frase)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
		
			printf("Enviado: %s",frase);
		}
	}
	
	close(sockfd);
	return 0;
}
*/