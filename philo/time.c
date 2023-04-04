/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:07:13 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/04 09:07:14 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_elapsed_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	wait_ms(long long time_to_wait, t_philo *philo)
{
	long long	start_time;

	start_time = get_elapsed_time();
	while ((get_elapsed_time() - start_time) < time_to_wait)
	{
		if (philo)
		{
			if (check_death_or_limit_meals(philo) == -1)
				return ;
		}
		usleep(250);
	}
}

long long	get_time_since_start(t_philo *philo)
{
	long long	curr_time;

	curr_time = get_elapsed_time();
	return (curr_time - philo->info->start_time);
}
