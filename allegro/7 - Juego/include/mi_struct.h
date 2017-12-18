#ifndef MI_STRUCT_H
#define MI_STRUCT_H


#include "mi_allegro/debug.h"
#include <allegro.h>


#define MAX_FUENTES     8
#define MAX_IMAGENES    32
#define MAX_WAVS        4
#define MAX_MIDIS       2
#define MAX_FIRE        8   // Cantidad maxima de "fueguitos" simultaneos

enum
{
    FUENTE_COMIENZO
};

enum
{
    IMG_FONDO,
    IMG_SONIC,
    IMG_FUEGO
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
    MENU_PRINCIPAL,
    MENU_JUEGO,
    MENU_PERDIO,
    MENU_SALIR
};

enum
{
    IMG_FIRE_1,
    IMG_FIRE_2,
    IMG_FIRE_3,
    IMG_FIRE_4,
    IMG_FIRE_MAX
};


struct mi_app
{
    FONT *fuentes[MAX_FUENTES];
    BITMAP *imagenes[MAX_IMAGENES];
    SAMPLE *wavs[MAX_WAVS];
    MIDI *midis[MAX_MIDIS];
    unsigned char menu;
    int pos_x;
    int pos_y;
    int fire_x[MAX_FIRE];
    int fire_y[MAX_FIRE];
    unsigned char fire_img;   // Define la imagen actual del fuego
	float time;
};

typedef     struct mi_app       mi_app_t;


void init_mi_struct(mi_app_t *app_struct);

void init_juego_vars(mi_app_t *app_struct);

void delete_mi_struct(mi_app_t *app_struct);


#endif // MI_STRUCT_H
