#ifndef MI_APLICACION_H
#define MI_APLICACION_H


#include "mi_allegro/debug.h"
#include "mi_struct.h"


void init_aplicacion(mi_app_t *app_struct);
void do_aplicacion(mi_app_t *app_struct);

void mi_allegro_exit(mi_app_t *app_struct);



#endif // MI_APLICACION_H
