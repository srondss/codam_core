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

int	parse_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] != '0' && ft_atol(argv[i]) == 0)
			return (printf(E_ARG), -1);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (printf(E_ARG), -1);
		}
		i++;
		j = 0;
	}
	return (1);
}

/*Function to get the current time in
milliseconds using gettimeofday() function.
Returns the current time in milliseconds. */
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/* Function to calculate the elapsed time in
milliseconds since the first call of the function.
Returns the elapsed time in milliseconds.*/
long long	get_elapsed_time(void)
{
	static long long	start_time = 0;
	long long			current_time;

	current_time = get_time();
	if (start_time == 0)
		start_time = current_time;
	return (current_time - start_time);
}


