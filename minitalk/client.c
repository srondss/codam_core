/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:47:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/14 15:26:28 by ysrondy       ########   odam.nl         */
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


static int	breakout = 0;

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		// printf("Sent NULL Bit\n");
		kill(pid, SIGUSR2);
		while (!breakout)
			;
		breakout = 0;
		i++;
	}
	pause();
}
// 'a' =>      0110 0001 = 97
// a & 128 =>  1000 0000 = 128

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
			// printf("Sent STR Bit: %d\n", bit);
			if (string[i] & (128 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!breakout)
				;
			// printf("POST STR PAUSE\n");
			breakout = 0;
			bit++;
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
			// printf("Sent LEN Bit\n");
			kill(pid, SIGUSR1);
			while (!breakout)
				;
			breakout = 0;
			len--;
		}
	}
	// printf("Sent FINAL LEN Bit\n");
	kill(pid, SIGUSR2);
	while (breakout == 0)
		;
	// printf("POST FINAL LEN PAUSE\n");
	breakout = 0;
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)(info);
	if (signum == SIGUSR1)
	{
		// printf("Received BIT!\n");
		breakout = 1;
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

	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (breakout == 0)
	{
		printf("Sending prod bit...\n");
		kill(atoi(argv[1]), SIGUSR1);
		sleep(1);
	}
	if (breakout == 1)
	{
		breakout = 0;
		printf("Got Confirmation! Sending bits...\n");
		send_str_len(atoi(argv[1]), argv[2]);
		send_binary_signals(atoi(argv[1]), argv[2]);
	}
	return (1);
}
