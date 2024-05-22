/*
 * UART_DRIVER.h
 *
 *  Created on: 14 may. 2024
 *      Author: Pablo Daniel Perez
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "NVIC.h"
#include <stdbool.h>
#include "fsl_uart.h"
#include "fsl_port.h"

#define UART_CLK_FREQ   CLOCK_GetFreq(UART0_CLK_SRC)
#define UART_BAUDRATE 	115200
#define PIN16			16u   /*!< Pin number for pin 16 in a port */
#define PIN17			17u   /*!< Pin number for pin 17 in a port */

typedef struct{
	uint8_t flag; /** Flag to indicate that there is new data*/
	uint8_t mail_box; /** it contains the received data*/
} uart_mail_box_t;

void UART0_init(void);

void UART0_RX_TX_IRQHandler(void);

void UART0_enable_interrupts(void);

uint8_t get_mail(void);

uint8_t get_flag(void);

void set_flag(uint8_t set);

/* eraser function */
void clear_flag(void);
void clear_mail(void);

#endif /* UART_DRIVER_H_ */
