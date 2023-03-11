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
	if (sum == 0)
	{
		string[position] = '\0';
		g_process++;
		return (1);
	}
	else
	{
		string[position] = sum;
		printf("%c\n", string[position]);
		return (0);
	}
}

void	update_string(int signum, char *string)
{
	static char	binary_string[8];
	static int	index = 0;
	static int	position = 0;

	if (signum == SIGUSR1)
		binary_string[index] = '1';
	if (signum == SIGUSR2)
	{
		binary_string[index] = '0';
		printf("Got a 0\n");
	}
	index++;
	if (index == 8)
	{
		printf("Entered index\n");
		printf("%s", binary_string);
		index = convert_binary_to_ascii(binary_string, string, position);
		if (index == 1)
			position = 0;
		else
			position++;
		index = 0;
		printf("Left index\n");
	}
}

void	handler_sigusr_server(int signum, siginfo_t *info, void *context)
{
	static int	id = 0;	
	static int	len = 0;
	static char	*string = NULL;

	if (g_process == 0 && id == 0)
	{
		id = info->si_pid;
		kill(id, SIGUSR1);
		return ;
	}
	if (id != info->si_pid)
		return ;
	if (g_process == 0)
	{
		if (signum == SIGUSR1)
			len++;
		if (signum == SIGUSR2)
			g_process++;
	}
	else if (g_process == 1)
	{
		printf("Got this pid: %d\n", id);
		if (!string)
			string = malloc(sizeof(char) * (len + 1));
		update_string(signum, string);
	}
	else if (g_process == 2)
	{
		printf("Final Process\n");
		printf("%s\n", string);
		free(string);
		string = NULL;
		g_process = 0;
		len = 0;
		kill(id, SIGUSR2);
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
