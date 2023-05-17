/*
Pruebas
‣ Al inicializar el reloj está en 00:00 y con hora invalida.
‣ Al ajustar la hora el reloj queda en hora y es válida.
‣ Probar horas invalidas y verificar que las rechaza.
‣ Después de n ciclos de reloj la hora avanza un segundo,
diez segundos, un minutos, diez minutos, una hora, diez
horas y un día completo.
‣ Fijar la hora de la alarma y consultarla.
‣ Fijar la alarma y avanzar el reloj para que suene.
‣ Fijar la alarma, deshabilitarla y avanzar el reloj para no
suene.
‣ Hacer sonar la alarma y posponerla.
‣ Hacer sonar la alarma y cancelarla hasta el otro dia..
*/


/*==================[inclusions]=============================================*/
#include "unity.h"
#include "reloj.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

//‣ Al inicializar el reloj está en 00:00 y con hora invalida.
void test_start_up(void){
    static const uint8_t ESPERADO[]={0,0,0,0,0,0};
    uint8_t hora[6] = {0xFF};
    clock_t reloj = ClockCreate(5);

    TEST_ASSERT_FALSE(ClockGetTime(reloj,hora,6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,hora,6);
}

//‣ Al ajustar la hora el reloj queda en hora y es válida.
void test_ajustar_hora (void){
    static const uint8_t ESPERADO[]={1,2,3,4,0,0};
    uint8_t hora[6] = {0xFF};
    clock_t reloj = ClockCreate(5);
    
    TEST_ASSERT_TRUE(ClockSetTime(reloj, ESPERADO, 4));
    TEST_ASSERT_TRUE(ClockGetTime(reloj,hora,6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO,hora,6);
}

















/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/