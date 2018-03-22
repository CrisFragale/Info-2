#include "mi_struct.h"


void init_mi_struct(mi_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
        app_struct->fuentes[i] = NULL;

    for(i=0; i<MAX_IMAGENES; i++)
        app_struct->imagenes[i] = NULL;

    app_struct->pos_x = 0;
    app_struct->pos_y = 0;
    app_struct->teclado_o_mouse = TECLADO;
}

void delete_mi_struct(mi_app_t *app_struct)
{
    unsigned int i;

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
}
