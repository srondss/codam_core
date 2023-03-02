/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/27 15:53:05 by ysrondy          ###   ########.fr       */
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

void	convert_binary_to_ascii(int pid, char *string)
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
	{
		kill(pid, SIGUSR2);
		write(1, "\n", 1);
	}
	else
		write(1, &sum, 1);
}


void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static int	id = 0;	

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)(context);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
