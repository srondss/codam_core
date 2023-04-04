/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:23:33 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/04 09:23:35 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_thread_creation(t_philo *philo)
{
	int	threads;

	pthread_mutex_lock(&philo->info->creation_mutex);
	threads = philo->info->created_threads;
	pthread_mutex_unlock(&philo->info->creation_mutex);
	if (threads != philo->info->number_of_philos)
		return (-1);
	return (1);
}

int	check_death_or_limit_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->philo_died_mutex);
	if (philo->info->philo_died == TRUE)
	{
		pthread_mutex_unlock(&philo->info->philo_died_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->philo_died_mutex);
	return (1);
}

int	check_philo_death(t_thread_info *info, t_philo *philo)
{
	long long	curr_time;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	curr_time = get_elapsed_time();
	if ((curr_time - philo->last_meal_time) > info->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_meal_time_mutex);
		pthread_mutex_lock(&info->philo_died_mutex);
		if (info->philo_died != TRUE)
		{
			pthread_mutex_unlock(&info->philo_died_mutex);
			message_if_alive(philo, DIED);
			pthread_mutex_lock(&info->philo_died_mutex);
			info->philo_died = TRUE;
			pthread_mutex_unlock(&info->philo_died_mutex);
		}
		else
			pthread_mutex_unlock(&info->philo_died_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	return (1);
}
