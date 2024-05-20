/*
 * TERMINAL.c
 *
 *  Created on: 14 may. 2024
 *      Author: dany-
 */

#include "TERMINAL.h"
#include "UART_DRIVER.h"
/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
void print_menu_terminal(void)
{

	const uint8_t screen_txt1[] 		= "1. Configurar hora\r";
	const uint8_t screen_txt2[] 		= "2. Ver hora\r";
	const uint8_t screen_txt3[] 		= "3. Configurar alarma\r";
	const uint8_t config_screen[] 		= vt_100_clear;
	const uint8_t posxy_1[]				= "\033[10;21H";
	const uint8_t posxy_2[]				= "\033[11;21H";
	const uint8_t posxy_3[]				= "\033[12;21H";
	const uint8_t background[]			= vt_100_bkgBlue;

    /* Send g_tipString out. */

	UART_WriteBlocking(UART0, config_screen, sizeof(config_screen)/sizeof(config_screen[0]));

    UART_WriteBlocking(UART0, posxy_1, 		 sizeof(posxy_1)/sizeof(posxy_1[0]));
    UART_WriteBlocking(UART0, background,	 sizeof(background)/sizeof(background[0]));
    UART_WriteBlocking(UART0, config_screen, sizeof(config_screen)/sizeof(config_screen[0]));
    UART_WriteBlocking(UART0, screen_txt1,   sizeof(screen_txt1)/sizeof(screen_txt1[0]));


    UART_WriteBlocking(UART0, posxy_2, 		 sizeof(posxy_2)/sizeof(posxy_2[0]));
	UART_WriteBlocking(UART0, screen_txt2,   sizeof(screen_txt2)/sizeof(screen_txt2[0]));

	UART_WriteBlocking(UART0, posxy_3, 		 sizeof(posxy_3)/sizeof(posxy_3[0]));
	UART_WriteBlocking(UART0, screen_txt3,   sizeof(screen_txt3)/sizeof(screen_txt3[0]));


}

void print_config_hora(void){
	const uint8_t screen_txt1[] 		= "Ingrese por favor la hora:\r";
	const uint8_t config_screen[] 		= vt_100_clear;
	const uint8_t posxy_1[]				= "\033[10;21H";
	const uint8_t config_font[]			= "\033[1;30m";
	const uint8_t background[]			= vt_100_bkgWhite;

	/* Send g_tipString out. */

	UART_WriteBlocking(UART0, config_screen, sizeof(config_screen)/sizeof(config_screen[0]));

	UART_WriteBlocking(UART0, posxy_1, 		 sizeof(posxy_1)/sizeof(posxy_1[0]));
	UART_WriteBlocking(UART0, background,	 sizeof(background)/sizeof(background[0]));
	UART_WriteBlocking(UART0, config_font,   sizeof(config_font)/sizeof(config_font[0]));
	UART_WriteBlocking(UART0, config_screen, sizeof(config_screen)/sizeof(config_screen[0]));
	UART_WriteBlocking(UART0, screen_txt1,   sizeof(screen_txt1)/sizeof(screen_txt1[0]));

}

void terminal_print_text(uint8_t *message, uint8_t length){

	UART_WriteBlocking(UART0, message, length);

}

void menu_terminal(void){

	typedef enum states_menu{
		MENU_ST,
		FREQ_CONFIG,
		SELECT_SIGNAL
	} menu_states;

	menu_states fsm_menu = MENU_ST;

	switch(fsm_menu){

		case MENU_ST:

			if(get_flag()){

				//print menu

				switch(get_mail()){

					case '1':
						//print option 1
						fsm_menu = FREQ_CONFIG;
						break;

					case '2':
						//print option 2
						fsm_menu = SELECT_SIGNAL;
						break;

					case '\e':
						fsm_menu = MENU_ST;
						break;
				}
			}

			break;

		case FREQ_CONFIG:

			if(true == get_flag()){

				switch(get_mail()){

					case '1':
						//print option 1
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la frecuencia
								//configurar frecuencia
							}
						}
						break;

					case '2':
						//print option 2
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la frecuencia
								//configurar frecuencia
							}
						}
						break;

					case '3':
						//print option 3
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la frecuencia
								//configurar frecuencia
							}
						}
						break;

					case '4':
						//print option 4
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la frecuencia
								//configurar frecuencia
							}
						}
						break;
				}
			}

			break;

		case SELECT_SIGNAL:

			if(true == get_flag()){

				switch(get_mail()){

					 case '1':
						//print option 1
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la senal
								//configurar senal
							}
						}
						break;

					case '2':
						//print option 2
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la frecuencia
								//configurar senal
							}
						}
						break;

					case '3':
						//print option 3
						while(!get_flag()){
							if('\r' == get_mail()){
								//print text: se ha seleccionado la frecuencia
								//configurar senal
							}
						}
						break;

				}
			}

			break;

	}

}
