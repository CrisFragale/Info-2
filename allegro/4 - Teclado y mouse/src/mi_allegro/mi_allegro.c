#include "mi_allegro.h"


int mi_allegro_at_exit(void (* func_ptr)(void));


void mi_allegro_init_fullscreen()
{
    int desktop_width, desktop_height;


	// int install_allegro(int system_id, int *errno_ptr, int (*atexit_ptr)());
    /* allegro_init();
     *      =
     * install_allegro(SYSTEM_AUTODETECT, &errno, atexit);
     */
	if(install_allegro(SYSTEM_AUTODETECT, &errno, mi_allegro_at_exit) != 0)
    {
        // No pudo inicializar allegro

        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("[ERROR] No pudo inicializar allegro (esta bien instalado?). Error:\n\t%s\n", allegro_error);
            // Muestra cuadro de texto

        exit(-1);
    }
	else
	{
		install_keyboard();
		install_mouse();
		install_timer();

		set_color_depth(desktop_color_depth());
		if(get_desktop_resolution(&desktop_width, &desktop_height) != 0)    // Obtiene la resolucion del escritorio
		{
		    // No pudo obtener resolucion de escritorio

		    desktop_width = 320;
		    desktop_height = 200;
		}


		// Los Video_Buffer (Para usar VSync) son parte del 'screen'. por lo tanto, para crear varios Video_Buffers debo
		// Asignar memoria virtual extra para el 'screen'. (Por eso el 'desktop_width*2' y 'desktop_height*2')
		if(set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, desktop_width, desktop_height, desktop_width*2, desktop_height*2) != 0)
		{
		    // No pudo crear ventana grafica

		    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		    allegro_message("[ERROR] No pudo crear ventana grafica. Error:\n\t%s\n", allegro_error);
		        // Muestra cuadro de texto

		    exit(-2);
		}

		clear_to_color(screen, makecol(128, 128, 128));	// Pinta todo el bitmap de un color
	}
}

void mi_allegro_init_windowed(int desktop_width, int desktop_height)
{
	// int install_allegro(int system_id, int *errno_ptr, int (*atexit_ptr)());
    /* allegro_init();
     *      =
     * install_allegro(SYSTEM_AUTODETECT, &errno, atexit);

     */
	if(install_allegro(SYSTEM_AUTODETECT, &errno, mi_allegro_at_exit) != 0)
    {
        // No pudo inicializar allegro

        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("[ERROR] No pudo inicializar allegro (esta bien instalado?). Error:\n\t%s\n", allegro_error);
            // Muestra cuadro de texto

        exit(-1);
    }
	else
	{
		install_keyboard();
		install_mouse();
		install_timer();

		set_color_depth(desktop_color_depth());


		// Los Video_Buffer (Para usar VSync) son parte del 'screen'. por lo tanto, para crear varios Video_Buffers debo
		// Asignar memoria virtual extra para el 'screen'. (Por eso el 'desktop_width*2' y 'desktop_height*2')
		if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, desktop_width, desktop_height, desktop_width*2, desktop_height*2) != 0)
		{
		    // No pudo crear ventana grafica

		    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		    allegro_message("[ERROR] No pudo crear ventana grafica. Error:\n\t%s\n", allegro_error);
		        // Muestra cuadro de texto

		    exit(-2);
		}

		clear_to_color(screen, makecol(128, 128, 128));	// Pinta todo el bitmap de un color
	}
}

int mi_allegro_at_exit(void (* func_ptr)(void))
{
    destroy_all_draw_buffers();

    return atexit(func_ptr);
}
