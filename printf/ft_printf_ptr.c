/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:09:28 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 19:37:19 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_ptr(va_list *list)
{
	unsigned long	ptr;
	char			*str;
	unsigned long	hex;

	ptr = va_arg(*list, unsigned long);
	if (!ptr)
		return (write(1, "0x0", 3));
	str = get_hex_ptr(ptr);
	hex = ft_putrstr(str);
	free(str);
	return (hex);
}

char	*get_hex_ptr(unsigned long hex)
{
	char *str;
	int x; 
	unsigned long remainder;
	
	str = (char *)malloc(sizeof(char) * 19);
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
	str[x] = 'x';
	str[x+1] = '0';
	str[x+2] = '\0';
	return (str);
}
