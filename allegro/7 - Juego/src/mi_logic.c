#include "mi_juego.h"
#include "mi_imagen.h"
#include "mi_juego_aux.h"


void logic_menu_principal(mi_app_t *app_struct)
{
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(key[KEY_ENTER])
        (*menu) = MENU_JUEGO;

    if(key[KEY_ESC])
        (*menu) = MENU_SALIR;
}

void logic_juego(mi_app_t *app_struct)
{
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(key[KEY_ESC])
    {
        (*menu) = MENU_SALIR;
        return;
    }

    movimiento_sonic(app_struct);

    generate_fire(app_struct);
    change_fire_img(app_struct);

    if(colision(app_struct))
    {
        (*menu) = MENU_PERDIO;
    }
}

void logic_perdio(mi_app_t *app_struct)
{
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	assert(menu);

    if(key[KEY_ENTER])
    {
        init_juego_vars(app_struct);
        (*menu) = MENU_JUEGO;
    }

    if(key[KEY_ESC])
        (*menu) = MENU_SALIR;
}




/***************************************************************************/
/*							FUNCIONES AUXILIARES			   			   */
/***************************************************************************/


void movimiento_sonic(mi_app_t *app_struct)
{
    float desplazamiento = 0.5*FPS_MS;
    int *pos_x;
    int *pos_y;

	assert(app_struct);

    pos_x = &(app_struct->pos_x);
    pos_y = &(app_struct->pos_y);

	assert(pos_x);
	assert(pos_y);

	// Movimiento
    if(key[KEY_LEFT]) (*pos_x) -= desplazamiento;
    if(key[KEY_RIGHT]) (*pos_x) += desplazamiento;
    if(key[KEY_UP]) (*pos_y) -= desplazamiento;
    if(key[KEY_DOWN]) (*pos_y) += desplazamiento;

	// Limites
    if( (*pos_x) > SCREEN_W - SONIC_WIDTH/2)
        (*pos_x) = SCREEN_W - SONIC_WIDTH/2;

    if( (*pos_x) < SONIC_WIDTH/2)
        (*pos_x) = SONIC_WIDTH/2;

    if( (*pos_y) > SCREEN_H - SONIC_HEIGHT/2)
        (*pos_y) = SCREEN_H - SONIC_HEIGHT/2;

    if( (*pos_y) < SONIC_HEIGHT/2)
        (*pos_y) = SONIC_HEIGHT/2;
}

void generate_fire(mi_app_t *app_struct)
{
    int desplazamiento = 0.5*FPS_MS;
    int *fire_x;
    int *fire_y;
    int i;

	assert(app_struct);

    for(i=0; i<MAX_FIRE; i++)
    {
        fire_x = &(app_struct->fire_x[i]);
        fire_y = &(app_struct->fire_y[i]);

		assert(fire_x);
		assert(fire_y);

        (*fire_y) += desplazamiento;

        if( (*fire_y) > SCREEN_H )
        {
            (*fire_y) = -FIRE_HEIGHT;
            (*fire_x) = rand()%(SCREEN_W-FIRE_WIDTH);
        }
    }
}

void change_fire_img(mi_app_t *app_struct)
{
    float *time;
    unsigned char *fire_img;

	assert(app_struct);

	fire_img = &(app_struct->fire_img);
	time = &(app_struct->time);

	assert(fire_img);
	assert(time);

    (*fire_img) = (((int)(*time)/FIRE_MS))%IMG_FIRE_MAX;	//Cambia de imagen del fuego 1 vez de cada FIRE_MS milisegundos
}


char colision(mi_app_t *app_struct)
{
    int pos_x;
    int pos_y;
    int fire_x;
    int fire_y;
    int i;

	assert(app_struct);

    pos_x = app_struct->pos_x;
    pos_y = app_struct->pos_y;


    for(i=0; i<MAX_FIRE; i++)
    {
        fire_x = app_struct->fire_x[i];
        fire_y = app_struct->fire_y[i];

        if( (pos_x + SONIC_WIDTH/3 > fire_x + FIRE_WIDTH/4) && (pos_x + SONIC_WIDTH/3 < fire_x + (FIRE_WIDTH*3)/4) && (pos_y + SONIC_HEIGHT/4 > fire_y + FIRE_WIDTH/4) && (pos_y + SONIC_HEIGHT/4 < fire_y + (FIRE_WIDTH*3)/4) )
            return 1;
        if( (pos_x + SONIC_WIDTH/3 > fire_x + FIRE_WIDTH/4) && (pos_x + SONIC_WIDTH/3 < fire_x + (FIRE_WIDTH*3)/4) && (pos_y - SONIC_HEIGHT/4 > fire_y + FIRE_WIDTH/4) && (pos_y - SONIC_HEIGHT/4 < fire_y + (FIRE_WIDTH*3)/4) )
            return 1;
        if( (pos_x - SONIC_WIDTH/3 > fire_x + FIRE_WIDTH/4) && (pos_x - SONIC_WIDTH/3 < fire_x + (FIRE_WIDTH*3)/4) && (pos_y + SONIC_HEIGHT/4 > fire_y + FIRE_WIDTH/4) && (pos_y + SONIC_HEIGHT/4 < fire_y + (FIRE_WIDTH*3)/4) )
            return 1;
        if( (pos_x - SONIC_WIDTH/3 > fire_x + FIRE_WIDTH/4) && (pos_x - SONIC_WIDTH/3 < fire_x + (FIRE_WIDTH*3)/4) && (pos_y - SONIC_HEIGHT/4 > fire_y + FIRE_WIDTH/4) && (pos_y - SONIC_HEIGHT/4 < fire_y + (FIRE_WIDTH*3)/4) )
            return 1;
    }

    return 0;
}
