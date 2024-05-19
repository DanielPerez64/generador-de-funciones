/*
 * UART_DRIVER.c
 *
 *  Created on: 14 may. 2024
 *      Author: dany-
 */
#include "UART_DRIVER.h"

static volatile uart_mail_box_t g_mail_box_uart_0 ={0, 0}; // encapsulada en este codigo

void UART0_init(void){

	uart_config_t config;
	uint32_t uart_clock;

	CLOCK_EnableClock(kCLOCK_PortB);

	PORT_SetPinMux(PORTB, PIN16, kPORT_MuxAlt3);
	PORT_SetPinMux(PORTB, PIN17, kPORT_MuxAlt3);

	UART_GetDefaultConfig(&config);
	config.baudRate_Bps = UART_BAUDRATE;
	config.enableTx     = true;
	config.enableRx     = true;

	uart_clock = CLOCK_GetFreq(UART0_CLK_SRC);
	UART_Init(UART0, &config, uart_clock);

}

void UART0_RX_TX_IRQHandler(void){


    /* If new data arrived. */
    if ((kUART_RxDataRegFullFlag | kUART_RxOverrunFlag) & UART_GetStatusFlags(UART0))
    {
    	g_mail_box_uart_0.mail_box = UART_ReadByte(UART0);
    	g_mail_box_uart_0.flag = true;

    }
    SDK_ISR_EXIT_BARRIER;
}

void UART0_enable_interrupts(void){
	/* Enable RX interrupt. */
	UART_EnableInterrupts(UART0, kUART_RxDataRegFullInterruptEnable | kUART_RxOverrunInterruptEnable);
}

uint8_t get_mail(void){
	return g_mail_box_uart_0.mail_box;
}

uint8_t get_flag(void){
	return g_mail_box_uart_0.flag;
}

void set_flag(uint8_t set){
	g_mail_box_uart_0.flag = set;
}

