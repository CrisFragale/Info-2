#include "mi_allegro.h"

char mi_allegro_init()
{
    int desktop_width, desktop_height;
    char return_value;


    if(allegro_init() != 0)
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
		if(get_desktop_resolution(&desktop_width, &desktop_height))    // Obtiene la resolucion del escritorio
		{
		    // No pudo obtener resolucion de escritorio

		    desktop_width = 320;
		    desktop_height = 200;
		}
		if(set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, desktop_width, desktop_height, 0, 0))
		{
		    // No pudo crear ventana grafica

		    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		    allegro_message("[ERROR] No pudo crear ventana grafica:\n\t%s\n", allegro_error);
		        // Muestra cuadro de texto

		    exit(-2);
		}
		else
		{
		    clear_to_color(screen, makecol(128, 128, 128));	// Pinta todo el bitmap de un color

		    return_value = 0;
		}
	}


    return return_value;
}
