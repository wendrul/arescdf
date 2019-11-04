/*
 * test_functions.c
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */

#include <stdio.h>

int	sh_print_char(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		printf("Put some character as an argument\r\n");
		return (0);
	}
	i = 1;
	while (argc > i)
	{
		printf("character '%c' ascii code: %d\r\n", argv[i][0], argv[i][0]);
		i++;
	}
	return (0);
}

int	sh_print_args(int argc, char **argv)
{
	int i = 1;
	while(i < argc)
	{
		printf("argv[%d]: %s\r\n", i, argv[i]);
		i++;
	}
	return (0);
}
