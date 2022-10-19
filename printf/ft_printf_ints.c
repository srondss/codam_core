/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ints.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 18:15:52 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/17 18:25:21 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include <stdarg.h>

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

int	ft_putstr(char *str)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
