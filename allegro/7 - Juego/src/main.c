#include "mi_allegro/mi_allegro.h"
#include "mi_aplicacion.h"
#include <stdio.h>


int main(void)
{
	mi_app_t mis_datos;
    char quit = 0;

    mi_allegro_init_fullscreen();      // Inicializa allegro, instala teclado, mouse, timer y crea una ventana

    init_mi_struct(&mis_datos);

    if(init_aplicacion(&mis_datos) == 0)  // Inicializa juego
	{
		while(!quit)    // Dibuja hasta que se presiona escape
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
		            quit = 1;
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

