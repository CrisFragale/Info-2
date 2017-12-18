#include "mi_allegro/mi_allegro.h"
#include "mi_aplicacion.h"
#include "mi_aplicacion_timer.h"
#include "mi_juego.h"
#include <time.h>


void draw(BITMAP *buffer, mi_app_t *app_struct);


int init_aplicacion(mi_app_t *app_struct)
{
    FONT *font;
    BITMAP *fondo, *sonic, *fuego;
    SAMPLE *wav;
    MIDI *midi;

	assert(app_struct);

    init_mi_struct(app_struct);

        // Cargo fuentes
    font = cargar_font("./fuentes/fuente_1.pcx");
    assert(font);

        // Cargo imagenes
    fondo = cargar_img("./imagenes/fondo.bmp");
    sonic = cargar_img("./imagenes/sonic.bmp");
    fuego = cargar_img("./imagenes/fire.bmp");
    assert(fondo);
    assert(sonic);
    assert(fuego);

        // Cargo audios
    wav = cargar_audio("./sonidos/untitled.wav");
    midi = cargar_midi("./sonidos/untitled.mid");
    assert(wav);
    assert(midi);

        // Pinto la pantalla de negro
    clear_to_color(screen, makecol(0,0,0)); // Pinta pantalla de negro


    app_struct->fuentes[FUENTE_COMIENZO] = font;
    app_struct->imagenes[IMG_FONDO] = fondo;
    app_struct->imagenes[IMG_SONIC] = sonic;
    app_struct->imagenes[IMG_FUEGO] = fuego;
    app_struct->midis[MIDI_MUSICA] = midi;
    app_struct->wavs[WAV_MUSICA] = wav;


    play_sample(wav, 255, 128, 1000, 1);
    //play_midi(midi, 1);


    return init_aplicacion_timer_ms(TICK_MS);
}

char logic_aplicacion(mi_app_t *app_struct)
{
    unsigned char *menu;

	assert(app_struct);

    menu = &(app_struct->menu);

	app_struct->time += FPS_MS;

    switch(*menu)
    {
        case MENU_PRINCIPAL:
                logic_menu_principal(app_struct);
            break;
        case MENU_JUEGO:
                logic_juego(app_struct);
            break;
        case MENU_PERDIO:
                logic_perdio(app_struct);
            break;
        case MENU_SALIR:
                return 1;
            break;
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
    unsigned char *menu;

	assert(app_struct);
	assert(buffer);

    menu = &(app_struct->menu);

    switch(*menu)
    {
        case MENU_PRINCIPAL:
                draw_menu_principal(buffer, app_struct);
            break;
        case MENU_JUEGO:
                draw_juego(buffer, app_struct);
            break;
        case MENU_PERDIO:
                draw_perdio(buffer, app_struct);
            break;
    }
}

void mi_allegro_exit(mi_app_t *app_struct)
{
    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.

	assert(app_struct);

    delete_mi_struct(app_struct);
}
