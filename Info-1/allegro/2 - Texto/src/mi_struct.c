#include "mi_struct.h"


void init_mi_struct(mi_app_t *app_struct)
{
    unsigned int i;

	assert(app_struct);

    for(i=0; i<MAX_FUENTES; i++)
        app_struct->fuentes[i] = NULL;
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
}
