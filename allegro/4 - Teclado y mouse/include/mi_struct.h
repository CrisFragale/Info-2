#ifndef MI_STRUCT_H
#define MI_STRUCT_H


#include "mi_allegro/debug.h"
#include <allegro.h>


#define MAX_FUENTES     8
#define MAX_IMAGENES    32


// Para variable 'imagenes'
enum
{
    IMG_FONDO,      // vale 0 (cero)
    IMG_OSO        // vale 1 (uno)
};


// Para variable 'teclado_o_mouse'.
// Define si estoy en modo TECLADO o 
// modo MOUSE en la aplicacion para
// mover el oso con el teclado o con
// el mouse respectivamente
enum
{
    TECLADO,      // vale 0 (cero)
    MOUSE        // vale 1 (uno)
};


struct mi_app
{
    FONT *fuentes[MAX_FUENTES];
    BITMAP *imagenes[MAX_IMAGENES];   // bitmaps de las imagenes

    int pos_x;
    int pos_y;
    char teclado_o_mouse; // 0: teclado, 1: mouse
};

typedef     struct mi_app       mi_app_t;


void init_mi_struct(mi_app_t *app_struct);

void delete_mi_struct(mi_app_t *app_struct);


#endif // MI_STRUCT_H
