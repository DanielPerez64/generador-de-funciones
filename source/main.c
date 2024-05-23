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
		run_config_loop(); // aqui se corre la maquina de estados correspondiente al menu
	}

	return 0;
}
