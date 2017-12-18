#ifndef MI_ALLEGRO_H
#define MI_ALLEGRO_H


#include "debug.h"
#include <allegro.h>
#include "mi_allegro_creacion.h"
#include "mi_allegro_draw.h"


void mi_allegro_init_fullscreen();
void mi_allegro_init_windowed(int desktop_width, int desktop_height);


#endif // MI_ALLEGRO_H
