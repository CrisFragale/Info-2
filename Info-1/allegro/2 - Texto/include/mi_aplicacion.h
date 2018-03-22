#ifndef MI_APLICACION_H
#define MI_APLICACION_H


#include "debug.h"
#include "mi_struct.h"


void mi_app_init(mi_app_t *app_struct);

void mi_aplicacion(mi_app_t *app_struct);

void mi_allegro_exit(mi_app_t *app_struct);


#endif // MI_APLICACION_H
