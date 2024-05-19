/*
 * GENERADOR_ADC.h
 *
 *  Created on: 18 may. 2024
 *      Author: dany-
 */

#ifndef GENERADOR_ADC_H_
#define GENERADOR_ADC_H_

#include <stdbool.h>
#include <stdint.h>
#include "MK64F12.h"
#include "fsl_adc16.h"

#define ADC16_CHANNEL_GROUP 0U
#define ADC16				ADC0
#define ADC16_USER_CHANNEL  12U

/* Funciones de configuracion*/
void ADC_init(void);

/* funciones de ejecucion */
void handle_ADC(void);
void read_ADC(void);
uint8_t get_amp(void);

#endif /* GENERADOR_ADC_H_ */
