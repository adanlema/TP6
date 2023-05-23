#ifndef RELOJ_H
#define RELOJ_H

/*==================[inclusions]=============================================*/
#include <stdbool.h>
#include <stdint.h>
/*==================[macros]=================================================*/
#define TIME_SIZE 6
/*==================[typedef]================================================*/
typedef struct clock_s * clock_t;
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
clock_t ClockCreate(int tics_por_seg);
bool    ClockGetTime(clock_t reloj, uint8_t * hora, int size);
bool    ClockSetTime(clock_t reloj, const uint8_t * hora, int size);
void    ClockTick(clock_t reloj);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif