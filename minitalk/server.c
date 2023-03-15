/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/15 11:50:40 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_process = 0;

void	update_string(int signum, char *string, int id)
{
	static char	c = 0;
	static int	position = 0;
	static int	index = 0;

	c <<= 1;
	if (signum == SIGUSR1)
		c |= 1;
	if (signum == SIGUSR2)
		c |= 0;
	index++;
	if (index == 8)
	{
		string[position] = c;
		position++;
		index = 0;
		if (c == 0)
		{
			g_process++;
			position = 0;
		}
		c = 0;
	}
	if (kill(id, SIGUSR1) == -1)
		error_handling_server(string);
}

void	print_and_reset(char **string, int *ptr_len, int *ptr_id)
{
	printf("%s\n", *string);
	free(*string);
	*string = NULL;
	g_process = 0;
	*ptr_len = 0;
	if (kill(*ptr_id, SIGUSR2) == -1)
		error_handling_server(*string);
	*ptr_id = 0;
}

void	handle_string_length(int signum, int *len, int id, char **string)
{
	if (signum == SIGUSR1)
		*len += 1;
	if (signum == SIGUSR2)
		g_process++;
	if (kill(id, SIGUSR1) == -1)
		error_handling_server(*string);
}

void	handler_sigusr_server(int signum, siginfo_t *info, void *context)
{
	static int	id = 0;
	static int	len = 0;
	static char	*string = NULL;

	if (g_process == 0 && id == 0)
	{
		id = info->si_pid;
		if (kill(id, SIGUSR1) == -1)
			error_handling_server(string);
		return ;
	}
	if (id != info->si_pid)
		return ;
	if (g_process == 0)
		handle_string_length(signum, &len, id, &string);
	else if (g_process == 1)
		handle_string_chars(signum, &string, id, len);
	if (g_process == 2)
		print_and_reset(&string, &len, &id);
	(void)(context);
}

//TODO: Add real ft_printf & atoi function.

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler_sigusr_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}
