#include "mi_allegro_creacion.h"
#include "mi_allegro_draw.h"


    // Variables globales
BITMAP *buff[3] = {NULL, NULL, NULL};   // Bitmap del buffer 1, 2 y 3
unsigned char current_buff = 0;         // Numero del buffer actual (para triple buffer)
unsigned char draw_method = 0;          // Metodo de dibujado (simple, doble o triple buffer con o sin VSync)


enum
{
	METHOD_BUFFER_SIMPLE,
	METHOD_BUFFER_DOBLE_SIN_VSYNC,
	METHOD_BUFFER_DOBLE_CON_VSYNC,
	METHOD_BUFFER_TRIPLE
};


void draw_simple_buffer(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct)
{
    if(draw_method != METHOD_BUFFER_SIMPLE)
    {
        draw_method = METHOD_BUFFER_SIMPLE;

        destroy_all_draw_buffers();
        // No requiere buffers de dibujo, dibuja directamente en pantalla
    }

	assert(logic);
	assert(app_struct);

    logic(screen, app_struct);  // Hace logica directamente en pantalla
}

void draw_doble_buffer_sin_vsync(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct)
{
    if(draw_method != METHOD_BUFFER_DOBLE_SIN_VSYNC)
    {
        draw_method = METHOD_BUFFER_DOBLE_SIN_VSYNC;

        destroy_all_draw_buffers();
            // Crea 1 buffer de dibujo. El otro buffer es la pantalla misma
        buff[0] = Crear_buffer(SCREEN_W, SCREEN_H);
        assert(buff[0]);
            // Pinta buffer de "transparente" (magenta)
        clear_to_color(buff[0], makecol(255,0,255));
    }

	assert(logic);
	assert(app_struct);

    logic(buff[0], app_struct);                     // Hace logica en el buffer

    draw_sprite(screen, buff[0], 0, 0); // Y luego muestra en pantalla
}

void draw_doble_buffer_con_vsync(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct)
{
    if(draw_method != METHOD_BUFFER_DOBLE_CON_VSYNC)
    {
        draw_method = METHOD_BUFFER_DOBLE_CON_VSYNC;

        destroy_all_draw_buffers();
            // Crea 2 buffers de dibujo
        buff[0] = Crear_video_buffer(SCREEN_W, SCREEN_H);
        buff[1] = Crear_video_buffer(SCREEN_W, SCREEN_H);
        assert(buff[0]);
        assert(buff[1]);
            // Pinta buffers de "transparente"
        clear_to_color(buff[0], makecol(255,0,255));
        clear_to_color(buff[1], makecol(255,0,255));

        current_buff = 0;
    }

	assert(logic);
	assert(app_struct);

    logic(buff[current_buff], app_struct);              // Hace logica en el buffer

    show_video_bitmap(buff[current_buff]);  // Luego muestra en pantalla (esperando sincronizacion vertical)

    current_buff = !current_buff;           // Y cambia de buffer entre 1 y 0
}

void draw_triple_buffer(void (*logic)(BITMAP *, mi_app_t *), mi_app_t *app_struct)
{
    static unsigned char prev_buff;             // Siguiente buffer que espera a mostrarse
                                                // (por lo tanto, mientras, no se puede usar este buffer)

    if(draw_method != METHOD_BUFFER_TRIPLE)
    {
        draw_method = METHOD_BUFFER_TRIPLE;

            // Si no esta habilitado el Triple buffer, lo habilito
        if(!(gfx_capabilities & GFX_CAN_TRIPLE_BUFFER))
        {
            enable_triple_buffer();
            if(!(gfx_capabilities & GFX_CAN_TRIPLE_BUFFER))
            {
                // Si no pudo habilitar triple buffer, prueba con doble buffer sin vsync
                draw_doble_buffer_sin_vsync(logic, app_struct);
                return;
            }
        }

        destroy_all_draw_buffers();
            // Crea 3 buffers de dibujo
        buff[0] = Crear_video_buffer(SCREEN_W, SCREEN_H);
        buff[1] = Crear_video_buffer(SCREEN_W, SCREEN_H);
        buff[2] = Crear_video_buffer(SCREEN_W, SCREEN_H);
        assert(buff[0]);
        assert(buff[1]);
        assert(buff[2]);
            // Pinta buffers de "transparente"
        clear_to_color(buff[0], makecol(255,0,255));
        clear_to_color(buff[1], makecol(255,0,255));
        clear_to_color(buff[2], makecol(255,0,255));

        current_buff = 0;
    }

	assert(logic);
	assert(app_struct);

    logic(buff[current_buff], app_struct);                  // Hace logica en el buffer

    while(poll_scroll())                        // Mientras todavia se esta esperando el refresco de la pantalla...
    {
        current_buff = 3-current_buff-prev_buff;    // ... Voy cambiando entre los otros dos buffers no usados
        logic(buff[current_buff], app_struct);
    }
    request_video_bitmap(buff[current_buff]);   // Manda el ultimo buffer completado a la
                                                // pantalla en el proximo refreso (retorna
                                                // inmediatamente sin esperar)

    prev_buff = current_buff;
    current_buff = (current_buff+1) % 3;
}


void destroy_all_draw_buffers()
{
    if(buff[0]) destroy_bitmap(buff[0]);
    if(buff[1]) destroy_bitmap(buff[1]);
    if(buff[2]) destroy_bitmap(buff[2]);
}
