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


void	init_philo(t_thread_info *info, t_philo *philos, int i)
{
	philos[i].id = i;
	philos[i].last_meal_time = get_elapsed_time();
	philos[i].meals_eaten = 0;
	philos[i].id_fork_right = i;
	philos[i].id_fork_left = ((i + 1) % info->number_of_philos);
	philos[i].info = info;
}

int	destroy_mutexes(t_philo *philos, int fork_mutexes, int l_meal_mutexes, int r_meal_mutexes)
{
	int	i;

	i = 0;
	while (i < fork_mutexes)
	{
		pthread_mutex_destroy(&philos[0].info->forks[i]);
		i++;
	}
	i = 0;
	while (i < l_meal_mutexes)
	{
		pthread_mutex_destroy(&philos[i].last_meal_time_mutex);
		i++;
	}
	i = 0;
	while (i < r_meal_mutexes)
	{
		pthread_mutex_destroy(&philos[i].meals_eaten_mutex);
		i++;
	}
	pthread_mutex_destroy(&philos->info->philo_died_mutex);
	free(philos->info->forks);
	printf(E_MUTEX);
	return (-1);
}

int	create_philosophers(t_thread_info *info, t_philo *philos)
{
	int	fork_mutexes;
	int	meal_mutexes;
	int i;

	i = 0;
	fork_mutexes = 0;
	meal_mutexes = 0;
	while (i < info->number_of_philos)
	{
		init_philo(info, philos, i);
		// mutex for making sure no philo can use a fork which is already used.
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (destroy_mutexes(philos, fork_mutexes, meal_mutexes, i));
		fork_mutexes++;
		// mutex for making sure no philo can change last meal time when it is being updated.
		if (pthread_mutex_init(&philos[i].last_meal_time_mutex, NULL) != 0)
			return (destroy_mutexes(philos, fork_mutexes, meal_mutexes, i));
		meal_mutexes++;
		// mutex for making sure philo doesn't continue eating after last meal. 
		if (info->required_meals > 0)
		{
			if (pthread_mutex_init(&philos[i].meals_eaten_mutex, NULL) != 0)
				return (destroy_mutexes(philos, fork_mutexes, meal_mutexes, i));
		}
		i++;
	}
	return (1);

}
