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

/*
Okay, so...

We need to send a bit and wait for a response before sending the next one.
Logic will be:

process == 0 => client is trying to make connection with server.
process == 1 => client has successfully made connection with server.

process == 3 => client is going to (or has) send/sent a bit and is waiting for confirmation to send next one.
process == 4 => client has received confirmation and process becomes 3 again.

*/


static int	g_process = 0;

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (g_process == 3)
		{
			kill(pid, SIGUSR2);
			pause();
			g_process--;
			i++;
		}
	}
	kill(pid, SIGUSR2);
	pause();
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
			if (g_process == 3)
			{
				if (string[i] & (128 >> bit))
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				pause();
				g_process--;
				bit++;
			}
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
	if (len)
	{
		while (len > 0)
		{
			if (g_process == 3)
			{
				kill(pid, SIGUSR1);
				pause();
				len--;
				g_process--;
			}
		}
	}
	kill(pid, SIGUSR2);
	pause();
	g_process--;
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)(info);
	if (signum == SIGUSR1)
	{
		printf("Received BIT!\n");
		g_process++;
	}
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
		printf("Sending prod bit...\n");
		kill(atoi(argv[1]), SIGUSR1);
		sleep(1);
	}
	if (g_process == 1)
	{
		printf("Got Confirmation! Sending bits...\n");
		g_process = 3;
		send_str_len(atoi(argv[1]), argv[2]);
		send_binary_signals(atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
	return (1);
}
