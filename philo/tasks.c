/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:08:36 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/20 17:49:56 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_grab_fork(t_philo *philo)
{
	if (p_right_then_left(philo) == -1)
		return (-1);
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
