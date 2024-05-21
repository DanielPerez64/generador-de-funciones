/*
 * GENERATOR.c
 *
 *  Created on: 20 may. 2024
 *      Author: dany-
 */

#include "GENERATOR.h"

void config_peripherics(void){

	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	UART0_init();
	UART0_enable_interrupts();
	NVIC_enable_interrupt_and_priotity(UART0_IRQ, PRIORITY_10); //uart interrupt
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_5); //pit interrupt
	NVIC_global_enable_interrupts;

}

void run_app(void){
	menu_terminal();
}