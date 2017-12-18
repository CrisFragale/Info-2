#include "mi_aplicacion.h"


void texto_izquierda(FONT *font);
void texto_centro(FONT *font);
void texto_derecha(FONT *font);
void texto_justificado(FONT *font);


void mi_app_init(mi_app_t *app_struct)
{
    assert(app_struct);    // SIEMPRE comprobar valor de los punteros !!!

    init_mi_struct(app_struct);

    app_struct->fuentes[0] = load_font("./fuentes/fuente_1.pcx",NULL,NULL);

	assert(app_struct->fuentes[0]);

    /* Carga fuente propia usando "ttf2pcx.exe".
     * Las fuentes han de cargarse luego de inicializar allegro.
     */
}

void mi_aplicacion(mi_app_t *app_struct)
{
    FONT *mi_font = NULL;    // SIEMPRE inicializar punteros a NULL !!!

    assert(app_struct);

    mi_font = app_struct->fuentes[0];

    assert(mi_font);

    texto_derecha(mi_font);

    texto_centro(mi_font);

    texto_izquierda(mi_font);

    texto_justificado(font);
        // font: fuente de texto predeterminado. Se define al inicializar allegro (variable global).


    /* Funciones de Texto:
        textout_ex:             Escribe texto alineado a izquierda en un bitmap.
        textout_centre_ex:      Escribe texto centrado en un bitmap.
        textout_right_ex:       Escribe texto alineado a derecha en un bitmap.
        textout_justify_ex:     Escribe texto justificado en un bitmap.
        textprintf_ex:          Escribe texto formateado alineado a izquierda en un bitmap.
        textprintf_centre_ex:   Escribe texto formateado centrado en un bitmap.
        textprintf_right_ex:    Escribe texto formateado alineado a derecha en un bitmap.
        textprintf_justify_ex:  Escribe texto formateado justificado en un bitmap.
    */
}


// Imprime texto alineado a izquierda
void texto_derecha(FONT *font)
{
    int x = 500, y = 0;
    int text_color = makecol(255, 0, 0);
    int background_color = makecol(255, 255, 255);
        /* makecol(red,green,blue): recibe enteros, del 0 al 255, de los colores
        *                          rojo(red), verde(green) y azul(blue) y devuelve
        *                          el codigo (numero entero) que lo representa.
        */

    assert(font);


    /* void textout_ex(BITMAP *bmp, const FONT *f, const char *s, int x, int y, int color, int bg);
     * bmp:     Bitmap (mapa de bits) donde se quiere escribir el texto.
     * f:       Fuente del texto (tamaño y estilo de letra).
     * s:       Texto
     * x, y:    Posicion en pixeles donde comienza el texto (0,0: esquina superior izquierda)
     * color:   Color del texto
     * bg:      Color de fondo del texto
     */
    textout_right_ex(screen, font, "Hola mundo", x, y, text_color, background_color);
        /* screen: bitmap de la ventana. Se define al crear la ventana (variable global).
         * posicion(x, y): indica la posicion donde termina el texto
         */
}


// Imprime texto centrado
void texto_centro(FONT *font)
{
    int x = 500, y = text_height(font);
        // text_height(FONT *f): Devuelve el alto (en pixeles) de la fuente f.
    int text_color = makecol(0, 255, 0);
    int background_color = -1;
        // color = -1: transparente

    assert(font);

    textprintf_centre_ex(screen, font, x, y, text_color, background_color,
							"Version: %s - Width = %d, Height = %d", allegro_id, SCREEN_W, SCREEN_H);
        // posicion(x, y): indica la posicion donde se encuentra el centro del texto
}


// Imprime texto alineado a derecha
void texto_izquierda(FONT *font)
{
    char *sistema_operativo = NULL;

    int x = 500, y = text_height(font)*2;

    assert(font);

    switch(os_type)
    {
    case OSTYPE_UNIX:
        sistema_operativo = "Variante Unix desconocida";
        break;
    case OSTYPE_SUNOS:
        sistema_operativo = "SunOS";
        break;
    case OSTYPE_NETBSD:
        sistema_operativo = "NetBSD";
        break;
    case OSTYPE_WIN3:
        sistema_operativo = "Windows 3.1 o anterior";
        break;
    case OSTYPE_DOSEMU:
        sistema_operativo = "Linux DOSEMU";
        break;
    case OSTYPE_OS2:
        sistema_operativo = "OS/2";
        break;
    case OSTYPE_WIN2000:
        sistema_operativo = "Windows 2000";
        break;
    case OSTYPE_WIN2003:
        sistema_operativo = "Windows 2003";
        break;
    case OSTYPE_DARWIN:
        sistema_operativo = "Darwin OS";
        break;
    case OSTYPE_OPENDOS:
        sistema_operativo = "Open DOS";
        break;
    case OSTYPE_FREEBSD:
        sistema_operativo = "Free BSD";
        break;
    case OSTYPE_MACOS:
        sistema_operativo = "Mac OS";
        break;
    case OSTYPE_QNX:
        sistema_operativo = "QNX";
        break;
    case OSTYPE_LINUX:
        sistema_operativo = "LINUX";
        break;
    case OSTYPE_WARP:
        sistema_operativo = "OS/2 Warp";
        break;
    case OSTYPE_OPENBSD:
        sistema_operativo = "Open BSD";
        break;
    case OSTYPE_WINVISTA:
        sistema_operativo = "Windows Vista";
        break;
    case OSTYPE_WIN95:
        sistema_operativo = "Windows 95";
        break;
    case OSTYPE_WIN98:
        sistema_operativo = "Windows 98";
        break;
    case OSTYPE_MACOSX:
        sistema_operativo = "Macos X";
        break;
    case OSTYPE_IRIX:
        sistema_operativo = "Irix OS";
        break;
    case OSTYPE_BEOS:
        sistema_operativo = "Be OS";
        break;
    case OSTYPE_WINXP:
        sistema_operativo = "Windows XP";
        break;
    case OSTYPE_WINME:
        sistema_operativo = "Windows ME";
        break;
    case OSTYPE_WINNT:
        sistema_operativo = "Windows NT";
        break;
    default:
        sistema_operativo = "Desconocido o MSDOS normal";
        break;
    }

    textprintf_ex(screen, font, x, y, makecol(0, 0, 255), makecol(0, 0, 0), "sistema operativo: %s", sistema_operativo);
        // posicion(x, y): indica la posicion donde empieza a escribirse el texto
}

// Imprime texto justificado
void texto_justificado(FONT *font)
{
    int i;
    char *lines[] = {"Dibuja un texto",
                       "justificado dentro",
                       "del area especificado",
                       "entre x1 y x2"};
    int x1  = 0;
    int x2  = 500;
    int y   = 400;
    int dif = x2-x1;
    int text_color = makecol(0, 0, 0);
    int bg_color = makecol(255, 255, 255);

    assert(font);


    vline(screen, x2, y, SCREEN_H-1, makecol(0, 0, 0)); // Dibuja una linea vertical

    for(i=0; i<4; i++, y+=text_height(font))
        textout_justify_ex(screen, font, lines[i], x1, x2, y, dif, text_color, bg_color);
}


void mi_allegro_exit(mi_app_t *app_struct)
{
    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

    assert(app_struct);

    delete_mi_struct(app_struct);
}
