/*
 * shell.c
 *
 *  Created on: Oct 26, 2019
 *      Author: Wendril
 */

#include "shell/shell.h"

int add_man_desc(const char *name, const char *man_desc)
{
	t_sh_func fun;
	for (fun = func_start; fun && strcmp(fun->name, name) != 0; fun = fun->next);
	if (fun)
		strlcpy(fun->man_desc, man_desc, MAN_FT_SIZE);
	else
		printf("adding man_desc: No such function '%s'\r\n", name);
	return (0);
}

int	add_sh_fun(char *name, int (*ptr_fun)(int argc, char **argv), char *description)
{
	t_sh_func new;
	new = (t_sh_func)malloc(sizeof(*new));
	if(new == NULL)
	{
		printf("MEMORY PROBLEM ADDING %s FUNCTION (malloc failed) Said function will not be available\r\n", name);
		return (-1);
	}
	t_sh_func fun;
	for (fun = func_start; fun && fun->next; fun = fun->next);
	if (func_start)
		fun->next = new;
	else
		func_start = new;
	new->name = name;
	new->func = ptr_fun;
	new->description = description;
	sprintf(new->man_desc, "There is no entry for %s.\r\n", name);
	new->next = NULL;
	return (0);
}

int	exec_shell_fun(char *buf)
{
	char	*argv[MAX_ARG_COUNT];
	int	argc = 1;

	argv[0] = buf;
	if (!*buf)
		return (0);
	uart_write("\r\n", 2);
	while (*buf && argc < MAX_ARG_COUNT)
	{
		if (is_whitespace(*buf))
		{
			*(buf++) = '\0';
			while (is_whitespace(*buf))
				buf++;
			argv[argc] = buf;
			argc++;
		}
		buf++;
	}
	for (t_sh_func fun = func_start; fun; fun = fun->next)
	{
		if (strcmp(argv[0], fun->name) == 0)
		{
			return (fun->func(argc, argv));

		}
	}
	printf ("No command named '%s'.\r\n", argv[0]);
	return (0);
}

int	shell_loop()
{
	char	buf[75];
	char 	c;
	int	shell_running, error_code;
	int pos;

	printf("\r\n\r\n========= Awkward Shell v0.0.0.0.0.0... =========\r\n\r\n");
	shell_running = 1;
	while (shell_running)
	{
		uart_write("\r\n$> ", 5);
		pos = 0;
		while(1)
		{
			c = uart_read();
			if (c == '\b')
			{
				if (pos > 0)
				{
					uart_write("\b \b", 3);
					pos--;
				}
				else
				{
					uart_write("\a", 1);
				}
			}
			else if (c == '\r')
			{
				buf[pos++] = '\0';
				break ;
			}
			else if (c != 127 && (is_whitespace(c) || c >= 32))
			{
				if (pos < sizeof(buf) - 1)
				{
					uart_write(&c, 1);
					buf[pos] = c;
					pos++;
				}
				else
					uart_write("\a", 1);
			}
			else
				uart_write("\a",1);
		}
		if (pos != 0)
		{
			if ((error_code = exec_shell_fun(buf)) < 0)
				printf("Error running %s. Error code: %d\r\n", buf, error_code);
			if (error_code == 1)
			{
				printf("Exiting shell...\r\n");
				shell_running = 0;
				return (-1);
			}

		}
	}
	return (0);
}
