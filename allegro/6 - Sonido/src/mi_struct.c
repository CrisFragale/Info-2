#include "mi_struct.h"


void init_mi_struct(mi_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
        app_struct->fuentes[i] = NULL;

    for(i=0; i<MAX_IMAGENES; i++)
        app_struct->imagenes[i] = NULL;

    for(i=0; i<MAX_WAVS; i++)
        app_struct->wavs[i] = NULL;

    for(i=0; i<MAX_MIDIS; i++)
        app_struct->midis[i] = NULL;

    app_struct->pos_x = 0;
    app_struct->pos_y = 0;
    app_struct->teclado_o_mouse = TECLADO;
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


    for(i=0; i<num_joysticks-2; i++)
        remove_joystick();
}
