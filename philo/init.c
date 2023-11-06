/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:02:03 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/20 17:52:46 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_thread_info *info)
{
	if (pthread_mutex_init(&info->philo_died_mutex, NULL) != 0)
		return (printf(E_MUTEX), -1);
	if (pthread_mutex_init(&info->creation_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->philo_died_mutex);
		return (printf(E_MUTEX), -1);
	}
	if (pthread_mutex_init(&info->std_out_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->philo_died_mutex);
		pthread_mutex_destroy(&info->creation_mutex);
		return (printf(E_MUTEX), -1);
	}
	return (1);
}

int	init_info_struct(t_thread_info *info, char **argv)
{
	info->number_of_philos = ft_atol(argv[1]);
	info->time_to_die = ft_atol(argv[2]);
	info->time_to_eat = ft_atol(argv[3]);
	info->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		info->required_meals = ft_atol(argv[5]);
	else
		info->required_meals = FALSE;
	info->philo_died = FALSE;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->number_of_philos);
	info->created_threads = 0;
	if (!info->forks)
		return (printf(E_MALLOC), -1);
	if (init_mutexes(info) == -1)
		return (-1);
	return (1);
}

void	init_philo(t_thread_info *info, t_philo *philos, int i)
{
	philos[i].id = i;
	philos[i].last_meal_time = get_elapsed_time();
	philos[i].meals_eaten = 0;
	philos[i].id_fork_right = i;
	if (i == 0)
		philos[i].id_fork_left = info->number_of_philos - 1;
	else
		philos[i].id_fork_left = i - 1;
	philos[i].info = info;
}

int	destroy_mutexes(t_philo *philos, int fork_mutexes,
		int l_meal_mutexes, int r_meal_mutexes)
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
	free(philos);
	return (-1);
}

int	init_philosophers(t_thread_info *info, t_philo *philos)
{
	int	fork_mutexes;
	int	meal_mutexes;
	int	i;

	i = 0;
	fork_mutexes = 0;
	meal_mutexes = 0;
	while (i < info->number_of_philos)
	{
		init_philo(info, philos, i);
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (destroy_mutexes(philos, fork_mutexes, meal_mutexes, i));
		fork_mutexes++;
		if (pthread_mutex_init(&philos[i].last_meal_time_mutex, NULL) != 0)
			return (destroy_mutexes(philos, fork_mutexes, meal_mutexes, i));
		meal_mutexes++;
		if (info->required_meals > 0)
		{
			if (pthread_mutex_init(&philos[i].meals_eaten_mutex, NULL) != 0)
				return (destroy_mutexes(philos, fork_mutexes, meal_mutexes, i));
		}
		i++;
	}
	return (1);
}
