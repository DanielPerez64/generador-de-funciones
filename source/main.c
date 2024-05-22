/*
 * Pablo Daniel Perez Montes
 * TAE 2024 CINVESTAV GDL
 *
 * Generador de funciones
 */
#include "GENERATOR.h"

int main(void){

	config_peripherics();
	function_start(); // inicia el timer unicamente

	while(1){

		handle_signal(); // no estoy seguro si esta implementacion es correcta
		run_config_loop(); // aqui se corre la maquina de estados correspondiente al menu y eso

	}

	return 0;
}
