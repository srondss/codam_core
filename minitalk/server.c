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

typedef struct	s_client 
{
	int	id;
	char 	string[9];
	int	bits;
	struct	s_client *next;
}	t_client;

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

t_client *find_client(t_client **lst_clients, int id)
{
	t_client *first;
	first = *lst_clients;

	if (first == NULL)
		return (NULL);
	if (first->id == id)
		return (first);
	while (first != NULL)
	{
		if (first->id == id)
			return (first);
		first = first->next;
	}
	return (NULL);
}

t_client	*create_new_client(t_client **head, int id)
{
	t_client	*new;
	t_client	*first;

	first = *head;
	new = malloc(sizeof(t_client) * 1);
	new->id = id;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (first->next != NULL)
			first = first->next;
		first->next = new;
	}
	return (new);
}

void	update_client(t_client *client, int signum)
{
	if (signum == SIGUSR1)
	{
		client->string[client->bits] = '1';
		client->bits++;
	}
	if (signum == SIGUSR2)
	{
		client->string[client->bits] = '0';
		client->bits++;
	}
	if (client->bits == 8)
	{
		client->string[client->bits] = '\0';
		client->bits = 0;
		convert_binary_to_ascii(client->id, client->string);
	}
}


void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static int	id = 0;	
	static t_client	**head;
	t_client	*client;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)(context);
	if (!head)
	{
		head = malloc(sizeof(t_client *) * 1);
	}
	client = find_client(head, id);
	if (!client)
	{
		client = create_new_client(head, id);
		update_client(client, signum);
	}
	else
		update_client(client, signum);
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
