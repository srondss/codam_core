/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:13 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/03 21:56:19 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	message_if_alive(t_philo *philo, int message)
{
	long long	time;

	time = get_time_since_start(philo);
	if (check_death_or_limit_meals(philo) == -1)
		return (-1);
	if (message == TAKE_FORK)
		printf("%lld %d has taken a fork\n", time, philo->id + 1);
	if (message == EAT)
		printf("%lld %d is eating\n", time, philo->id + 1);
	if (message == SLEEP)
		printf("%lld %d is sleeping\n", time, philo->id + 1);
	if (message == THINK)
		printf("%lld %d is thinking\n", time, philo->id + 1);
	if (message == DIED)
		printf("%lld %d died\n", time, philo->id + 1);
	return (1);
}

void	*one_philo(t_philo *philo)
{
	message_if_alive(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_right]);
	wait_ms(philo->info->time_to_die, philo);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
	return (NULL);
}

int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philos->info->creation_mutex);
	while (i < philos[0].info->number_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL,
				&philo_execution, &philos[i]) != 0)
		{
			pthread_mutex_unlock(&philos->info->creation_mutex);
			return (-1);
		}
		i++;
		philos->info->created_threads += 1;
		usleep(250);
	}
	philos->info->start_time = get_elapsed_time();
	pthread_mutex_unlock(&philos->info->creation_mutex);
	return (1);
}

int	main(int argc, char **argv)
{
	t_thread_info	info;
	t_philo			*philos;

	if (argc < 5 || argc > 6)
		return (printf(E_ARG));
	if (parse_arguments(argv) == -1)
		return (EXIT_FAILURE);
	if (init_info_struct(&info, argv) == -1)
		return (EXIT_FAILURE);
	philos = malloc(sizeof(t_philo) * info.number_of_philos);
	if (!philos)
		return (free_and_destroy(&info));
	if (init_philosophers(&info, philos) == -1)
		return (free_and_destroy(&info));
	if (create_threads(philos) == -1)
		return (join_and_free(&info, philos, 1));
	loop_philo_state(&info, philos);
	return (join_and_free(&info, philos, 0));
}
