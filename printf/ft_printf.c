/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:44:13 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 20:18:53 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static const JUMP_TABLE		my_table[127] = 
{
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
	int x;
	va_list arg;

	va_start(arg, FORMAT);
	x = 0;
	while (*FORMAT)
	{
		if (*FORMAT == '%')
		{
			if (my_table[(int) (*(FORMAT + 1))] != NULL)
			{
				x += my_table[(int) (*(FORMAT + 1))](arg);
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
	return (x);
}

int main(void)
{
	printf("Og return: %d\n", printf("@ly![Tbn N%p_{#%uY7$Ns%ds8^a'!%c&Dv@8%uvG0N3#3s%%%Xkl_l!  s]\r\n", (void *)-4212550174028180241, 1625465292, 1290064617, -850343596, 707692624, 1554125633));
	ft_printf("My return: %d\n", ft_printf("@ly![Tbn N%p_{#%uY7$Ns%ds8^a'!%c&Dv@8%uvG0N3#3s%%%Xkl_l!  s]\r\n", (void *)-4212550174028180241, 1625465292, 1290064617, -850343596, 707692624, 1554125633));
}
