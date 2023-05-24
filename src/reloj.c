/*==================[inclusions]=============================================*/
#include <string.h>
#include "reloj.h"
/*==================[macros and definitions]=================================*/

#define DECENA_TIME 6
#define UNIDAD_TIME 10

#define UNIDAD_SEG  5
#define DECENA_SEG  4
#define UNIDAD_MIN  3
#define DECENA_MIN  2
#define UNIDAD_HOR  1
#define DECENA_HOR  0

struct alarma_s {
    uint8_t time[TIME_SIZE];
    bool    estado;
};

struct clock_s {
    uint8_t   time[TIME_SIZE];
    uint32_t  ticks;
    uint32_t  ticks_por_seg;
    bool      valida;
    alarma_pt alarma;
};

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
static void ClockIncrement_seg(clock_t reloj);
static void ClockIncrement_day(clock_t reloj);
static void ClockIncrement(clock_t reloj, uint8_t indice, uint8_t valor);
/*==================[internal data definition]===============================*/
static struct clock_s  self[1];
static struct alarma_s al_reloj[1];
/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
static void ClockIncrement_seg(clock_t reloj) {
    if (reloj->ticks == reloj->ticks_por_seg) {
        reloj->ticks = 0;
        reloj->time[UNIDAD_SEG]++;
    }
}

static void ClockIncrement_day(clock_t reloj) {
    if ((reloj->time[DECENA_HOR] == 2) && (reloj->time[UNIDAD_HOR] == 4)) {
        reloj->time[DECENA_HOR] = 0;
        reloj->time[UNIDAD_HOR] = 0;
    }
}

static void ClockIncrement(clock_t reloj, uint8_t indice, uint8_t valor) {
    if (reloj->time[indice] == valor) {
        reloj->time[indice] = 0;
        reloj->time[indice - 1]++;
    }
}

/*==================[external functions definition]==========================*/
clock_t ClockCreate(int tics_por_seg) {
    memset(self, 0, sizeof(self));
    memset(al_reloj, 0, sizeof(al_reloj));

    self->ticks_por_seg = tics_por_seg;
    self->alarma        = al_reloj;
    return self;
}
bool ClockGetTime(clock_t reloj, uint8_t * hora, int size) {
    memcpy(hora, reloj->time, size);
    return reloj->valida;
}

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size) {
    memcpy(reloj->time, hora, size);
    reloj->valida = true;
    return true;
}

void ClockTick(clock_t reloj) {
    reloj->ticks++;
    ClockIncrement_seg(reloj);
    ClockIncrement(reloj, UNIDAD_SEG, UNIDAD_TIME); // INCREMENTAR_DECENAS_SEG
    ClockIncrement(reloj, DECENA_SEG, DECENA_TIME); // INCREMENTAR_MINUTOS_UNIDAD
    ClockIncrement(reloj, UNIDAD_MIN, UNIDAD_TIME); // INCREMENTAR_MINUTOS_DECENAS
    ClockIncrement(reloj, DECENA_MIN, DECENA_TIME); // INCREMENTAR_HORAS_UNIDAD
    ClockIncrement(reloj, UNIDAD_HOR, UNIDAD_TIME); // INCREMENTAR_HORAS_DECENAS
    ClockIncrement_day(reloj);
}

bool ClockSetAlarma(clock_t reloj, const uint8_t * hora, int size) {
    memcpy(reloj->alarma->time, hora, size);
    reloj->alarma->estado = true;
    return true;
}
bool ClockGetAlarma(clock_t reloj, uint8_t * hora, int size) {
    if (reloj->alarma->estado) {
        memcpy(hora, reloj->alarma->time, size);
    }
    return (reloj->alarma->estado);
}

bool ClockDispararAlarma(clock_t reloj) {
    bool estado = false;
    if (reloj->alarma->time == reloj->time)
        estado = true;
    return estado;
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/