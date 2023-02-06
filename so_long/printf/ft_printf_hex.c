/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:07:45 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/20 17:01:26 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	put_hex(va_list *list)
{
	char			str[10];
	int				x;
	unsigned int	remainder;
	unsigned int	hex;

	hex = va_arg(*list, unsigned int);
	if (hex == 0)
		return (write(1, "0", 1));
	x = 0;
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder < 10)
			str[x] = '0' + remainder;
		else
			str[x] = ('7' + 32) + remainder;
		x++;
		hex = hex / 16;
	}
	str[x] = '\0';
	return (ft_putrstr(str));
}

int	put_chex(va_list *list)
{
	char			str[10];
	int				x;
	unsigned int	remainder;
	unsigned int	hex;

	hex = va_arg(*list, unsigned int);
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
