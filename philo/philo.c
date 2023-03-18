/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:13 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/17 22:37:28 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
	Current problem: Waiter will always pick 1st philo if none of the philos are ready yet.
	Ideally, waiter function will only be called when philosopher is thinking.
	So process will look like the following:
	-> Philsopher state == THINKING, prompt waiter.
	-> If not sufficient forks on table, refuse (return 0).
		If sufficient forks, accept (return 1) and philo can start eating, thinking, etc...
	Hence, waiter should not be in a while loop but rather a function call.
	However, if waiter is entering part of function when he is giving forks to the philo,
	that part should be mutex to avoid data races.
	Will fix tomorrow.
*/

t_philo	*find_hungriest_philo(t_philo **head)
{
	t_philo	*philo;
	t_philo	*hungriest_philo;

	philo = *head;
	hungriest_philo = *head;
	while (philo != NULL)
	{
		printf("Waiter is looking for hungriest philo.\n");
		printf("Curr philo: %d with %lld last meal\n", philo->number, philo->last_meal_time);
		if (philo->last_meal_time == 0 && philo->forks != 2 && philo->state == STATE_THINKING)
		{
			printf("First round.\n");
			return (philo);
		}
		if (philo->last_meal_time < hungriest_philo->last_meal_time && philo->state == STATE_THINKING && philo->forks != 2)
		{
			printf("Hungriest Philo %d with last meal at %lld is now replaced by philo %d with last meal at %lld\n", hungriest_philo->number, hungriest_philo->last_meal_time, philo->number, philo->last_meal_time);
			hungriest_philo = philo;
		}
		philo = philo->next;
	}
	printf("Returning hungriest philo.\n");
	return (hungriest_philo);
}

void	*waiter_execution(void *ptr_waiter)
{
	t_waiter	*waiter;
	t_philo		*hungriest_philo;

	waiter = (t_waiter *)ptr_waiter;
	printf("Waiter has been created.\n");
	while (waiter->philo_info->dead_philos != waiter->philo_info->forks_on_table)
	{
		printf("Forks on table: %d\n", waiter->philo_info->forks_on_table);
		while (waiter->philo_info->forks_on_table >= 0)
		{
			if (waiter->philo_info->forks_on_table - 2 >= 0)
			{
				printf("Inside waiter while loop.\n");
				hungriest_philo = find_hungriest_philo(waiter->head);
				printf("Hungriest Philo: %d\n", hungriest_philo->number);
				hungriest_philo->forks += 2;
				waiter->philo_info->forks_on_table -= 2;
				hungriest_philo->state = STATE_EATING;
				hungriest_philo->last_meal_time = (get_elapsed_time() + waiter->philo_info->time_to_eat);
				printf("Exited waiter while loop.\n");
			}
		}
	}
	return (waiter);
}


void	*philo_execution(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	while (1)
	{
		if (get_elapsed_time() >= philo->philo_info->time_to_die &&
			philo->last_meal_time == 0)
			break ;
		if (philo->last_meal_time != 0 && (get_elapsed_time()
				- philo->last_meal_time) >= philo->philo_info->time_to_die)
			break ;
		if (philo->forks == 2)
		{
			printf("Philo %d got two forks!\n", philo->number);
			printf("Philo %d has started eating at %lld ms.\n",
				philo->number, get_elapsed_time());
			usleep(philo->philo_info->time_to_eat * 1000);
			philo->forks = 0;
			philo->philo_info->forks_on_table += 2;
			philo->state = STATE_SLEEPING;
			printf("Philo %d has started sleeping at %lld ms.\n",
				philo->number, get_elapsed_time());
			usleep(philo->philo_info->time_to_sleep * 1000);
			philo->state = STATE_THINKING;
			printf("Philo %d has started thinking at %lld ms.\n",
				philo->number, get_elapsed_time());
		}
	}
	philo->state = STATE_DEAD;
	philo->philo_info->dead_philos += 1;
	printf("OMG! Philo %d died at: %lld ms.\n", philo->number, get_elapsed_time());
	return (philo);
}

void	check_leaks(void)
{
	system("leaks -q philo");
}

void	create_and_join_threads(t_philo **head, t_thread_info *philo_info,
		t_waiter *waiter)
{
	t_philo	*philo;

	if (pthread_create(&(waiter->thread), NULL, &waiter_execution, waiter) != 0)
		(free_philosophers(head), free(philo_info),
			free(waiter), print_error(E_THREAD));

	philo = *head;
	while (philo != NULL)
	{
		if (pthread_create(&(philo->thread), NULL,
				&philo_execution, philo) != 0)
			(free_philosophers(head), free(philo_info), print_error(E_THREAD));
		philo = philo->next;
	}
	philo = *head;
	while (philo != NULL)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			(free_philosophers(head), free(philo_info), print_error(E_THREAD));
		printf("Philo %d has finished execution.\n", philo->number);
		philo = philo->next;
	}
}

int	main(int argc, char **argv)
{
	t_waiter		*waiter;
	t_thread_info	*philo_info;
	t_philo			**head;

	atexit(check_leaks);
	if (argc < 5 || argc > 6)
		return (printf(E_ARG));
	parse_arguments(argv);
	philo_info = malloc(sizeof(t_thread_info) * 1);
	if (!philo_info)
		return (printf(E_MALLOC));
	init_philo_struct(philo_info, argv);
	head = malloc(sizeof(t_philo *) * 1);
	if (!head)
		(free(philo_info), print_error(E_MALLOC));
	create_philosophers(philo_info, head);
	waiter = malloc(sizeof(t_waiter) * 1);
	if (!waiter)
		(free(philo_info), free(head), print_error(E_MALLOC));
	init_waiter_struct(waiter, head, philo_info);
	create_and_join_threads(head, philo_info, waiter);

	free_philosophers(head);
	free(philo_info);
	free(waiter);
}
