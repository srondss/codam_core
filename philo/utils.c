/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:36:10 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/16 19:36:11 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *error)
{
	printf("%s", error);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char	*nptr)
{
	long	sign;
	long	i;
	long	sum;

	i = 0;
	sum = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		sum *= 10;
		sum += nptr[i++] - '0';
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '\0')
			return (0);
	}
	if ((sum * sign) > INT_MAX || (sum * sign) < INT_MIN)
		return (0);
	return (sum * sign);
}
