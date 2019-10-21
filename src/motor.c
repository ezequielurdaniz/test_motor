/*
 * motor.c
 *
 *  Created on: 2 jul. 2019
 *      Author: ezequiel
 */
/*=====[Inclusions of public function dependencies]==========================*/

#include "sapi.h"
#include "motor.h"

static gpioMap_t vector; //LED1(X->),LED2(X<-),LED3(Y->),LEDB(Y<-),GPIO0(X max),GPIO1(X min),GPIO2(Y max),GPIO6(Y min)
static gpioInit_t estado; //GPIO_OUTPUT (salida),GPIO_INPUT (entrada)

							// TEC1 - MOTOR X-> // TEC2 - MOTOR X<- // TEC3 - MOTOR Y-> // TEC4 - MOTOR Y<-


/*=====[Declarations of public functions]=======================*/


void configlimitMotor(gpioMap_t vector ,gpioInit_t estado){		// Configuracion del motor
	
	parametro=vector;
	configuracion=estado;
	
	gpioConfig(parametro, configuracion); //configuro los limities y direccion del motor. 

	}

void bottonPressed_avance (	gpioMap_t tecla ){  // Muevo motor

	switch(tecla){
			case TEC1:
				gpioWrite(LED1, ON); //MOTOR X->
				break;
			case TEC2:
				gpioWrite(LED2, ON); //MOTOR X<-
				break;
			case TEC3:
				gpioWrite(LED3, ON); //MOTOR Y->
				break;
			case TEC4:
				gpioWrite(LEDB, ON); //MOTOR Y<-
				break;
			default:
				//Sin accion.
				break;
			}
	}


void bottonReleased_freno (gpioMap_t tecla){				//Freno motor

	switch(tecla){
			case TEC1:
				gpioWrite(LED1, OFF); 						//MOTOR X->
				break;
			case TEC2:
				gpioWrite(LED2, OFF); 						//MOTOR X<-
				break;
			case TEC3:
				gpioWrite(LED3, OFF); 						//MOTOR Y->
				break;
			case TEC4:
				gpioWrite(LEDB, OFF); 						//MOTOR Y<-
				break;
			default:										//Sin accion.
				break;
			}
	}

int limite ( void ) {										//Limite
	for(int i=0;i<=3;i++){
		sensor=0;											//Inicializo sensor
	switch(i){
			case 0:
				valor = !gpioRead(GPIO0);
				if(valor == 1){
					sensor=1;								//Limite X_max
				}
				break;
			case 1:
				valor = !gpioRead(GPIO1);
				if(valor == 1){
					sensor=2;								//Limite X_min
				}
				break;
			case 2:
				valor = !gpioRead(GPIO2);
				if(valor == 1){
					sensor=3;								//Limite Y_max
				}
				break;
			case 3:
				valor = !gpioRead(GPIO6);
				if(valor == 1){
					sensor=4;								//Limite Y_min
				}
				break;
			default:
				sensor=0;
				break;
			}
	if(sensor != 0){
		break;                                            //Corte for
		}
	}
	return sensor;
	}
