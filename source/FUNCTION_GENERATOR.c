/*
 * FUNCTION_GENERATOR.c
 *
 *  Created on: 18 may. 2024
 *      Author: Pablo Daniel Perez
 */

#include "FUNCTION_GENERATOR.h"

//********************************************************************************

// signal configuration struct
static volatile signal_configuration signal_config = {0,0,0};
static volatile uint8_t index = 0; // index for each sample of the array
static volatile bool square_sig_st = true; // variable that will decide what will be happening with the square wave
static uint32_t clock_pit;	// this static variable works for set the value for the clock

// table array for the functions
const uint32_t triangle_array[16] = {0,32,64,96,128,160,192,224,256,224,192,160,128,96,64,32};
const uint32_t sine_array[16] 	  = {128,176,218,246,256,246,218,176,128,79,37,9,0,9,37,79};

//********************************************************************************

void generator_init(void){


	clock_pit = CLOCK_GetFreq(kCLOCK_BusClk);
	DAC_init();
	ADC_init();
	PIT_init(clock_pit);
}

void run_signal(void){



	if(signal_config.function == SINE){
		sin_function();
	}
	else if(signal_config.function == TRIANGLE){
		triangle_function();
	}
	else if(signal_config.function == SQUARE){
		square_function();
	}
}

//********************************************************************************

void function_start(void){
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}

void set_config_amplitude(void){
	signal_config.amplitude = get_amp(); //get form ADC the value of potentiometer
}

void set_signal(uint8_t signal){
	signal_config.function = signal;
}

void set_config_period(uint32_t period){

	signal_config.period = period/DELTA;
	set_period(signal_config.period, clock_pit);

}

void sin_function(void){

	if(PIT_get_irq_status(kPIT_Chnl_0)){
		index = 0;
		PIT_clear_irq_status(kPIT_Chnl_0);
	}

	analog_Write_DAC( (signal_config.amplitude * sine_array[index])/FIX_POINT_SCALE );
	index++;

}

void triangle_function(void){

	if(PIT_get_irq_status(kPIT_Chnl_0)){
		index = 0;
		PIT_clear_irq_status(kPIT_Chnl_0);
	}

	analog_Write_DAC( (signal_config.amplitude * triangle_array[index])/FIX_POINT_SCALE );
	index++;
}

void square_function(void){

	if( square_sig_st ){ // if its true then...
		analog_Write_DAC(signal_config.amplitude);
		square_sig_st = false;
	}
	else{
		analog_Write_DAC(ZERO_VOLTS);
		square_sig_st = true;
	}

}

/* get status functions */

uint8_t get_function_status(void){

	return signal_config.function;
}
