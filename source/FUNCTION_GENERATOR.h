/*
 * FUNCTION_GENERATOR.h
 *
 *  Created on: 18 may. 2024
 *      Author: dany-
 */

#ifndef FUNCTION_GENERATOR_H_
#define FUNCTION_GENERATOR_H_

#include "GENERADOR_DAC.h"
#include "GENERADOR_ADC.h"
#include <stdint.h>

typedef struct {
	uint32_t 	frequency;
	uint8_t		amplitude;
} signal_configuration;

void ADC_DAC_init(void);

/* writes on struct signal_configuration the value of the desired frequency */
void set_freq(uint32_t frequency);

/* function that generate a signal with the atributes of struct signal_configuration */
void sin_function(void);
void triangle_function(void);
void square_function(void);


#endif /* FUNCTION_GENERATOR_H_ */
