/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/20 11:32:18 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_client
{
	int		pid;
	char		bits[8];
	int		bits_received;
	char		*message;
	struct s_client	*next;
}	t_client;

t_client *ptr_to_list = NULL;

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
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
			if (string[i] & (128 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(100);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	string = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!string)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		string[i] = s1[i];
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}

void	convert_binary_to_ascii(t_client *client)
{
	int	i;
	int	sum;
	int	square_two;
	char	string_with_one_letter[2];

	i = 0;
	sum = 0;
	square_two = 128;
	while (i < 8)
	{
		if (client->bits[i] == '1')
			sum += square_two;
		square_two /= 2;
		i++;
	}
	if (sum == 0)
	{
		printf("%s", client->message);
		free(client->message);
		send_binary_signals(client->pid, "Server: 200 OK");
	}
	else
	{
		string_with_one_letter[0] = sum;
		string_with_one_letter[1] = '\0';
		client->message = ft_strjoin(client->message, string_with_one_letter);
	}
}

int	check_if_pid_exists(t_client **head, int pid)
{
	t_client *first;

	first = *head;
	if (first == NULL)
		return (0);
	if (first->pid == pid)
		return (1);
	while (first->next != NULL)
	{
		if (first->pid == pid)
			return (1);
		first = first->next;
	}
	return (0);
}

t_client	*ft_lstlast(t_client *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_client **lst, t_client *new)
{
	t_client	*tmp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = new;
		}
	}
}

void	update_message(int signum, int pid)
{
	t_client	*first_node;

	first_node = ptr_to_list;
	while (first_node->pid != pid)
		first_node = first_node->next;
	if (!first_node->message)
	{
		first_node->message = malloc(sizeof(char) * 1);
		first_node->message = "\0";
	}
	if (signum == SIGUSR2)
	{
		first_node->bits[first_node->bits_received] = '0';
		first_node->bits_received += 1;
	}
	else if (signum == SIGUSR1)
	{
		first_node->bits[first_node->bits_received] = '1';
		first_node->bits_received += 1;
	}
	if (first_node->bits_received == 8)
	{
		convert_binary_to_ascii(first_node);
		first_node->bits_received = 0;
	}
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	t_client	*new_client;

	if (check_if_pid_exists(&ptr_to_list, info->si_pid) == 0)
	{
		write(1, "Allocating New Node\n", 20);
		new_client = malloc(sizeof(t_client) * 1);
		new_client->pid = info->si_pid;
		new_client->message = malloc(sizeof(char) * 1);
		new_client->message = "\0";
		new_client->next = NULL;
		ft_lstadd_back(&ptr_to_list, new_client);
	}
	// run code which loops through linked list and updates message.
	update_message(signum, info->si_pid);

	(void)(context);
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
