/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:44:13 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/17 18:30:02 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "ft_printf.h"

typedef int	(*JUMP_TABLE)(va_list arg); 

int put_int(va_list list);
int	put_prc(va_list list);
int	ft_putstr(char *str);
int	put_char(va_list list);

int	ft_printf(const char *FORMAT, ...)
{
	static const JUMP_TABLE		my_table[127] = 
	{
		['d'] = &put_int,
	 	['c'] = &put_char
	/*	['s'] = &put_str,
		['p'] = &put_ptr,
		['i'] = &put_int,
		['u'] = &put_uint,
		['x'] = &put_hex,
		['X'] = &put_chex,
		['%'] = &put_prc*/
	};

	int x;
	va_list arg;

	va_start(arg, FORMAT);
	x = 0;

	while (FORMAT[x] != '\0')
	{
		if (FORMAT[x] == '%')
		{
			if (my_table[(int) FORMAT[x + 1]] != NULL)
			{
				my_table[(int) FORMAT[x + 1]](arg);
				x++;
			}
		}
		else
			write(1, &FORMAT[x], 1);
		x++;
	}

	return (x);
}

int main(void)
{
	char c = 'h';
	printf("return: %d\n", (ft_printf("Hello %c\n", c, 14)));
}

int	put_prc(va_list list)
{
	(void) list;
	write(1, "%", 1);
	return (1);
}

int put_int(va_list list)
{
	int num;
	char *str;

	num = va_arg(list, int);
	str = ft_itoa((long) num);
	if (!str)
		return (0);
	num = ft_putstr(str);
	free(str);
	return (num);
}

int	put_char(va_list list)
{
	int	letter;
	
	letter = va_arg(list, int);
	ft_putchar_fd(letter, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

