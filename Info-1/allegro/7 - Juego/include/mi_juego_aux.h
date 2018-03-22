#ifndef MI_JUEGO_AUX_H
#define MI_JUEGO_AUX_H


#include "mi_struct.h"
#include "mi_aplicacion.h"


#define FIRE_MS  (100)


void movimiento_sonic(mi_app_t *app_struct);
void generate_fire(mi_app_t *app_struct);
void change_fire_img(mi_app_t *app_struct);
char colision(mi_app_t *app_struct);


#endif // MI_JUEGO_AUX_H
