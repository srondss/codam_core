/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:29:25 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/18 16:29:31 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	// I don't think I need to malloc here considering it is a constant variable.
	info->forks = malloc(sizeof(pthread_mutex_t) * info->number_of_philos);
	info->created_threads = 0;
	if (!info->forks)
		return (printf(E_MALLOC), -1);
	if (pthread_mutex_init(&info->philo_died_mutex, NULL) != 0)
		return (free(info->forks), printf(E_MUTEX), -1);
	if (pthread_mutex_init(&info->creation_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&info->philo_died_mutex);
		return (free(info->forks), printf(E_MUTEX), -1);
	}
	return (1);
}
