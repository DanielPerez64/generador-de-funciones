/*
 * GENERADOR_DAC.h
 *
 *  Created on: 18 may. 2024
 *      Author: dany-
 *
 *  Este driver configura el DAC0 para facilitar su implementacion.
 *
 *  Funciones:
 *
 *  	DAC_begin: inicializa las configuraciones del DAC0 y sus registros
 *
 *  	analog_Write_DAC; recibe un entero sin signo de 32 bits el cual sera escrito en el pin/header
 *  	11: DAC0_OUT
 *
 *
 */

#ifndef GENERADOR_DAC_H_
#define GENERADOR_DAC_H_

#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_dac.h"

#define DAC_BASEADDR DAC0

/* inicializa y configura el DAC0 */
void DAC_begin(void);

void analog_Write_DAC();



#endif /* GENERADOR_DAC_H_ */
