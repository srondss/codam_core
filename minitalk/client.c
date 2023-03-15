/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:47:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/15 10:59:57 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_breakout = 0;

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			error_handling_client();
		while (!g_breakout)
			;
		g_breakout = 0;
		i++;
	}
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
			send_bit(string, bit, pid, i);
			while (!g_breakout)
				;
			g_breakout = 0;
			bit++;
		}
		i++;
	}
	send_null(pid);
}

void	send_str_len(int pid, char *string)
{
	int	len;

	len = ft_strlen(string);
	if (len)
	{
		while (len > 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_handling_client();
			while (!g_breakout)
				;
			g_breakout = 0;
			len--;
		}
	}
	if (kill(pid, SIGUSR2) == -1)
		error_handling_client();
	while (g_breakout == 0)
		;
	g_breakout = 0;
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)(info);
	if (signum == SIGUSR1)
		g_breakout = 1;
	if (signum == SIGUSR2)
	{
		printf("Server: 202 OK\n");
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
	while (g_breakout == 0)
		wait_for_connection(ft_atoi(argv[1]));
	if (g_breakout == 1)
	{
		g_breakout = 0;
		printf("Connected!\n");
		send_str_len(ft_atoi(argv[1]), argv[2]);
		send_binary_signals(ft_atoi(argv[1]), argv[2]);
	}
}
