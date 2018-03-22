#ifndef MI_JUEGO_H
#define MI_JUEGO_H


#include "mi_struct.h"
#include "mi_aplicacion.h"


void logic_menu_principal(mi_app_t *app_struct);
void logic_juego(mi_app_t *app_struct);
void logic_perdio(mi_app_t *app_struct);

void draw_menu_principal(BITMAP *buffer, mi_app_t *app_struct);
void draw_juego(BITMAP *buffer, mi_app_t *app_struct);
void draw_perdio(BITMAP *buffer, mi_app_t *app_struct);


#endif // MI_JUEGO_H
