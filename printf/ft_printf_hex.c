/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:07:45 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 19:40:43 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	put_hex(va_list list)
{
	char str[20];
	int x; 
	unsigned long remainder;
	unsigned long hex;
	
	hex = va_arg(list, unsigned long);
	if (hex == 0)
		return (write(1, "0", 1));
	x = 0;
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder < 10)
			str[x] = '0' + remainder;
		else
			str[x] = ('7'+32) + remainder;
		x++;
		hex = hex / 16;
	}
	str[x] = '\0';
	return (ft_putrstr(str));
}

int	put_chex(va_list list)
{
	char str[20];
	int x; 
	unsigned long remainder;
	unsigned long hex;
	
	hex = va_arg(list, unsigned long);
	if (hex == 0)
		return (write(1, "0", 1));
	x = 0;
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder < 10)
			str[x] = '0' + remainder;
		else
			str[x] = '7' + remainder;
		x++;
		hex = hex / 16;
	}
	str[x] = '\0';
	return (ft_putrstr(str));
}
