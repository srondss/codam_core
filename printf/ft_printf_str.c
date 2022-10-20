/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:05:16 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/20 17:03:28 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

int	put_char(va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	return (write(1, &c, 1));
}

int	put_str(va_list *list)
{
	char	*str;
	int		len;

	str = va_arg(*list, char *);
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_putstr(str);
	return (len);
}

int	ft_putrstr(char *str)
{
	int	len;
	int	i;

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
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
