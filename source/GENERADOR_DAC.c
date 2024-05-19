/*
 * GENERADOR_DAC.c
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
 */
#include "GENERADOR_DAC.h"

void DAC_begin(void){

	/* configura el DAC */
	dac_config_t dacConfigStruct;

	DAC_GetDefaultConfig(&dacConfigStruct);
	DAC_Init(DAC_BASEADDR, &dacConfigStruct);
	DAC_Enable(DAC_BASEADDR, true);             /* Enable output. */
	DAC_SetBufferReadPointer(DAC_BASEADDR, 0U); /* Make sure the read pointer to the start. */

}

void analog_Write_DAC(uint32_t dacValue){

	DAC_SetBufferValue(DAC_BASEADDR, 0U, dacValue); //esta funcion de fsl_dac.h escribe el valor en el pin DAC0_OUT

}
