#include "mi_allegro/mi_allegro.h"
#include "mi_aplicacion.h"
#include "mi_aplicacion_timer.h"


void draw(BITMAP *buffer, mi_app_t *app_struct);


int init_aplicacion(mi_app_t *app_struct)
{
    BITMAP *fondo = NULL;
    BITMAP *oso = NULL;

	assert(app_struct);

        // Cargo imagenes
    fondo = cargar_img("./imagenes/fondo.bmp");
    oso = cargar_img("./imagenes/oso.bmp");
    assert(fondo);
    assert(oso);

    app_struct->imagenes[IMG_FONDO] = fondo;
    app_struct->imagenes[IMG_OSO] = oso;

        // Pinto la pantalla de negro
    clear_to_color(screen, makecol(0,0,0)); // Pinta pantalla de negro

    return init_aplicacion_timer_ms(TICK_MS);
}

char logic_aplicacion(mi_app_t *app_struct)
{
    float desplazamiento = 0.2*FPS_MS;
    char *teclado_o_mouse = NULL;
    float *pos_x = NULL, *pos_y = NULL;

	assert(app_struct);

    pos_x = &(app_struct->pos_x);
    pos_y = &(app_struct->pos_y);
    teclado_o_mouse = &(app_struct->teclado_o_mouse);

	assert(pos_x);
	assert(pos_y);
	assert(teclado_o_mouse);


    if(key[KEY_ESC]) return -1;


    if(key[KEY_ENTER]) (*teclado_o_mouse) = 0;
    if(mouse_b & 0x1) (*teclado_o_mouse) = 1;

    if((*teclado_o_mouse) == 0)
    {
        if(key[KEY_LEFT]) (*pos_x) -= desplazamiento;
        if(key[KEY_RIGHT]) (*pos_x) += desplazamiento;
        if(key[KEY_UP]) (*pos_y) -= desplazamiento;
        if(key[KEY_DOWN]) (*pos_y) += desplazamiento;
    }
    else
    {
        (*pos_x) = mouse_x;
        (*pos_y) = mouse_y;
    }

	return 0;
}

void draw_aplicacion(mi_app_t *app_struct)
{
	assert(app_struct);
	
    draw_doble_buffer_sin_vsync(draw, app_struct);
}

void draw(BITMAP *buffer, mi_app_t *app_struct)
{
    BITMAP *fondo = NULL;
    BITMAP *oso = NULL;
    float *pos_x = NULL, *pos_y = NULL;

	assert(app_struct);
	assert(buffer);

    fondo = app_struct->imagenes[IMG_FONDO];
    oso = app_struct->imagenes[IMG_OSO];

    pos_x = &(app_struct->pos_x);
    pos_y = &(app_struct->pos_y);

    assert(fondo);
    assert(oso);
    assert(pos_x);
    assert(pos_y);

    stretch_sprite(buffer, fondo, 0, 0, SCREEN_W, SCREEN_H);
    draw_sprite(buffer, oso, (*pos_x) - oso->w/2, (*pos_y) - oso->h/2);
}


void mi_allegro_exit(mi_app_t *app_struct)
{
    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

	assert(app_struct);

    delete_mi_struct(app_struct);
}
