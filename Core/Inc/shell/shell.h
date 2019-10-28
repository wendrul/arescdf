/*
 * shell.h
 *
 *  Created on: Oct 27, 2019
 *      Author: Wendril
 */

#ifndef INC_SHELL_H_
#define INC_SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARG_COUNT 8
#define UART_DEVICE huart1
#define MAN_FT_SIZE 100

typedef struct	s_sh_func
{
	char				*name;
	int					(*func)(int argc, char **argv);
	char				*description;
	char				man_desc[MAN_FT_SIZE];
	struct s_sh_func	*next;

}		*t_sh_func;

t_sh_func	func_start;
int			dataReady;

int	exec_shell_fun(char *buf);
int	shell_loop();
int	init_shell();
int	add_sh_fun(char *name, int (*ptr_fun)(int argc, char **argv), char *description);
int add_man_desc(const char *name, const char *man_desc);

/*Uart communication*/

int uart_write(char * s, uint16_t size);
int uart_read();
int	is_whitespace(char c);

/*Shell Functions*/
int	sh_help(int argc, char **argv);
int	sh_print_char(int argc, char **argv);
int	sh_print_args(int argc, char **argv);
int sh_exit(int argc, char **argv);

#endif /* INC_SHELL_H_ */
