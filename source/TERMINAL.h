/*
 * TERMINAL.h
 *
 *  Created on: 14 may. 2024
 *      Author: dany-
 */

/********************************************************************************************************
*********************************************************************************************************
*********************************************************************************************************
Set Display Attributes
Set Attribute Mode	<ESC>[{attr1};...;{attrn}m
Sets multiple display attribute settings. The following lists standard attributes:
0	Reset all attributes
1	Bright
2	Dim
4	Underscore
5	Blink
7	Reverse
8	Hidden

	Foreground Colors
30	Black
31	Red
32	Green
33	Yellow
34	Blue
35	Magenta
36	Cyan
37	White

	Background Colors
40	Black
41	Red
42	Green
43	Yellow
44	Blue
45	Magenta
46	Cyan
47	White

SOURCE:
http://graphcomp.com/info/specs/ansi_col.html

*********************************************************************************************************
*********************************************************************************************************
*********************************************************************************************************/

#ifndef TERMINAL_H_
#define TERMINAL_H_

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* UART instance and clock */

#include <stdint.h>
//#include "TIMER.h"

/* text foreground color */
#define vt_100_frgBlack 	"\033[30m"
#define vt_100_frgRed 		"\033[31m"
#define vt_100_frgGreen 	"\033[32m"
#define vt_100_frgYellow	"\033[33m"
#define	vt_100_frgBlue		"\033[34m"
#define	vt_100_frgMagenta	"\033[35m"
#define	vt_100_frgCyan		"\033[36m"
#define	vt_100_frgWhite		"\033[37m"

/* background colors */
#define	vt_100_bkgBlack 	"\033[40m"
#define	vt_100_bkgRed 		"\033[41m"
#define	vt_100_bkgGreen 	"\033[42m"
#define	vt_100_bkgYellow	"\033[43m"
#define	vt_100_bkgBlue		"\033[44m"
#define	vt_100_bkgMagenta	"\033[45m"
#define	vt_100_bkgCyan		"\033[46m"
#define	vt_100_bkgWhite		"\033[47m"

/* screen manipulation */
#define	vt_100_clear			"\033[2J"
#define	vt_100_xy_center		"\033[25;25H"

#define ASCII_0				48u
#define ASCII_1				49u
#define ASCII_2				50u
#define ASCII_3				51u
#define ASCII_4				52u
#define ASCII_5				53u
#define ASCII_6				54u
#define ASCII_7				55u
#define ASCII_8				56u
#define ASCII_9				57u

#define ASCII_CR			13u
#define ASCII_ESC			27u


void print_menu_terminal(void);

void print_config_hora(void);

//void print_ver_hora(time_struct *rtc);

void print_config_alarma(void);

void terminal_print_text(uint8_t *message, uint8_t length);

void menu_terminal(void);

#endif /* TERMINAL_H_ */
