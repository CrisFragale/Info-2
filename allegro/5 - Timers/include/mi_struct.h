#ifndef MI_STRUCT_H
#define MI_STRUCT_H


#include "mi_allegro/debug.h"
#include <allegro.h>


#define MAX_FUENTES     8
#define MAX_IMAGENES    32

enum
{
    IMG_FONDO,      // vale 0 (cero)
    IMG_OSO        // vale 1 (uno)
};

enum
{
    TECLADO,
    MOUSE
};


struct mi_app
{
    FONT *fuentes[MAX_FUENTES];
    BITMAP *imagenes[MAX_IMAGENES];   // bitmaps de las imagenes
    float pos_x, pos_y;
    char teclado_o_mouse;
};

typedef     struct mi_app       mi_app_t;


void init_mi_struct(mi_app_t *app_struct);

void delete_mi_struct(mi_app_t *app_struct);


#endif // MI_STRUCT_H
