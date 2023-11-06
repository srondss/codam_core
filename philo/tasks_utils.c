/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:08:36 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/20 17:51:30 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_if_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		p_think(philo);
		usleep(500);
	}
}

void	*philo_execution(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	if (check_thread_creation(philo) == -1)
		return (NULL);
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_elapsed_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	if (philo->info->number_of_philos == 1)
		return (one_philo(philo));
	wait_if_even(philo);
	while (1)
	{
		if (p_grab_fork(philo) == -1)
			break ;
		if (p_eat(philo) == -1)
			break ;
		if (p_sleep(philo) == -1)
			break ;
		if (p_think(philo) == -1)
			break ;
	}
	return (NULL);
}

int	p_left_then_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_left]);
	if (message_if_alive(philo, TAKE_FORK) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_right]);
	if (message_if_alive(philo, TAKE_FORK) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		return (-1);
	}
	return (1);
}

int	p_right_then_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_right]);
	if (message_if_alive(philo, TAKE_FORK) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		return (-1);
	}
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_left]);
	if (message_if_alive(philo, TAKE_FORK) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}
	return (1);
}
