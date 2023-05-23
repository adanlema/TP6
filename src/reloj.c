/*==================[inclusions]=============================================*/
#include <string.h>
#include "reloj.h"
/*==================[macros and definitions]=================================*/

struct clock_s {
    uint8_t  hora_actual[TIME_SIZE];
    uint32_t ticks;
    uint32_t ticks_por_seg;
    bool     valida;
};
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
static struct clock_s self[1];
/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
clock_t ClockCreate(int tics_por_seg) {
    memset(self, 0, sizeof(self));
    self->ticks_por_seg = tics_por_seg;
    return self;
}
bool ClockGetTime(clock_t reloj, uint8_t * hora, int size) {
    memcpy(hora, reloj->hora_actual, size);
    return reloj->valida;
}

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size) {
    memcpy(reloj->hora_actual, hora, size);
    reloj->valida = true;
    return true;
}

//  H0  H1  M2  M3  S4  S5
void ClockTick(clock_t reloj) {
    reloj->ticks++;
    // INCREMENTAR_SEGUNDOS
    if (reloj->ticks == reloj->ticks_por_seg) {
        reloj->ticks = 0;
        reloj->hora_actual[5]++;
    }
    // INCREMENTAR_DECENAS_SEG
    if (reloj->hora_actual[5] == 10) {
        reloj->hora_actual[5] = 0;
        reloj->hora_actual[5 - 1]++;
    }
    // INCREMENTAR_MINUTOS_UNIDAD
    if (reloj->hora_actual[4] == 6) {
        reloj->hora_actual[4] = 0;
        reloj->hora_actual[4 - 1]++;
    }
    // INCREMENTAR_MINUTOS_DECENAS
    if (reloj->hora_actual[3] == 10) {
        reloj->hora_actual[3] = 0;
        reloj->hora_actual[3 - 1]++;
    }
    // INCREMENTAR_HORAS_UNIDAD
    if (reloj->hora_actual[2] == 6) {
        reloj->hora_actual[2] = 0;
        reloj->hora_actual[2 - 1]++;
    }
    // INCREMENTAR_HORAS_DECENAS
    if (reloj->hora_actual[1] == 10) {
        reloj->hora_actual[1] = 0;
        reloj->hora_actual[1 - 1]++;
    }
    // INCREMENTAR_DIAS
    if ((reloj->hora_actual[0] == 2) && (reloj->hora_actual[1] == 4)) {
        reloj->hora_actual[0] = 0;
        reloj->hora_actual[1] = 0;
    }
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/