#include <allegro.h>
#include <stdio.h>


int main()
{
    int color_depth;
    char titulo[64];


	// inicializa allegro. (Devuelve 0 en caso de exito)
	// Se debe llamar al comienzo del programa
    if(allegro_init() != 0)
	{
		printf("No pudo inicializar allegro. (Esta bien instalado?)\n");
		exit(-1);
	}

    install_keyboard();     // inicializa rutinas de teclado
    install_mouse();        // inicializa rutinas de mouse
    install_timer();        // inicializa rutinas de timer


    color_depth = desktop_color_depth();    // Devuelve la profundidad de color del escritorio.

    sprintf(titulo, "Titulo de ventana allegro :D - depth: %d", color_depth);

    set_window_title(titulo);               // Setea un titulo a la ventana

    set_color_depth(color_depth);           // Setea profundidad de color.
                                            // valores validos: 8(predeterminado), 15, 16, 24, y 32


    //int set_gfx_mode(int card, int w, int h, int v_w, int v_h)
        /* Crea una ventana allegro y permite establecer uno
         * entre distintos modos graficos.
         *
         * card:    GFX_AUTODETECT: setea la resolucion y profundidad de
         *              color especificada en pantalla completa, si falla
         *              la setea en modo ventana.
         *          GFX_AUTODETECT_FULLSCREEN: setea la resolucion y
         *              profundidad de color especificada en pantalla
         *              completa. si no puede, la funcion falla.
         *          GFX_AUTODETECT_WINDOWED: setea la resolucion y
         *              profundidad de color especificada en modo
         *              ventana. Si no puede, la funcion falla. Tener en
         *              cuenta que un modo ventana corriendo a una profundidad
         *              de color distinta a la del escritorio, puede resultar
         *              en una performance no optima debido a conversiones
         *              de color en el driver de video.
         *          GFX_SAFE: Tratará de setear la resolucion y profundidad
         *              de color especificada. Si falla, busca una resolucion
         *              soportada por la plataforma actual (320x200 en DOS,
         *              640x480 en Windows, etc). Si no puede setear ningun
         *              modo grafico, la funcion falla, lo que significa
         *              que la maquina actual no soporta ninguna salida de
         *              video.
         * w, h: Ancho y alto respectivamente (resolucion) de la ventana.
         *      La profundidad de como, debe ser especificada con
         *      set_color_depth() antes de llamar a esta funcion.
         * v_w, v_h: Especifican el ancho y alto minimo de ventana virtual,
         *      en caso que se necesite una ventana virtual mas grande que
         *      la ventana fisica para hacer cambios de pagina o scrolling.
         *      Se debe setear en 0 (cero) en caso de no importar.
         *      El rango de tamaños posibles es usualmente muy limitado,
         *      dependen del driver de video y algunos drivers no permiten
         *      ventanas virtuales mas grandes que la ventana fisica, lo
         *      cual es recomenable usar "0,0" para mayor compatibilidad.
         * Retorno: Devuelve 0 (cero) en caso de exito. Devuelve un numero
         *      negativo en caso de falla y guarda una descripcion del
         *      problema en allegro_error.
         *
         * Luego de elegir un modo grafico, los tamaños de ventana fisico
         * y virtual pueden ser chequeados con las macros SCREEN_W, SCREEN_H,
         * VIRTUAL_W, and VIRTUAL_H.
         */


    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0); // Crea la ventana


    rest(5000); // Espera 5000 milisegundos (5 segundos)


    allegro_exit(); /* Desinstala rutinas como mouse, teclado y timer, y cierra Allegro.
                     * No es necesario hacer una llamada explicita a esta funcion porque
                     * allegro_init() la llama en su rutina de salida, por lo que será
                     * llamada automaticamente al terminar el programa.
                     * Tener en cuenta que luego de llamar a esta funcion, otras funciones
                     * como destroy_bitmap() podrían producir errores en tiempo de ejecucion.
                     */

    return 0;
} END_OF_MAIN()
/* END_OF_MAIN():
 * La macro END_OF_MAIN es necesaria para asegurar
 * la compatibilidad entre distintas plataformas.
 *
 * DOS: No es necesario
 *
 * UNIX: No es necesario
 *
 * WINDOWS: En Windows es necesario porque Windows
 * usa la funcion WinMain como punto de entrada en
 * lugar de main. La macro END_OF_MAIN hace que
 * Windows acepte un linkeo contra un main regular.
 * Primero, la macro END_OF_MAIN renombra main a
 * _mangled_main para evitar conflictos sobre el
 * simbolo main. Luego crea una funcion WinMain el
 * cual llama a la funcion _mangled_main. De esta
 * forma son soportados tanto la llamada al main
 * de la forma main(), como de la forma
 * main(int argc, char** argv).
 *
 * NOTA: NO se debe incluir ";" (punto y coma)
 * luego de la macro END_OF_MAIN().
 */

/* Para mas informacion, visitar las siguientes paginas:
http://alleg.sourceforge.net/stabledocs/en/allegro.html
http://es.slideshare.net/residentejf/manual-allegro-c
*/
