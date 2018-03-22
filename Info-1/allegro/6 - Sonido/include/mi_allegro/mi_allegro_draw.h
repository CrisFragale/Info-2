#ifndef MI_ALLEGRO_DRAW_H
#define MI_ALLEGRO_DRAW_H


#include "debug.h"
#include "../mi_struct.h"


void draw_simple_buffer(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct);
void draw_doble_buffer_sin_vsync(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct);
void draw_doble_buffer_con_vsync(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct);
void draw_triple_buffer(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct);

void destroy_all_draw_buffers();


#endif // MI_ALLEGRO_DRAW_H
