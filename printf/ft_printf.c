/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:44:13 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 15:56:38 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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

/*int main(void)
{
	unsigned int j;
	unsigned int *ptr;

	ptr = &j;
	j = 214747;

	ft_printf("My Pointer address: %%\n");
	printf("Original pointer address: %%\n");
}*/

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

int put_uint(va_list list)
{
	unsigned int num;
	char *str;

	num = va_arg(list, unsigned int);
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
	int				*ptr;
	char			*str;
	unsigned long	hex;

	ptr = va_arg(list, int *);
	hex = (unsigned long)ptr;
	str = get_hex_ptr(hex);
	return (ft_putstr(str));
}

char	*get_hex_ptr(unsigned long hex)
{
	char *str;
	int x; 
	unsigned long remainder;
	
	str = (char *)malloc(sizeof(char) * 13);
	str[0] = '0';
	str[1] = 'x';
	x = 13;
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder < 10)
			str[x] = '0' + remainder;
		else
			str[x] = ('7'+32) + remainder;
		x--;
		hex = hex / 16;
	}
	return (str);
}


int	put_hex(va_list list)
{
	char str[10];
	int x; 
	unsigned long remainder;
	unsigned long hex;
	
	hex = va_arg(list, unsigned long);
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
	str[x] = '\0';
	return (ft_putrstr(str));
}

int	put_chex(va_list list)
{
	char str[10];
	int x; 
	unsigned long remainder;
	unsigned long hex;
	
	hex = va_arg(list, unsigned long);
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

int ft_putrstr(char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = len;
	while (len >= 0)
	{
		write(1, str+len, 1);
		len--;
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

