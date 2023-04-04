/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_or_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:48:25 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/04 09:48:27 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_and_destroy(t_thread_info *info)
{
	free(info->forks);
	pthread_mutex_destroy(&info->philo_died_mutex);
	pthread_mutex_destroy(&info->creation_mutex);
	printf("Mutex or Malloc error.\n");
	return (EXIT_FAILURE);
}

void	destroy_philo_mutexes(t_philo *philos, t_thread_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->philo_died_mutex);
	pthread_mutex_destroy(&info->creation_mutex);
	while (i < info->number_of_philos)
	{
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&philos[i].last_meal_time_mutex);
		if (info->required_meals > 0)
			pthread_mutex_destroy(&philos[i].meals_eaten_mutex);
		i++;
	}
}

int	join_and_free(t_thread_info *info, t_philo *philos, int ret_value)
{
	int	i;
	int	threads;

	i = 0;
	pthread_mutex_lock(&info->creation_mutex);
	threads = info->created_threads;
	pthread_mutex_unlock(&info->creation_mutex);
	while (i < threads)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	destroy_philo_mutexes(philos, info);
	free(philos);
	free(info->forks);
	if (ret_value)
	{
		printf(E_THREAD);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
