/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_client.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:42:20 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/15 12:07:40 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	sign = 1;
	while (nptr[i] == '\f' || nptr[i] == ' ' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
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
	}
	return (sum * sign);
}

void	wait_for_connection(int pid)
{
	static int	sleepcount = 0;

	printf("Trying to connect to server...\n");
	if (kill(pid, SIGUSR1) == -1)
		error_handling_client();
	sleep(1);
	sleepcount++;
	if (sleepcount == 15)
	{
		printf("TIMEOUT.\nCould not connect with server.\n");
		printf("Please check pid or try again later...\n");
		exit(EXIT_FAILURE);
	}
}

void	send_bit(char *string, int bit, int pid, int i)
{
	if (string[i] & (128 >> bit))
	{
		if (kill(pid, SIGUSR1) == -1)
			error_handling_client();
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			error_handling_client();
	}
}

void	error_handling_client(void)
{
	printf("Client-side Error.\n");
	exit(EXIT_FAILURE);
}
