#ifndef MI_APLICACION_H
#define MI_APLICACION_H


#include "mi_aplicacion_timer.h"
#include "mi_struct.h"


#define FPS_MS 16


int init_aplicacion(mi_app_t *app_struct);
char logic_aplicacion(mi_app_t *app_struct);
void draw_aplicacion(mi_app_t *app_struct);

void mi_allegro_exit(mi_app_t *app_struct);



#endif // MI_APLICACION_H
