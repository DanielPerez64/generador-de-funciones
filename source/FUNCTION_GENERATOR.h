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
#include "PIT.h"
#include "fsl_clock.h"
#include <stdint.h>

#define DELTA			32U
#define ZERO_VOLTS		0

//uint8_t triangle_f[5] = {1/8,1/6,1/4,1/2,1};

typedef struct {
	uint32_t 	period;
	uint32_t	amplitude;
} signal_configuration;

void generator_init(void);

/* */
void set_config_amplitude(void);
void set_config_period(uint32_t period);


/* function that generate a signal with the atributes of struct signal_configuration */
void sin_function(void);
void triangle_function(void);
void square_function(void);


#endif /* FUNCTION_GENERATOR_H_ */
