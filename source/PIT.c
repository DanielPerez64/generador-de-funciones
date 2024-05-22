/*
 * PIT.c
 *
 *  Created on: 7 may 2024
 *      Author: jlpe
 */

#include "PIT.h"

volatile static uint8_t pitIsrFlag = false;

void PIT0_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    pitIsrFlag = true;

    /* Added for, and affects, all PIT handlers. For CPU clock which is much larger than the IP bus clock,
     * CPU can run out of the interrupt handler before the interrupt flag being cleared, resulting in the
     * CPU's entering the handler again and again. Adding DSB can prevent the issue from happening.
     */
    __DSB();
}



void PIT_clear_irq_status(pit_channel_t pit_chn)
{
	pitIsrFlag = false;
}

uint8_t PIT_get_irq_status(pit_channel_t pit_chn)
{
	return(pitIsrFlag);
}


void PIT_init(uint32_t clock_pit)
{

	pit_config_t pitConfig;

	/*
	 * pitConfig.enableRunInDebug = false;
	 */
	PIT_GetDefaultConfig(&pitConfig);

	/* Init pit module */
	PIT_Init(PIT, &pitConfig);

	/* Set timer period for channel 0 */
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(_2_SEC, clock_pit));

	/* Enable timer interrupts for channel 0 */
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);

	//PIT_StartTimer(PIT, kPIT_Chnl_0);

}

uint32_t get_count_value(pit_channel_t pit_chn){

	return PIT_GetCurrentTimerCount(PIT,kPIT_Chnl_0);

}
/*
 * brief: set the period for the timer to count
 *
 * parameters:
 * 	clock_pit: 	clock for the timer to work
 * 	period:		time in microseconds
 *
 */
void set_period(uint32_t period, uint32_t clock_pit){

	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(period, clock_pit));
}

void start_timer(void){

	PIT_StartTimer(PIT, kPIT_Chnl_0);
}
