#ifndef MI_STRUCT_H
#define MI_STRUCT_H


#include "mi_allegro/debug.h"
#include <allegro.h>


#define MAX_FUENTES     8
#define MAX_IMAGENES    32
#define MAX_WAVS        4
#define MAX_MIDIS       2

enum
{
    IMG_FONDO,
    IMG_OSO,
    IMG_COSITO
};

enum
{
    WAV_MUSICA
};

enum
{
    MIDI_MUSICA
};

enum
{
    TECLADO,
    MOUSE,
	JOYSTICK
};


struct mi_app
{
    FONT *fuentes[MAX_FUENTES];
    BITMAP *imagenes[MAX_IMAGENES];
    SAMPLE *wavs[MAX_WAVS];
    MIDI *midis[MAX_MIDIS];
    int pos_x;
    int pos_y;
    char teclado_o_mouse;
};

typedef     struct mi_app       mi_app_t;


void init_mi_struct(mi_app_t *app_struct);

void delete_mi_struct(mi_app_t *app_struct);


#endif // MI_STRUCT_H
