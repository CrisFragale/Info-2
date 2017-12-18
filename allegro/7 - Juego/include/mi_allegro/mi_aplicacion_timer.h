#ifndef MI_APLICACION_TIMER_H
#define MI_APLICACION_TIMER_H


#define TICK_MS	1


extern volatile char tick;  // Extern: Para utilizar variable definida en otro archivo fuente

int init_aplicacion_timer_ms(int ms);


#endif // MI_APLICACION_TIMER_H
