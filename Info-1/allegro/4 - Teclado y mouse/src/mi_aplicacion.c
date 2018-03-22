#include "mi_aplicacion.h"
#include "mi_allegro/mi_allegro.h"


void logic(BITMAP *buffer, mi_app_t *app_struct);


void init_aplicacion(mi_app_t *app_struct)
{
    BITMAP *fondo;
    BITMAP *oso;

	assert(app_struct);

    fondo = cargar_img("./imagenes/fondo.bmp");
    oso = cargar_img("./imagenes/oso.bmp");
    assert(fondo);
    assert(oso);

    app_struct->imagenes[IMG_FONDO] = fondo;
    app_struct->imagenes[IMG_OSO] = oso;

    clear_to_color(screen, makecol(0,0,0));
}

void do_aplicacion(mi_app_t *app_struct)
{
	assert(app_struct);

    draw_doble_buffer_sin_vsync(logic, app_struct);
}

void logic(BITMAP *buffer, mi_app_t *app_struct)
{
	assert(buffer);
	assert(app_struct);

    BITMAP *fondo = app_struct->imagenes[IMG_FONDO];
    BITMAP *oso = app_struct->imagenes[IMG_OSO];

	assert(fondo);
	assert(oso);

    int *pos_x = &(app_struct->pos_x);
    int *pos_y = &(app_struct->pos_y);
    char *teclado_o_mouse = &(app_struct->teclado_o_mouse);

	assert(pos_x);
	assert(pos_y);
	assert(teclado_o_mouse);


    if(key[KEY_ENTER]) (*teclado_o_mouse) = TECLADO;   // Si apreta ENTER
    if(mouse_b & 0x1) (*teclado_o_mouse) = MOUSE;      // Si apreta click izquierdo del mouse

    if((*teclado_o_mouse) == TECLADO)
    {
        if(key[KEY_LEFT]) (*pos_x)--;
        if(key[KEY_RIGHT]) (*pos_x)++;
        if(key[KEY_UP]) (*pos_y)--;
        if(key[KEY_DOWN]) (*pos_y)++;
    }
    else
    {
        (*pos_x) = mouse_x;
        (*pos_y) = mouse_y;
    }

    stretch_sprite(buffer, fondo, 0, 0, SCREEN_W, SCREEN_H);
    draw_sprite(buffer, oso, (*pos_x) - oso->w/2, (*pos_y) - oso->h/2);
}

void mi_allegro_exit(mi_app_t *app_struct)
{
    delete_mi_struct(app_struct);
}
