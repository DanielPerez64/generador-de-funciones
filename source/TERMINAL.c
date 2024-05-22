/*
 * TERMINAL.c
 *
 *  Created on: 14 may. 2024
 *      Author: Pablo Daniel Perez
 */

#include "TERMINAL.h"
#include "UART_DRIVER.h"
#include "FUNCTION_GENERATOR.h"
/*******************************************************************************
 * Code
 ******************************************************************************/

// fsm menu variable
menu_states fsm_menu = MENU_ST;

/* function implementation*/

void terminal_print_text(uint8_t *message, uint8_t length){

	UART_WriteBlocking(UART0, message, length);

}

void menu_terminal(void){


	switch(fsm_menu){

		case MENU_ST:

			show_menu();

			while(!get_flag()); // wait for something on mailbox

			if(ASCII_1 == get_mail()){

				fsm_menu = FREQ_CONFIG;
			}
			else if(ASCII_2 == get_mail()){

				fsm_menu = SELECT_SIGNAL;
			}
			else{
				fsm_menu = MENU_ST;
			}

			clear_flag();
			break;

		case FREQ_CONFIG:

			show_set_freq();

			while(!get_flag()); //wait for mailbox

			if(ASCII_ESC == get_mail()){
				fsm_menu = MENU_ST;
			}
			else if(ASCII_1 == get_mail()){
				// set the frequency
				set_config_period(_1KHZ);
				// tell user that frequency has been selected
				clear_flag();
				idle_until_enter();


			}
			else if(ASCII_2 == get_mail()){
				// set the frequency
				set_config_period(_5KHZ);
				// tell user that frequency has been selected
				clear_flag();
				idle_until_enter();

			}
			else if(ASCII_3 == get_mail()){
				// set the frequency
				set_config_period(_10KHZ);
				// tell user that frequency has been selected
				clear_flag();
				idle_until_enter();

			}
			else if(ASCII_4 == get_mail()){
				// set the frequency
				set_config_period(_100KHZ);
				// tell user that frequency has been selected
				clear_flag();
				idle_until_enter();

			}
			else{
				fsm_menu = FREQ_CONFIG;
			}

			clear_flag();
			break;

		case SELECT_SIGNAL:

			show_set_signal();

			while(!get_flag()); //wait for mailbox

			if(ASCII_ESC == get_mail()){
				fsm_menu = MENU_ST;
			}
			else if(ASCII_1 == get_mail()){
				// set the signal
				set_signal(SINE);
				// tell user that signal has been selected
				clear_flag();
				idle_until_enter();

			}
			else if(ASCII_2 == get_mail()){
				// set the signal
				set_signal(TRIANGLE);
				// tell user that signal has been selected
				clear_flag();
				idle_until_enter();

			}
			else if(ASCII_3 == get_mail()){
				// set the signal
				set_signal(SQUARE);
				// tell user that signal has been selected
				clear_flag();
				idle_until_enter();

			}
			else{
				fsm_menu = SELECT_SIGNAL;
			}

			clear_flag();
			break;

	}

}

static void show_menu(void){
	uint8_t clear[]			= vt_100_clear;
	uint8_t text1[] 		= "1. Seleccione frecuencia.";
	uint8_t text2[] 		= "2. Seleccion de senial.";
	uint8_t posxy_1[]		= "\033[10;21H";
	uint8_t posxy_2[]		= "\033[11;21H";

	/* PRINT TEXT TO THE UART */
	terminal_print_text(clear, 	sizeof(clear)/sizeof(clear[0]));
	terminal_print_text(posxy_1, 	sizeof(posxy_1)/sizeof(posxy_1[0]));
	terminal_print_text(text1, 		sizeof(text1)/sizeof(text1[0]));
	terminal_print_text(posxy_2, 	sizeof(posxy_2)/sizeof(posxy_2[0]));
	terminal_print_text(text2, 		sizeof(text2)/sizeof(text2[0]));

}

static void show_set_freq(void){
	uint8_t clear[]			= vt_100_clear;
	uint8_t text1[] 		= "Seleccione frecuencia a generar.";
	uint8_t text2[] 		= "1. 1KHz.";
	uint8_t text3[] 		= "2. 5KHz.";
	uint8_t text4[] 		= "3. 10KHz.";
	uint8_t text5[] 		= "4. 100KHz.";
	uint8_t posxy_1[]		= "\033[10;21H";
	uint8_t posxy_2[]		= "\033[12;21H";
	uint8_t posxy_3[]		= "\033[13;21H";
	uint8_t posxy_4[]		= "\033[14;21H";
	uint8_t posxy_5[]		= "\033[15;21H";

	/* PRINT TEXT TO THE UART */
	terminal_print_text(clear, 	sizeof(clear)/sizeof(clear[0])); //clear screen
	/* print the message*/
	terminal_print_text(posxy_1, 	sizeof(posxy_1)/sizeof(posxy_1[0]));
	terminal_print_text(text1, 		sizeof(text1)/sizeof(text1[0]));
	terminal_print_text(posxy_2, 	sizeof(posxy_2)/sizeof(posxy_2[0]));
	terminal_print_text(text2, 		sizeof(text2)/sizeof(text2[0]));
	terminal_print_text(posxy_3, 	sizeof(posxy_3)/sizeof(posxy_3[0]));
	terminal_print_text(text3, 		sizeof(text3)/sizeof(text3[0]));
	terminal_print_text(posxy_4, 	sizeof(posxy_4)/sizeof(posxy_4[0]));
	terminal_print_text(text4, 		sizeof(text4)/sizeof(text4[0]));
	terminal_print_text(posxy_5, 	sizeof(posxy_5)/sizeof(posxy_5[0]));
	terminal_print_text(text5, 		sizeof(text5)/sizeof(text5[0]));
}

static void show_set_signal(void){
	uint8_t clear[]			= vt_100_clear;
	uint8_t text1[] 		= "Selecciona la senial.";
	uint8_t text2[] 		= "1. Senoidal.";
	uint8_t text3[] 		= "2. Triangular.";
	uint8_t text4[] 		= "3. Cuadrada.";

	uint8_t posxy_1[]		= "\033[10;21H";
	uint8_t posxy_2[]		= "\033[12;21H";
	uint8_t posxy_3[]		= "\033[13;21H";
	uint8_t posxy_4[]		= "\033[14;21H";

	/* PRINT TEXT TO THE UART */
	terminal_print_text(clear, 	sizeof(clear)/sizeof(clear[0])); // clear screen
	// print the message
	terminal_print_text(posxy_1, 	sizeof(posxy_1)/sizeof(posxy_1[0]));
	terminal_print_text(text1, 		sizeof(text1)/sizeof(text1[0]));
	terminal_print_text(posxy_2, 	sizeof(posxy_2)/sizeof(posxy_2[0]));
	terminal_print_text(text2, 		sizeof(text2)/sizeof(text2[0]));

	terminal_print_text(posxy_3, 	sizeof(posxy_3)/sizeof(posxy_3[0]));
	terminal_print_text(text3, 		sizeof(text3)/sizeof(text3[0]));
	terminal_print_text(posxy_4, 	sizeof(posxy_4)/sizeof(posxy_4[0]));
	terminal_print_text(text4, 		sizeof(text4)/sizeof(text4[0]));

}

static void selection_msg(void){
	uint8_t clear[]			= vt_100_clear;
	uint8_t text1[] 		= "Se ha seleccionado la frecuencia, presione enter.";
	uint8_t posxy_1[]		= "\033[10;21H";

	/* PRINT TEXT TO THE UART */
	terminal_print_text(clear, 	sizeof(clear)/sizeof(clear[0])); // clear screen
	// print the message
	terminal_print_text(posxy_1, 	sizeof(posxy_1)/sizeof(posxy_1[0]));
	terminal_print_text(text1, 		sizeof(text1)/sizeof(text1[0]));

}

static void idle_until_enter(void){

	while(!get_flag()){
		if(ASCII_ENTER == get_mail()){
			clear_mail();
			break;
		}
		clear_flag();
	}

	clear_flag();
	selection_msg();


	while(!get_flag()){
		if(ASCII_ENTER == get_mail()){
			clear_mail();
			break;
		}
		clear_flag();
	}

}
