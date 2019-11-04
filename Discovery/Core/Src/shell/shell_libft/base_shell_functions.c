/*
 * base_shell_libft.c
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */

#include <stdio.h>
#include "shell/shell.h"

int	sh_help(int argc, char **argv)
{
	uart_write("\r\n", 2);
	if (argc == 1)
	{
		for (t_sh_func fun = func_start; fun != NULL; fun = fun->next)
			printf("- %s:  \t%s\r\n", fun->name, fun->description);
		printf("\r\n\r\nFor more information about a command type `help foo`\r\n");
	}
	else
	{
		t_sh_func fun;
		for (fun = func_start; fun && strcmp(fun->name, argv[1]) != 0; fun = fun->next);
		if (fun != NULL)
			printf("%s\r\n", fun->man_desc);
		else
			printf("help: There is no such function '%s'\r\n", argv[1]);
	}
	return (0);
}

int sh_exit(int argc, char **argv)
{
	return (1);
}
