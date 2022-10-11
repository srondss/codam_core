/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:00:58 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/10 09:10:22 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

static int	ft_multiplier(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	sum;
	int	multiplier;

	i = 0;
	sign = 1;
	sum = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{	
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	multiplier = ft_multiplier(nptr);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum += ((nptr[i] - 48) * multiplier);
		multiplier /= 10;
		i++;
	}
	return (sum * sign);
}

static int	ft_multiplier(const char *nptr)
{
	float	multiplier;
	int	i;

	i = 0;
	multiplier = 0.1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		multiplier *= 10;
		i++;
	}
	return ((int)multiplier);
}

/*int main(void)
{
	char str[8] = "+42lyon";
	
	printf("Og: %d\n", atoi(str));
	printf("Mine: %d\n", ft_atoi(str));
}*/
