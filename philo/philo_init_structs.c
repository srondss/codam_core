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

void	init_philo_struct(t_thread_info *philosophers_info, char **argv)
{
	philosophers_info->forks_on_table = ft_atol(argv[1]);
	philosophers_info->time_to_die = ft_atol(argv[2]);
	philosophers_info->time_to_eat = ft_atol(argv[3]);
	philosophers_info->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philosophers_info->required_meals = ft_atol(argv[5]);
	else
		philosophers_info->required_meals = 0;
	philosophers_info->dead_philos = 0;
}

void	init_waiter_struct(t_waiter *waiter, t_philo **head,
	t_thread_info *philo_info)
{
	waiter->head = head;
	waiter->philo_info = philo_info;
}
