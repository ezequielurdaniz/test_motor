
// Testing del software motor.c del proyecto final de carrera de especialización. 
// Urdaniz, Fabian Ezequiel  urdanizezequiel@gmail.com
// Testing de Software en Sistemas Embebidos.


//-------------------------------- Include --------------------------------------
// Archivo header para la compilación del testing. Incluido cMock para la libreria SAPI.h 

#include "unity.h"
#include "motor.h"
#include "mock_sapi.h"

//-------------------------------- Configuración----------------------------------

void setUp(void){
	//No se requiere el uso esta función.
}

void tearDown (void){
	//No se requiere el uso esta función.
}

// ----------------------------- Testing ------------------------------------------
// Testeo la función configuración del motor para avance en una dirección de la tecla TEC1.
void test_configuracion_motor(void){
	gpioConfig_ExpectAndReturn(LED1,GPIO_OUTPUT,1);  // Configuro el puerto GPIO y retorno un 1 (true).
	gpioWrite_IgnoreAndReturn(1); 					 // Ignoro write en el puerto GPIO  y retorno 1 (true).
	configlimitMotor(LED1,GPIO_OUTPUT);			     // Testeo de la funcion configlimitMotor con los parametros LED1,GPIO_OUTPUT.
	bottonPressed_avance(TEC1);				         // Si la configuracion se hizo correctamente se verifica el avance con el parametro TEC1.
}

// Testeo la funcion configuración del los sensores limites para detectar el limite de avance del sensor 1.
void test_configuracion_limited(void){
	gpioConfig_ExpectAndReturn(GPIO0,GPIO_INPUT,1); // Configuro el puerto GPIO y retorno un 1 (true).
	configlimitMotor(GPIO0,GPIO_INPUT);             // Testeo de la funcion configlimitMotor con los parametros GPIO0,GPIO_INPUT.
	gpioRead_ExpectAndReturn(GPIO0,0);				// Read el puerto GPIO y retorno un 0 (false).
	TEST_ASSERT_EQUAL (1,limite());					// Testeo que la funcion limite me retorne el valor del sensor 1.
}

// Testeo el avance para la dirección de la tecla TEC1 en el eje x.
void test_bottonPressed_avance_en_x(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true).
	gpioWrite_ExpectAndReturn(LED1, ON, 1);			// Write en el puerto GPIO el valor de ON de LED1 y retorno 1 (true).
	configlimitMotor(LED1,GPIO_OUTPUT);				// En configlimitMotor seteo los parametros LED1,GPIO_OUTPUT.
	bottonPressed_avance(TEC1);						// Se verifica el avance con el parametro TEC1.
}

// Testeo el avance para la dirección de la tecla TEC3 en el eje y.
void test_bottonPressed_avance_en_y(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1(true).
	gpioWrite_ExpectAndReturn(LED3, ON, 1);			// Write en el puerto GPIO el valor de ON de LED3 y retorno 1 (true).
	configlimitMotor(LED3,GPIO_OUTPUT);				// En configlimitMotor seteo los parametros LED3,GPIO_OUTPUT.
	bottonPressed_avance(TEC3);						// Se verifica el avance con el parametro TEC3.
}

// Testeo el freno para la dirección de la tecla TEC1 en el eje x.
void test_bottonReleased_freno_en_x(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true).
	gpioWrite_ExpectAndReturn(LED1, OFF, 0);		// Write en el puerto GPIO el valor de OFF de LED1 y retorno 0 (false).
	configlimitMotor(LED1,GPIO_OUTPUT);				// En configlimitMotor seteo los parametros LED1,GPIO_OUTPUT.
	bottonReleased_freno (TEC1);					// Se verifica el freno de avance en x del parametro TEC1.
}

// Testeo el freno para la dirección de la tecla TEC3 en el eje y.
void test_bottonReleased_freno_en_y(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true).
	gpioWrite_ExpectAndReturn(LED3, OFF, 0);		// Write en el puerto GPIO el valor de OFF de LED3 y retorno 0 (false).
	configlimitMotor(LED3,GPIO_OUTPUT);				// En configlimitMotor seteo los parametros LED3,GPIO_OUTPUT.
	bottonReleased_freno (TEC3);					// Se verifica el freno de avance en y del parametro TEC3.
}


// Testeo del sensor de limite superior de dirección en el eje x.
void test_limite_superior_x(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true).
	gpioRead_ExpectAndReturn(GPIO0,0);				// Read el puerto GPIO y retorno un 0 (false).
	TEST_ASSERT_EQUAL (1,limite());					// Testeo que la funcion limite me retorne el valor del sensor 1.
}

// Testeo del sensor de limite inferior de dirección en el eje x.
void test_limite_inferior_x(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true)
	gpioRead_ExpectAndReturn(GPIO0,1);				// Read el puerto GPIO y retorno un 1 (true).
	gpioRead_ExpectAndReturn(GPIO1,0);				// Read el puerto GPIO y retorno un 0 (false).
	TEST_ASSERT_EQUAL (2,limite());					// Testeo que la funcion limite me retorne el valor del sensor 2.
}

// Testeo del sensor de limite superior de dirección en el eje y.
void test_limite_3(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true)
	gpioRead_ExpectAndReturn(GPIO0,1);				// Read el puerto GPIO y retorno un 1 (true).
	gpioRead_ExpectAndReturn(GPIO1,1);				// Read el puerto GPIO y retorno un 1 (true).
	gpioRead_ExpectAndReturn(GPIO2,0);				// Read el puerto GPIO y retorno un 0 (false).
	TEST_ASSERT_EQUAL (3,limite());					// Testeo que la funcion limite me retorne el valor del sensor 3.
}

// Testeo de no se alcanzo ningun limite de dirección.
void test_limite_4(void){
	gpioConfig_IgnoreAndReturn(1);					// Ignoro configuración del puerto GPIO  y retorno 1 (true).
	gpioRead_IgnoreAndReturn(1);					// Ignoro read del puerto GPIO  y retorno 1 (true).
	TEST_ASSERT_EQUAL (0,limite());					// Testeo que la funcion limite me retorne el valor de ningun sensor (0).
}


