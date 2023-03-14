/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/14 15:26:30 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	g_process = 0;

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	update_string(int signum, char *string, int id)
{
	static char c = 0;
	static int	index = 0; // index of binary_string.
	static int	position = 0; // position in malloced string.

	c <<= 1; 
	if (signum == SIGUSR1)
		c |= 1;
	if (signum == SIGUSR2)
		c |= 0; // doesn't change anything.
	index++;
	if (index == 8)
	{
		// printf("|%c|\n", c);
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
	// usleep(500);
	kill(id, SIGUSR1); // send confirmation of receipt to client.
}

void	handler_sigusr_server(int signum, siginfo_t *info, void *context)
{
	static int	id = 0;
	static int	len = 0;
	static char	*string = NULL;

// Checks if a client is already being handled.
	if (g_process == 0 && id == 0)
	{
		id = info->si_pid;
		kill(id, SIGUSR1);
		return ;
	}
// If another client is trying to interact with server, will just be ignored.
	if (id != info->si_pid)
		return ;
// Receives the length of the string that needs to be allocated.
// Sends a bit back to client acknowledging receipt.
	if (g_process == 0)
	{
		if (signum == SIGUSR1)
			len++;
		// Move to next state as client finished sending all bits.
		if (signum == SIGUSR2)
			g_process++;
		kill(id, SIGUSR1);
	}
	// Mallocs string if doesn't exist or updates string if exists.
	else if (g_process == 1)
	{
		// printf("Length Received: %d from %d\n", len, id);
		// printf("Received string bit.\n");
		if (!string)
			string = malloc(sizeof(char) * (len + 1));
		update_string(signum, string, id);
	}
	// prints string and reinitialises state.
	if (g_process == 2)
	{
		printf("%s\n", string);
		free(string);
		string = NULL;
		g_process = 0;
		// position = 0;
		len = 0;
		kill(id, SIGUSR2); // kills client.
		id = 0;
	}
	(void)(id);
	(void)(context);
}

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
	{
		pause();
	}
}
