#ifndef MI_STRUCT_H
#define MI_STRUCT_H


#include "debug.h"
#include "mi_allegro.h"


#define MAX_FUENTES 32


struct mi_app
{
    FONT *fuentes[MAX_FUENTES];
};

typedef     struct mi_app       mi_app_t;


void init_mi_struct(mi_app_t *app_struct);

void delete_mi_struct(mi_app_t *app_struct);


#endif // MI_STRUCT_H
