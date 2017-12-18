#include "mi_struct.h"
#include "mi_imagen.h"


void init_mi_struct(mi_app_t *app_struct)
{
    int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
        app_struct->fuentes[i] = NULL;

    for(i=0; i<MAX_IMAGENES; i++)
        app_struct->imagenes[i] = NULL;

    for(i=0; i<MAX_WAVS; i++)
        app_struct->wavs[i] = NULL;

    for(i=0; i<MAX_MIDIS; i++)
        app_struct->midis[i] = NULL;

	app_struct->time = 0;

    init_juego_vars(app_struct);
}

void init_juego_vars(mi_app_t *app_struct)
{
    int i;

	assert(app_struct);

    srand(time(NULL));  // Genero semilla

    for(i=0; i<MAX_FIRE; i++)
    {
        app_struct->fire_x[i] = rand()%(SCREEN_W-FIRE_WIDTH);
        app_struct->fire_y[i] = -(((i+1)*SCREEN_H)/MAX_FIRE);  //Para que se generen con una distancia entre los fuegos
    }

    app_struct->fire_img = IMG_FIRE_1;

    app_struct->pos_x = SCREEN_W/2;
    app_struct->pos_y = SCREEN_H;
    app_struct->menu = MENU_PRINCIPAL;
}

void delete_mi_struct(mi_app_t *app_struct)
{
    int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
    {
        if(app_struct->fuentes[i])
            destroy_font(app_struct->fuentes[i]);
    }

    for(i=0; i<MAX_IMAGENES; i++)
    {
        if(app_struct->imagenes[i])
            destroy_bitmap(app_struct->imagenes[i]);
    }

        // Al destruir los audios, se detiene su reproduccion
    for(i=0; i<MAX_WAVS; i++)
    {
        if(app_struct->wavs[i])
            destroy_sample(app_struct->wavs[i]);
    }

    for(i=0; i<MAX_MIDIS; i++)
    {
        if(app_struct->midis[i])
            destroy_midi(app_struct->midis[i]);
    }
}
