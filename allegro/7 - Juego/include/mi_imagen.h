#ifndef MI_IMAGEN_H
#define MI_IMAGEN_H


#include "mi_struct.h"


#define SONIC_WIDTH     41
#define SONIC_HEIGHT    66

#define FIRE_WIDTH      75
#define FIRE_HEIGHT     75


enum
{
    DRAW_SONIC_IDLE,
    DRAW_SONIC_IZQ,
    DRAW_SONIC_DER
};

enum
{
    DRAW_FIRE_1,
    DRAW_FIRE_2,
    DRAW_FIRE_3,
    DRAW_FIRE_4
};


void draw_sonic(unsigned char sector, BITMAP *buffer, mi_app_t *app_struct);
void draw_fuegos(BITMAP *buffer, mi_app_t *app_struct);


#endif // MI_IMAGEN_H
