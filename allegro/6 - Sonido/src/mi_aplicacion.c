#include "mi_allegro/mi_allegro.h"
#include "mi_aplicacion.h"
#include "mi_aplicacion_timer.h"


void draw(BITMAP *buffer, mi_app_t *app_struct);
void print_joystick_info(BITMAP *buffer);


int init_aplicacion(mi_app_t *app_struct)
{
    BITMAP *fondo = NULL, *oso = NULL;
    SAMPLE *wav = NULL;
    MIDI *midi = NULL;

	assert(app_struct);

        // Cargo imagenes
    fondo = cargar_img("./imagenes/fondo.bmp");
    oso = cargar_img("./imagenes/oso.bmp");
    assert(fondo);
    assert(oso);

        // Cargo audios
    wav = cargar_audio("./sonidos/untitled.wav");
    midi = cargar_midi("./sonidos/untitled.mid");
    assert(wav);
    assert(midi);

        // Pinto la pantalla de negro
    clear_to_color(screen, makecol(0,0,0));


    /* play_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop);
     * spl:     Puntero al audio
     * vol:     Volumen. De 0 (minimo) a 255 (maximo)
     * pan:     Panoramizacion. De 0 (izquierda) a 255 (derecha)
     * freq:    Frecuencia de reproduccion. 1000 = normal, 2000 = doble de velocidad, 500 = mitad de velocidad
     * loop:    Repeticion. 0 = no repite, 1 = repite.
     *
     * El audio WAV debe ser de 16 bits
     * Estos parametros se pueden modificar mientras se reproduce llamando a:
     * adjust_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop)
     */

    /* play_midi(const MIDI *mid, int loop);
     * mid:     Puntero al audio
     * loop:    Repeticion. 0 = no repite, 1 = repite.
     */


    app_struct->imagenes[IMG_FONDO] = fondo;
    app_struct->imagenes[IMG_OSO] = oso;
    app_struct->midis[MIDI_MUSICA] = midi;
    app_struct->wavs[WAV_MUSICA] = wav;


    play_sample(wav, 255, 128, 1000, 1);
    play_midi(midi, 1);


    return init_aplicacion_timer_ms(TICK_MS);
}

char logic_aplicacion(mi_app_t *app_struct)
{
    float desplazamiento = 0.5*FPS_MS;
    char *teclado_o_mouse = NULL;
    int *pos_x = NULL;
    int *pos_y = NULL;

	assert(app_struct);

    teclado_o_mouse = &(app_struct->teclado_o_mouse);
    pos_x = &(app_struct->pos_x);
    pos_y = &(app_struct->pos_y);

	assert(teclado_o_mouse);
	assert(pos_x);
	assert(pos_y);



    if(key[KEY_ESC]) return -1;


    poll_joystick();    // No hay interrupcion que maneje variables de joystick.
                        // Hay que llamar a esta funcion para actualizar valores
                        // antes de leerlos


    if(key[KEY_ENTER]) (*teclado_o_mouse) = TECLADO;
    if(mouse_b & 0x1) (*teclado_o_mouse) = MOUSE;
    if(joy[0].button[0].b) (*teclado_o_mouse) = JOYSTICK;


    if((*teclado_o_mouse) == TECLADO)
    {
        if(key[KEY_LEFT]) (*pos_x) -= desplazamiento;
        if(key[KEY_RIGHT]) (*pos_x) += desplazamiento;
        if(key[KEY_UP]) (*pos_y) -= desplazamiento;
        if(key[KEY_DOWN]) (*pos_y) += desplazamiento;
    }
    else if((*teclado_o_mouse) == MOUSE)
    {
        (*pos_x) = mouse_x;
        (*pos_y) = mouse_y;
    }
    else if((*teclado_o_mouse) == JOYSTICK)
    {
        if(joy[0].stick[0].axis[0].d1) (*pos_x) -= desplazamiento;
        if(joy[0].stick[0].axis[0].d2) (*pos_x) += desplazamiento;
        if(joy[0].stick[0].axis[1].d1) (*pos_y) -= desplazamiento;
        if(joy[0].stick[0].axis[1].d2) (*pos_y) += desplazamiento;
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
    int *pos_x = NULL;
    int *pos_y = NULL;

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


    poll_joystick();

    print_joystick_info(buffer);
}


void print_joystick_info(BITMAP *buffer)
{
    int i, j, k;
    int y = text_height(font);

	assert(buffer);

    textprintf_ex(buffer, font, 0, 0, makecol(0, 255, 0), makecol(0, 0, 0), "Joysticks conectados: %d", num_joysticks);
        // num_joysticks: variable que contiene cantidad de joysticks conectados. Soporta hasta 4 joysticks simultaneos.

    for(i=0; i<num_joysticks; i++)
    {
        for(j=0; j<joy[i].num_buttons; j++)
        {
            textprintf_right_ex(buffer, font, SCREEN_W-1, y, makecol(0, 255, 0), makecol(0, 0, 0), \
                                "Joystick %d button %d: \"%s\" %d", \
                                i, j, joy[i].button[j].name, joy[i].button[j].b);
            y += text_height(font);
        }
        for(j=0; j<joy[i].num_sticks; j++)
        {
            for(k=0; k<joy[i].stick[j].num_axis; k++)
            {
                textprintf_right_ex(buffer, font, SCREEN_W-1, y, makecol(0, 255, 0), makecol(0, 0, 0), \
                                    "Joystick %d stick %d: \"%s\" \"%s\" %d %d", \
                                    i, j, joy[i].stick[j].name, joy[i].stick[j].axis[k].name, \
                                    joy[i].stick[j].axis[k].d1, joy[i].stick[j].axis[k].d2);
                y += text_height(font);
            }
        }
    }
}

void mi_allegro_exit(mi_app_t *app_struct)
{
    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

	assert(app_struct);

    delete_mi_struct(app_struct);
}
