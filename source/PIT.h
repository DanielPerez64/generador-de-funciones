/*
 * PIT.h
 *
 *  Created on: 7 may 2024
 *      Author: jlpe
 */

#ifndef PIT_H_
#define PIT_H_

#include "fsl_pit.h"
#include <stdint.h>

typedef enum
{
	PIT_Ch0,
	PIT_Ch1,
	PIT_Ch2,
	PIT_Ch3

} pit_channel_t;

/* enum to list seconds in microseconds */
typedef enum
{
	_1_SEC = 1000000U,
	_2_SEC = (_1_SEC * 2U),
} micro_sec;

void PIT_init(uint32_t clock_pit);

void PIT_clear_irq_status(pit_channel_t pit_chn);

uint8_t PIT_get_irq_status(pit_channel_t pit_chn);

uint32_t get_count_value(pit_channel_t pit_chn);

void set_period(uint32_t period, uint32_t clock_pit);

void start_timer(void);


#endif /* PIT_H_ */
