/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:47:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/08 19:32:43 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

static int	g_process = 0;

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
	kill(pid, SIGUSR2);
	usleep(200);
}

void	convert_binary_to_ascii(char *string)
{
	int	i;
	int	sum;
	int	square_two;

	i = 0;
	sum = 0;
	square_two = 128;
	while (i < 8)
	{
		if (string[i] == '1')
			sum += square_two;
		square_two /= 2;
		i++;
	}
	if (sum == 0)
		write(1, "\n", 1);
	else
		write(1, &sum, 1);
}

void	send_binary_signals(int pid, char *string)
{
	int	i;
	int	bit;

	i = 0;
	while (string[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (string[i] & (128 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(200);
		}
		i++;
	}
	send_null(pid);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	send_str_len(int pid, char *string)
{
	int	len;

	len = ft_strlen(string);
	printf("String Length: %d\n", len);
	if (len)
	{
		while (len > 0)
		{
			kill(pid, SIGUSR1);
			len--;
			usleep(200);
		}
	}
	kill(pid, SIGUSR2);
	usleep(200);
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)(info);
	if (signum == SIGUSR1)
		g_process++;
	if (signum == SIGUSR2)
	{
		write(1, "Server: 202 OK\n", 15);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (printf("Usage: ./client <server_pid> <string>\n"));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (g_process == 0)
	{
		printf("Waiting for server availablity...\n");
		kill(atoi(argv[1]), SIGUSR1);
		sleep(1);
	}
	if (g_process == 1)
	{
		printf("Got Confirmation! Sending bits...\n");
		send_str_len(atoi(argv[1]), argv[2]);
		send_binary_signals(atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
	return (1);
}
