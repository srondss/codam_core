/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:05:16 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 18:43:58 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_putstr(str);
	return (len);
}

int ft_putrstr(char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = len;
	while (len > 0)
	{
		len--;
		write(1, &str[len], 1);
	}
	return (i);
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
