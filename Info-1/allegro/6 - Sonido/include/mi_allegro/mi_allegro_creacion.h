#ifndef MI_ALLEGRO_CREACION_H
#define MI_ALLEGRO_CREACION_H


#include "debug.h"
#include <allegro.h>


BITMAP *cargar_img(char *img_filename);
BITMAP *Crear_video_buffer();
BITMAP *Crear_buffer();
MIDI *cargar_midi(char *audio_filename);
SAMPLE *cargar_audio(char *audio_filename);


#endif // MI_ALLEGRO_CREACION_H
