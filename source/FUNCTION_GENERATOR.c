/*
 * FUNCTION_GENERATOR.c
 *
 *  Created on: 18 may. 2024
 *      Author: dany-
 */

#include "FUNCTION_GENERATOR.h"

// signal configuration struct
static volatile signal_configuration signal_config; // set but no used

// table array for the functions
const uint32_t triangle_array[];
const uint32_t sine_array[];

void generator_init(void){

	uint32_t clock_pit;
	clock_pit = CLOCK_GetFreq(kCLOCK_BusClk);
	DAC_init();
	ADC_init();
	PIT_init(clock_pit);
}

void set_config_amplitude(void){
	signal_config.amplitude = get_amp(); //get form ADC the value of potentiometer
}

void set_config_period(uint32_t period){
	signal_config.period = period;
}

void sin_function(void){

}

void triangle_function(void){

//	if( signal_config.frequency/8 == get_count_value()){
//
//	}

}

void square_function(void){

	if( signal_config.period/DELTA < get_count_value(kPIT_Chnl_0) ){
		analog_Write_DAC(signal_config.amplitude);
	}
	else{
		analog_Write_DAC(ZERO_VOLTS);
	}

}
