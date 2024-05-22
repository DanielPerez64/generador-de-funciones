/*
 * GENERATOR.h
 *
 *  Created on: 20 may. 2024
 *      Author: Pablo Daniel Perez
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "FUNCTION_GENERATOR.h"
#include "TERMINAL.h"
#include "UART_DRIVER.h"

void config_peripherics(void);

void run_config_loop(void);

void handle_signal(void);

#endif /* GENERATOR_H_ */
