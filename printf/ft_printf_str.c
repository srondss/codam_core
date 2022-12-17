/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:05:16 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/12/17 14:35:58 by ysrondy          ###   ########.fr       */
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
	int	flag;

	flag = 0;
	len = ft_strlen(str);
	i = len;
	while (len > 0)
	{
		len--;
		flag = write(1, &str[len], 1);
		if (flag == -1)
			return (-1);
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int	len;
	int	flag;

	len = ft_strlen(str);
	flag = write(1, str, len);
	if (flag == -1)
		return (flag);
	return (len);
}
