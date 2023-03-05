/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/05 23:02:25 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
Need to fix the following things

1. Server must print the entire string, not just bit by bit.
In order to facilitate this, I must send the length of the string as the first signal received by server.
Then calloc a string of x bytes and start filling it in.

2. Client should first send a 'prod' bit to see if it is able to start sending the string.
If the client doesn't receive approval from the server, it should sleep and try again in a few seconds.
If too many seconds go by, the user should receive a message saying that it should try later or check pid.

3. If 2 clients are trying to send signals at the same time, server should only process signals from the 
client that is the current id of the static id variable. Once it receives '\0', it can reset the id to 0 and
accept the next signal.

*/

static int	process = 0;

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	convert_binary_to_ascii(char *binary_string, char *string, int position)
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
	printf("Sum: %d\n", sum);
	if (sum == 0)
	{
		string[position] = '\0';
		process++;
		return (1);
	}
	else
	{
		string[position] = sum;
		printf("String: %s\n", string);
		return (0);
	}
}

void	update_string(int signum, char *string)
{
	static char	binary_string[8];
	static int	index = 0;
	static int	position = 0;

	printf("Index: %d, Position: %d\n", index, position);
	if (signum == SIGUSR1)
		binary_string[index] = '1';
	if (signum == SIGUSR2)
		binary_string[index] = '0';
	index++;
	if (index == 8)
	{
		printf("Binary_String: %s\n", binary_string);
		index = convert_binary_to_ascii(binary_string, string, position);
		if (index == 1)
			position = 0;
		else
			position++;
		index = 0;
	}
}


void	handler_sigusr_server(int signum, siginfo_t *info, void *context)
{
	static int	id = 0;	
	static int	len = 0;
	static char	*string = NULL;

	if (signum == SIGUSR1)
		printf("Received 1\n");
	if (signum == SIGUSR2)
		printf("Received 0\n");
	if (info->si_pid != 0)
		id = info->si_pid;
	if (process == 0) // First call. Receiving str_len;
	{
		write(1, "Enter Process 0\n", 16);
		if (signum == SIGUSR1)
			len++;
		if (signum == SIGUSR2)
			process++;
	}
	else if (process == 1) // Second call. Malloc String.
	{
		write(1, "Enter Process 1\n", 16);
		if (!string)
			string = malloc(sizeof(char) * (len + 1));
		update_string(signum, string);
	}
	else if (process == 2)
	{
		printf("%s\n", string);
		free(string);
		process = 0;
		len = 0;
		kill(id, SIGUSR2);
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
