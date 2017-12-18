#include "mi_imagen.h"


void draw_menu_principal(BITMAP *buffer, mi_app_t *app_struct)
{
    FONT *font;

	assert(buffer);
	assert(app_struct);

    font = app_struct->fuentes[FUENTE_COMIENZO];
	assert(font);

    textout_centre_ex(buffer, font, "PRESIONAR ENTER PARA EMPEZAR", SCREEN_W/2, SCREEN_H/2 - text_height(font)/2, makecol(0, 255, 0), -1);
    textout_centre_ex(buffer, font, "PRESIONAR ESCAPE PARA SALIR", SCREEN_W/2, SCREEN_H/2 + text_height(font)/2, makecol(0, 255, 0), -1);
}

void draw_juego(BITMAP *buffer, mi_app_t *app_struct)
{
    BITMAP *fondo;

	assert(buffer);
	assert(app_struct);

    fondo = app_struct->imagenes[IMG_FONDO];
	assert(fondo);

    stretch_sprite(buffer, fondo, 0, 0, SCREEN_W, SCREEN_H);

    if(key[KEY_LEFT])
    {
        draw_sonic(DRAW_SONIC_IZQ, buffer, app_struct);
    }
    else if(key[KEY_RIGHT])
    {
        draw_sonic(DRAW_SONIC_DER, buffer, app_struct);
    }
    else if(key[KEY_UP])
    {
        draw_sonic(DRAW_SONIC_DER, buffer, app_struct);
    }
    else if(key[KEY_DOWN])
    {
        draw_sonic(DRAW_SONIC_IZQ, buffer, app_struct);
    }
    else
    {
        draw_sonic(DRAW_SONIC_IDLE, buffer, app_struct);
    }

    draw_fuegos(buffer, app_struct);
}

void draw_perdio(BITMAP *buffer, mi_app_t *app_struct)
{
    FONT *font;

	assert(buffer);
	assert(app_struct);

    font = app_struct->fuentes[FUENTE_COMIENZO];
	assert(font);

    textout_centre_ex(buffer, font, "HAS PERDIDO", SCREEN_W/2, SCREEN_H/4 - text_height(font)/2, makecol(255, 0, 0), -1);
    textout_centre_ex(buffer, font, "PRESIONAR ENTER PARA EMPEZAR", SCREEN_W/2, SCREEN_H/2 - text_height(font)/2, makecol(0, 255, 0), -1);
    textout_centre_ex(buffer, font, "PRESIONAR ESCAPE PARA SALIR", SCREEN_W/2, SCREEN_H/2 + text_height(font)/2, makecol(0, 255, 0), -1);
}





/***************************************************************************/
/*							FUNCIONES AUXILIARES			   			   */
/***************************************************************************/


void draw_sonic(unsigned char sector, BITMAP *buffer, mi_app_t *app_struct)
{
    BITMAP *sonic;
    int pos_x;
    int pos_y;

	assert(buffer);
	assert(app_struct);

    sonic = app_struct->imagenes[IMG_SONIC];
	assert(sonic);
    pos_x = app_struct->pos_x;
    pos_y = app_struct->pos_y;

    switch(sector)
    {
        case DRAW_SONIC_IDLE:
                masked_blit(sonic, buffer, 0, 0, pos_x - SONIC_WIDTH/2, pos_y - SONIC_HEIGHT/2, SONIC_WIDTH, SONIC_HEIGHT);
            break;
        case DRAW_SONIC_IZQ:
                masked_blit(sonic, buffer, SONIC_WIDTH, 0, pos_x - SONIC_WIDTH/2, pos_y - SONIC_HEIGHT/2, SONIC_WIDTH, SONIC_HEIGHT);
            break;
        case DRAW_SONIC_DER:
                masked_blit(sonic, buffer, 2*SONIC_WIDTH, 0, pos_x - SONIC_WIDTH/2, pos_y - SONIC_HEIGHT/2, SONIC_WIDTH, SONIC_HEIGHT);
            break;
    }
}

void draw_fuegos(BITMAP *buffer, mi_app_t *app_struct)
{
    BITMAP *fuego;
    unsigned char fire_img;
    int fire_x;
    int fire_y;
    int i;

	assert(buffer);
	assert(app_struct);

    fuego = app_struct->imagenes[IMG_FUEGO];
	assert(fuego);
    fire_img = app_struct->fire_img;

    for(i=0; i<MAX_FIRE; i++)
    {
        fire_x = app_struct->fire_x[i];
        fire_y = app_struct->fire_y[i];

        switch(fire_img)
        {
            case DRAW_FIRE_1:
                    masked_blit(fuego, buffer, 0, 0, fire_x, fire_y, FIRE_WIDTH, FIRE_HEIGHT);
                break;
            case DRAW_FIRE_2:
                    masked_blit(fuego, buffer, FIRE_WIDTH, 0, fire_x, fire_y, FIRE_WIDTH, FIRE_HEIGHT);
                break;
            case DRAW_FIRE_3:
                    masked_blit(fuego, buffer, 2*FIRE_WIDTH, 0, fire_x, fire_y, FIRE_WIDTH, FIRE_HEIGHT);
                break;
            case DRAW_FIRE_4:
                    masked_blit(fuego, buffer, 3*FIRE_WIDTH, 0, fire_x, fire_y, FIRE_WIDTH, FIRE_HEIGHT);
                break;
        }
    }
}
