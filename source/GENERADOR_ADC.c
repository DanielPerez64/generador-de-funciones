/*
 * GENERADOR_ADC.c
 *
 *  Created on: 18 may. 2024
 *      Author: dany-
 */

#include "GENERADOR_ADC.h"



static volatile uint32_t Voltaje_out;

void ADC_init(void){
	adc16_config_t adc16ConfigStruct;
	adc16_channel_config_t adc16ChannelConfigStruct;

	ADC16_GetDefaultConfig(&adc16ConfigStruct);

#ifdef BOARD_ADC_USE_ALT_VREF
    adc16ConfigStruct.referenceVoltageSource = kADC16_ReferenceVoltageSourceValt;
#endif
    ADC16_Init(ADC16, &adc16ConfigStruct);
    ADC16_EnableHardwareTrigger(ADC16, false); /* Make sure the software trigger is used. */

    adc16ChannelConfigStruct.channelNumber                        = ADC16_USER_CHANNEL;
	adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;
#if defined(FSL_FEATURE_ADC16_HAS_DIFF_MODE) && FSL_FEATURE_ADC16_HAS_DIFF_MODE
	adc16ChannelConfigStruct.enableDifferentialConversion = false;
#endif /* FSL_FEATURE_ADC16_HAS_DIFF_MODE */

}

void handle_ADC(void){

}

void read_ADC(void){
	Voltaje_out = ADC16_GetChannelConversionValue(ADC16, ADC16_CHANNEL_GROUP);
}

uint8_t get_amp(void){
	uint8_t Amp;

	Amp = Voltaje_out;

	return Amp;
}
