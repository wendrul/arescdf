/*
 * init_shell.c
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */

#include "shell/shell.h"

int	init_shell()
{
	func_start = NULL;

	/*Function `help` */
	add_sh_fun("help", sh_help, "Lists all available functions along with their descriptions.");
	add_man_desc("help", "HELP:\r\n\t- help :\t\t\tList functions\r\n\t- help [FUNC] : \tShow man entry for func\r\n");

	add_sh_fun("ascii", sh_print_char, "Shows ascii code of characters passed in argument.");

	add_sh_fun("args", sh_print_args, "Prints the arguments of the function.");

	add_sh_fun("exit", sh_exit, "exits the shell");

	return (0);
}
