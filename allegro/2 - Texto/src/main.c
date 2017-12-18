#include "mi_allegro.h"
#include "mi_aplicacion.h"


int main()
{
    int return_value;
    mi_app_t mis_datos;


    if(mi_allegro_init() == 0)          // Inicializa allegro, instala teclado, mouse, timer y crea una ventana
    {
        mi_app_init(&mis_datos);

        mi_aplicacion(&mis_datos);      // Muestra algunos textos en pantalla

        rest(3000);                    // Espera 3 segundos

        mi_allegro_exit(&mis_datos);    // Se debe borrar imagenes y liberar memoria antes de cerrar allegro.


        return_value = 0;
    }
    else
    {
        return_value = -1;
    }

    return return_value;
} END_OF_MAIN()

