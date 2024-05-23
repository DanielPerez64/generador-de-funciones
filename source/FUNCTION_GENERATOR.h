/*
 * FUNCTION_GENERATOR.h
 *
 *  Created on: 18 may. 2024
 *      Author: Pablo Daniel Perez
 */

#ifndef FUNCTION_GENERATOR_H_
#define FUNCTION_GENERATOR_H_

#include "GENERADOR_DAC.h"
#include "GENERADOR_ADC.h"
#include "PIT.h"
#include "fsl_clock.h"
#include <stdint.h>

#define DELTA			16U
#define ZERO_VOLTS		0
#define FIX_POINT_SCALE	256U
#define MAX_COUNT		16U
#define HALF_PERIOD		2U

/*
 * This structure contains the configuration for the generator to set a function to work
 */
typedef struct {

	uint32_t 	period;	// the period that was selected from menu
	uint32_t	amplitude; // the amplitude that is configured from ADC
	uint8_t		function; //which function is selected
	uint8_t		index; //sample index

} signal_configuration;

/*
 * This enumeration contains the options for the signal
 */
typedef enum function_select{

	SQUARE,
	TRIANGLE,
	SINE

} funct_selection;

typedef enum period_options{

	_1KHZ 	= 1000u,
	_500HZ 	= 2000u,
	_250HZ	= 4000u,
	_100HZ 	= 10000u

} periods;

void generator_init(void);

/* RUN the signal  */
void run_signal(void);
void next_sample(void);

/* HANDLE the functions to be used */
void function_start(void);
/* reset the signal with new configuration */
void function_restart(void);

/* */
void set_config_amplitude(void);
void set_signal(uint8_t signal);
void set_config_period(uint32_t period);


/* function that generate a signal with the atributes of struct signal_configuration */
void sin_function(void);
void triangle_function(void);
void square_function(void);

/* sets and gets from signal configuration */

uint8_t get_function_status(void);


#endif /* FUNCTION_GENERATOR_H_ */
