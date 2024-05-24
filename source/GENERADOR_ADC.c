/*
 * GENERADOR_ADC.c
 *
 *  Created on: 18 may. 2024
 *     Author: Pablo Daniel Perez
 */

#include "GENERADOR_ADC.h"



static volatile uint32_t Voltaje_out;
static adc16_config_t adc16ConfigStruct;
static adc16_channel_config_t adc16ChannelConfigStruct;

void ADC_init(void){


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

void read_ADC(void){
	ADC16_SetChannelConfig(ADC16, ADC16_CHANNEL_GROUP, &adc16ChannelConfigStruct);
	while (0U == (kADC16_ChannelConversionDoneFlag &
				  ADC16_GetChannelStatusFlags(ADC16, ADC16_CHANNEL_GROUP)))
	{
	}
	Voltaje_out = ADC16_GetChannelConversionValue(ADC16, ADC16_CHANNEL_GROUP);

}

uint32_t get_amp(void){

	return ((Voltaje_out*2854)/4095)+1241;
}
