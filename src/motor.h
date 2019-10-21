/*
 * main.h
 *
 *  Created on: 2 jul. 2019
 *      Author: ezequiel
 */

#ifndef PDM_MOVER_COMUNICAR_INC_MOTOR_H_
#define PDM_MOVER_COMUNICAR_INC_MOTOR_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include "sapi.h"
#include <stdint.h>
#include <stddef.h>

/*=====[Definitions of public data types]====================================*/

bool_t valor;
int parametro;				// valor configurabled el puerto //LED1(X->),LED2(X<-),LED3(Y->),LEDB(Y<-),GPIO0(X max),GPIO1(X min),GPIO2(Y max),GPIO6(Y min)
int configuracion;			// variable de estado del puerto (entrada/salida) // GPIO_OUTPUT (salida),GPIO_INPUT (entrada)
int sensor;					// variable numero de senso (1,2,3,4)

/*=====[Prototypes (declarations) of public functions]=======================*/

void configlimitMotor(gpioMap_t vector, gpioInit_t estado);	// Configuracion gpio vector/estado
void bottonPressed_avance (gpioMap_t);  	// Muevo motor
void bottonReleased_freno (gpioMap_t);		// Freno motor
int limite(void); 							// Limites



#endif /* PDM_MOVER_COMUNICAR_INC_MOTOR_H_ */
