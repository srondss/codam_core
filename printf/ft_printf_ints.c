/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ints.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 18:15:52 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/20 17:02:32 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_int(va_list *list)
{
	int		num;
	char	*str;

	num = va_arg(*list, int);
	str = ft_itoa(num);
	if (!str)
		return (0);
	num = ft_putstr(str);
	free(str);
	return (num);
}

static char	*ft_uitoa(unsigned int len, unsigned int num, unsigned int n)
{
	char	*str;

	while (n > 0)
	{
		n /= 10;
		len++;
	}
	if (num == 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (str);
	str[len] = '\0';
	while (0 < len)
	{
		len--;
		if (num < 9)
		{
			str[len] = num + '0';
			break ;
		}
		str[len] = ((num % 10) + '0');
		num /= 10;
	}
	return (str);
}

int	put_uint(va_list *list)
{
	unsigned int	num;
	char			*str;

	num = va_arg(*list, unsigned int);
	str = ft_uitoa(0, num, num);
	if (!str)
		return (0);
	num = ft_putstr(str);
	free(str);
	return (num);
}
