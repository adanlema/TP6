#ifndef RELOJ_H
#define RELOJ_H

/*==================[inclusions]=============================================*/
#include <stdbool.h>
#include <stdint.h>
/*==================[macros]=================================================*/
#define TIME_SIZE 6
#define TIME_POST 5

#define CONTROLAR_REBALSE(LIMITE_DEC, LIMITE_UNI, DECENA, UNIDAD, SIGUIENTE)                       \
    if (UNIDAD > LIMITE_UNI) {                                                                     \
        DECENA = DECENA + UNIDAD / LIMITE_UNI;                                                     \
        UNIDAD = 0 + ((UNIDAD / LIMITE_UNI) * UNIDAD - (LIMITE_UNI + 1));                          \
    }                                                                                              \
    if (DECENA > LIMITE_DEC) {                                                                     \
        DECENA = DECENA - (LIMITE_DEC + 1);                                                        \
        SIGUIENTE += 1;                                                                            \
    }

/*==================[typedef]================================================*/
typedef struct clock_s *  clock_t;
typedef struct alarma_s * alarma_pt;
typedef void (*evento_pt)(void);
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
clock_t ClockCreate(int tics_por_seg, evento_pt funcion);
void    ClockTick(clock_t reloj);
bool    ClockGetTime(clock_t reloj, uint8_t * hora, int size);
bool    ClockSetTime(clock_t reloj, const uint8_t * hora, int size);

bool    ClockSetAlarma(clock_t reloj, const uint8_t * hora, int size);
bool    ClockGetAlarma(clock_t reloj, uint8_t * hora, int size);
bool    ClockGetAlarmaActivada(clock_t reloj);
bool    ClockDesactivarAlarma(clock_t reloj);
bool    ClockPosponerAlarma(clock_t reloj, uint8_t time_post);
void    ClockCancelarAlarma(clock_t reloj);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif