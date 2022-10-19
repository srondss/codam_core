/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:44:13 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/18 14:48:20 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "ft_printf.h"

typedef int	(*JUMP_TABLE)(va_list arg); 

int	put_int(va_list list);
int	put_prc(va_list list);
int	ft_putstr(char *str);
int	put_char(va_list list);
int	put_str(va_list list);
int	put_ptr(va_list list);
char	*get_hex(unsigned long hex);

int	ft_printf(const char *FORMAT, ...)
{
	static const JUMP_TABLE		my_table[127] = 
	{
		['d'] = &put_int,
	 	['c'] = &put_char,
		['s'] = &put_str,
		['p'] = &put_ptr
	/*	['i'] = &put_int,
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
	int j;
	int *i;
	unsigned long x;
	
	j = 5;
	i = &j;

	ft_printf("My Pointer address: %p\n", i);
	printf("Original pointer address: %p\n", i);
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

int 	put_str(va_list list)
{
	char	*str;
	int	len;

	str = va_arg(list, char *);
	len = ft_putstr(str);
	return (len);
}

int	put_ptr(va_list list)
{
	int	*ptr;
	char	*str;
	unsigned long	hex;

	ptr = va_arg(list, int *);
	hex = (unsigned long)ptr;
	str = get_hex(hex);
	hex = 11;
	write(1, &str[0], 1);
	write(1, &str[1], 1);
	while (hex > 1)
	{
		write(1, &str[hex], 1);
		hex--;
	}
	
	return (11);
}

char	*get_hex(unsigned long hex)
{
	char *arr;
	int x; 
	unsigned long remainder;
	
	arr = (char *)malloc(sizeof(char) * 12);
	arr[0] = '0';
	arr[1] = 'x';
	x = 2;
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder < 10)
			arr[x] = '0' + remainder;
		else
			arr[x] = ('7'+32) + remainder;
		printf("arr[%d]: %c\n", x, arr[x]);
		x++;
		hex = hex / 16;
	}
	return (arr);
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

