#include "mi_allegro/mi_allegro.h"
#include "mi_aplicacion.h"


void logica(BITMAP *buffer, mi_app_t *app_struct);


void init_aplicacion(mi_app_t *app_struct)
{
    BITMAP *fondo = NULL;
    BITMAP *oso = NULL;

	assert(app_struct);

        // Carga imagenes
    fondo = cargar_img("./imagenes/fondo.bmp");
    oso = cargar_img("./imagenes/oso.bmp");
    assert(fondo);
    assert(oso);

    app_struct->imagenes[IMG_FONDO] = fondo;
    app_struct->imagenes[IMG_OSO] = oso;

    clear_to_color(screen, makecol(255,0,255));  // Pinta todo el bufer de magenta.
                                                 // El magenta (255, 0, 255), se usa como color transparente.
}

void do_aplicacion(mi_app_t *app_struct)
{
	assert(app_struct);

    draw_simple_buffer(logica, app_struct);
}

void logica(BITMAP *buffer, mi_app_t *app_struct)
{
    BITMAP *fondo = NULL;
    BITMAP *oso = NULL;

	assert(buffer);
	assert(app_struct);

    fondo = app_struct->imagenes[IMG_FONDO];
    oso = app_struct->imagenes[IMG_OSO];

	assert(fondo);
	assert(oso);

    stretch_sprite(buffer, fondo, 0, 0, SCREEN_W, SCREEN_H);
        /* Copia toda una imagen, la escala y la dibuja sobre otra imagen
         * buffer:              bitmap de destino
         * fondo:               bitmap fuente
         * 0, 0:                Posicion del bitmap destino donde se copia el bitmap fuente
         * SCREEN_W, SCREEN_H:  Escalamiento del bitmap fuente
         */

    draw_sprite(buffer, oso, SCREEN_W/2 - oso->w/2, SCREEN_H/2 - oso->h/2);
        /* Copia toda una imagen sobre otra imagen
         * buffer:                                          bitmap de destino
         * oso:                                             bitmap fuente
         * SCREEN_W/2 - coso->w/2, SCREEN_H/2 - coso->h/2:  Posicion del bitmap destino donde se copia el bitmap fuente
         */


    /* Otras funciones de dibujo:
     *  blit():         Copia un sector de una imagen sobre otra imagen
     *  stretch_blit(): Copia un sector de una imagen, la escala y la dibuja sobre otra imagen
     */
}


void mi_allegro_exit(mi_app_t *app_struct)
{
	assert(app_struct);

    delete_mi_struct(app_struct);
}
