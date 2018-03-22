#include "mi_allegro/mi_allegro.h"
#include "mi_aplicacion.h"


int main(void)
{
    mi_app_t mis_datos;

    init_mi_struct(&mis_datos);

    mi_allegro_init_windowed(800, 600);  // Inicializa allegro, instala teclado, mouse, timer y crea una ventana

    init_aplicacion(&mis_datos);  // Inicializa juego

    do_aplicacion(&mis_datos);

    rest(5000);

    mi_allegro_exit(&mis_datos);  // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.


    return 0;
} END_OF_MAIN()

