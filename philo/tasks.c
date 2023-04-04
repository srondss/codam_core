/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:08:36 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/04 09:08:37 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (philo->id % 2 == 1)
		usleep(500);
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

int	p_grab_fork(t_philo *philo)
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

int	p_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_elapsed_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	if (message_if_alive(philo, EAT) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}
	if (philo->info->required_meals > 0)
	{
		pthread_mutex_lock(&philo->meals_eaten_mutex);
		philo->meals_eaten += 1;
		pthread_mutex_unlock(&philo->meals_eaten_mutex);
	}
	wait_ms(philo->info->time_to_eat, philo);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
	return (1);
}

int	p_sleep(t_philo *philo)
{
	if (message_if_alive(philo, SLEEP) == -1)
		return (-1);
	wait_ms(philo->info->time_to_sleep, philo);
	return (1);
}

int	p_think(t_philo *philo)
{
	if (message_if_alive(philo, THINK) == -1)
		return (-1);
	return (1);
}
