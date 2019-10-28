/*
 * uart_com.c
 *
 *  Created on: Oct 28, 2019
 *      Author: Wendril
 */
#include "usart.h"
#include "gpio.h"
#include "shell/shell.h"

int uart_write(char * s, uint16_t size)
{
	HAL_UART_Transmit(&UART_DEVICE, (uint8_t*)s, size, 0xFFFF);
 	return size;
}

int	uart_read()
{
	char c;

	HAL_UART_Receive_IT(&UART_DEVICE, (uint8_t*)(&c), 1);
	while (!dataReady);
	dataReady = 0;
	return (c);
}

int	is_whitespace(char c)
{
	return (c == '\f' || c == '\n' ||
			c == '\r' || c == ' ');
}
