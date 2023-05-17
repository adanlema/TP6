/*==================[inclusions]=============================================*/
#include <string.h>
#include "reloj.h"
/*==================[macros and definitions]=================================*/
struct clock_s{
    /*
    union{
        uint8_t hora[6];
        struct{
            uint8_t hora[2];
            uint8_t min[2];
            uint8_t seg[2];
        }actual;
    }
    */
   uint8_t hora_actual[6];
   bool valida;
};
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
clock_t ClockCreate(int tics_por_seg){
    static struct clock_s self[1];
    memset(self,0,sizeof(self));
    return self;
}
bool ClockGetTime(clock_t reloj, uint8_t * hora, int size){
    memcpy(hora,reloj->hora_actual,size);
    return reloj->valida;
}

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size){
    memcpy(reloj->hora_actual,hora,size);
    reloj->valida = true;
    return true;
}



/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/