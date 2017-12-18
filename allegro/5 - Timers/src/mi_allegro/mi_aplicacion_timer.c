#include "mi_allegro.h"
#include "mi_aplicacion_timer.h"


volatile char tick = 0; /* volatile: previene optimizaciones, que el
                         * compilador realiza, tales como el NO actualizar
                         * el valor de una variable si NO es notificado
                         * que su valor ha sido modificado. Por lo que
                         * puede producir errores si su valor es modificado
                         * externamente (ej. en una interrupcion).
                         */

void ticker(void)
{
    tick+=TICK_MS;
}END_OF_FUNCTION(ticker) // Bloquea codigo. NO termina con ; (punto y coma)

/* END_OF_FUNCTION, LOCK_VARIABLE y LOCK_FUNCTION son necesarios en
 * Sistemas Operativos que son "non-reentrancy" (Que no pueden
 * reinterrumpir ya estando en una interrupcion). Bloquear codigo y
 * datos imposibilita la virtualizacion de los mismos durante una
 * interrupcion y evitar problemas.
 *
 * La memoria virtual es cuando una parte del disco duro (archivo
 * de paginacion en windows, swap en linux) es utilizada como memoria
 * RAM (para guardar variables por ejemplo)
 */

int init_aplicacion_timer_ms(int ms)
{
    LOCK_VARIABLE(tick);
    LOCK_FUNCTION(ticker);

    return install_int_ex(ticker, MSEC_TO_TIMER(ms));// inicia timer para interrumpir
                                                     // cada 'ms' milisegundos
}
