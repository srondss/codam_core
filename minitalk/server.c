/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/08 19:34:14 by ysrondy          ###   ########.fr       */
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

int	convert_binary_to_ascii(char *binary_string, char *string, int position, int id)
{
	int	i;
	int	sum;
	int	square_two;

	i = 0;
	sum = 0;
	square_two = 128;
	while (i < 8)
	{
		if (binary_string[i] == '1')
			sum += square_two;
		square_two /= 2;
		i++;
	}
	// if null-terminating byte, change state.
	if (sum == 0)
	{
		string[position] = '\0';
		g_process++;
		usleep(200);
		kill(id, SIGUSR1);
		return (1);
	}
	// if not null-terminating byte, append char to malloc string and keep going.
	else
	{
		string[position] = sum;
		usleep(200);
		kill(id, SIGUSR1);
		return (0);
	}
}

void	update_string(int signum, char *string, int id)
{
	static char	binary_string[8];
	static int	index = 0; // index of binary_string.
	static int	position = 0; // position in malloced string.

	if (signum == SIGUSR1)
		binary_string[index] = '1';
	if (signum == SIGUSR2)
		binary_string[index] = '0';
	index++;
	if (index == 8)
	{
		printf("Binary String: %s\n", binary_string);
		index = convert_binary_to_ascii(binary_string, string, position, id);
		if (index == 1) // string is finished, reset values.
			position = 0;
		else
			position++; // still more chars to be appended to string, need to increase position index by 1.
		index = 0; // reset index of binary_string as binary_string is finished.
	}
	else
	{
		usleep(200);
		kill(id, SIGUSR1); // send confirmation of receipt to client.
	}
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
		{
			len++;
			usleep(500);
			kill(id, SIGUSR1);
		}
		// Move to next state as client finished sending all bits.
		if (signum == SIGUSR2)
		{
			g_process++;
			usleep(200);
			kill(id, SIGUSR1);
		}
	}
	// Mallocs string if doesn't exist or updates string if exists.
	else if (g_process == 1)
	{
		if (!string)
			string = malloc(sizeof(char) * (len + 1));
		update_string(signum, string, id);
	}
	// prints string and reinitialises state.
	else if (g_process == 2)
	{
		printf("%s\n", string);
		free(string);
		string = NULL;
		g_process = 0;
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

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
