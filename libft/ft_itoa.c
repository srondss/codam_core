/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:59:48 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/11 14:01:42 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		num;
	int		i;

	i = 0;
	len = 0;
	num = n;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len + 1] = '\0';
	while (i < len)
	{
		if (num < 9)
		{
			str[len] = num + '0';
			break ;
		}
		num = (num % 10);
		str[len] = (num);
		len--;
	}
	return (str);
}

/*int main(void)
{
	int n;
	
	n = 42;
	printf("Itoa: %s", ft_itoa(n));
}*/
