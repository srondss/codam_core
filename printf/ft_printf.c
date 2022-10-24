/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:44:13 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/24 12:33:13 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static const t_jump_table		g_my_table[127] = {
['d'] = &put_int,
['c'] = &put_char,
['s'] = &put_str,
['p'] = &put_ptr,
['i'] = &put_int,
['u'] = &put_uint,
['x'] = &put_hex,
['X'] = &put_chex,
['%'] = &put_prc
};

int	ft_printf(const char *FORMAT, ...)
{
	int		x;
	va_list	arg;

	va_start(arg, FORMAT);
	x = 0;
	while (*FORMAT)
	{
		if (*FORMAT == '%')
		{
			if (g_my_table[(int)(*(FORMAT + 1))] != NULL)
			{
				x += g_my_table[(int)(*(FORMAT + 1))](&arg);
				FORMAT++;
			}
		}
		else
		{
			write(1, FORMAT, 1);
			x++;
		}
		FORMAT++;
	}
	va_end(arg);
	return (x);
}

/*int main(void)
{
	ft_printf("Return %d\n", ft_printf("hello%%%"));
}*/
