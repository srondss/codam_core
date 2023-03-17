/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:02:03 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/16 21:02:04 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Returns the last philosopher in the list.*/
t_philo	*get_last_philo(t_philo **head)
{
	t_philo	*first;

	first = *head;
	if (first == NULL)
		return (first);
	while (first->next != NULL)
		first = first->next;
	return (first);
}

/*Creates the first philosopher in the linked list of philsophers.*/
void	first_philo(t_philo **head, t_thread_info *philosophers_info, int i)
{
	t_philo	*first_philo;

	first_philo = malloc(sizeof(t_philo) * 1);
	if (!first_philo)
		(free(philosophers_info), free(head), exit(EXIT_FAILURE));
	*head = first_philo;
	first_philo->forks = 1;
	first_philo->number = i;
	first_philo->state = STATE_WAITING_FOR_FORK;
	first_philo->next = NULL;
}

/*Adds a philosopher to an already existing linked list of philosophers*/
void	add_philosopher(t_philo **head, t_philo *new_philo, int i)
{
	t_philo	*previous_philo;

	previous_philo = get_last_philo(head);
	new_philo->forks = 1;
	new_philo->number = i;
	new_philo->state = STATE_WAITING_FOR_FORK;
	new_philo->next = NULL;
	previous_philo->next = new_philo;
}

/* Will always be called after one philosopher has been malloced.*/
void	free_philosophers(t_philo **head)
{
	t_philo	*curr;
	t_philo	*prev;

	curr = *head;
	if (curr == NULL)
	{
		printf("List is empty.\n");
		return ;
	}
	prev = *head;
	while (curr != NULL)
	{
		printf("Freeing: %d\n", curr->number);
		curr = curr->next;
		free(prev);
		prev = curr;
	}
	free(head);
}

/*Creates a linked list of philosophers and activates their threads.*/
void	create_philosophers(t_thread_info *philosophers_info, t_philo **head)
{
	t_philo	*last_philo;
	t_philo	*new_philo;
	int		i;

	i = 0;
	*head = NULL;
	while (i < philosophers_info->number_of_philosophers)
	{
		last_philo = get_last_philo(head);
		if (!last_philo)
			first_philo(head, philosophers_info, i);
		else
		{
			new_philo = malloc(sizeof(t_philo) * 1);
			if (!new_philo)
				(free_philosophers(head), printf(E_MALLOC), exit(EXIT_FAILURE));
			add_philosopher(head, new_philo, i);
		}
		i++;
	}
}
