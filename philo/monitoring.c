/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:43:01 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/04 09:43:02 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meals_eaten(t_philo *philos, int *philos_finished_eating, int i)
{
	pthread_mutex_lock(&philos[i].meals_eaten_mutex);
	if (philos[i].meals_eaten >= philos->info->required_meals)
		*(philos_finished_eating) += 1;
	pthread_mutex_unlock(&philos[i].meals_eaten_mutex);
}

void	loop_philo_state(t_thread_info *info, t_philo *philos)
{
	int	i;
	int	philos_finished_eating;

	while (1)
	{
		i = 0;
		philos_finished_eating = 0;
		while (i < info->number_of_philos)
		{
			if (info->required_meals > 0)
				update_meals_eaten(philos, &philos_finished_eating, i);
			if (philos_finished_eating == info->number_of_philos)
			{
				pthread_mutex_lock(&info->philo_died_mutex);
				info->philo_died = TRUE;
				pthread_mutex_unlock(&info->philo_died_mutex);
				return ;
			}
			if (check_philo_death(info, &philos[i]) == -1)
				return ;
			i++;
		}
		usleep(250);
	}
}
