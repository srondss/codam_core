/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:13 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/17 22:37:28 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->info->dead_mutex) != 0)
	{
		printf("Lock fails.\n");
		return (1);
	} // need to destroy
	if (philo->info->someone_died == 1)
	{
		pthread_mutex_unlock(&philo->info->dead_mutex);
		return (1);
	}
	if ((get_elapsed_time() - philo->last_meal_time) > philo->info->time_to_die)
	{
		philo->info->someone_died = 1;
		printf("Philo %d has died at %lld ms.\n", philo->id, get_elapsed_time());
		pthread_mutex_unlock(&philo->info->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead_mutex);

	return (0);
}

int	p_grab_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_right]);

	if (philo_is_dead(philo))
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		return (-1);
	}

	printf("Philo %d grabbed fork on his right [id: %d] [ms: %lld].\n", philo->id, philo->id_fork_right, get_elapsed_time());

	pthread_mutex_lock(&philo->info->forks[philo->id_fork_left]);

	if (philo_is_dead(philo))
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}

	printf("Philo %d grabbed fork on his left [id: %d] [ms: %lld].\n", philo->id, philo->id_fork_left, get_elapsed_time());
	return (1);
}

void	wait_ms(long long time_to_wait)
{
	long long start_time;

	start_time = get_elapsed_time();
	while ((get_elapsed_time() - start_time) < time_to_wait)
	{
		usleep(100);
	}
}

int	p_eat(t_philo *philo)
{

	if (philo_is_dead(philo))
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_elapsed_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	printf("Philo %d has started eating at %lld ms.\n",
		philo->id, get_elapsed_time());
	wait_ms(philo->info->time_to_eat);

	if (!philo_is_dead(philo))
		printf("Philo %d finished his meal at %lld ms. Forks %d and %d are now available.\n", philo->id, get_elapsed_time(), philo->id_fork_left, philo->id_fork_right);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
	return (1);
}

int	p_sleep(t_philo *philo)
{
	if (philo_is_dead(philo))
		return (-1);
	printf("Philo %d has started sleeping at %lld ms.\n",
		philo->id, get_elapsed_time());
	wait_ms(philo->info->time_to_sleep);
	return (1);
}

int	p_think(t_philo *philo)
{
	if (philo_is_dead(philo))
		return (-1);
	printf("Philo %d has started thinking at %lld ms.\n",
		philo->id, get_elapsed_time());
	return (1);
}

void	*philo_execution(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0) // if philo is has an even id, he will wait to make sure no deadlocks happen.
		usleep(500);
	while (1)
	{
		if (p_grab_fork(philo) == -1)
			break ;
		if (p_eat(philo) == -1)
			break ;
		if (p_sleep(philo) == -1)
			break ;
		if (p_think(philo) == -1)
			break ;
	}
	return (NULL);
}

void	check_leaks(void)
{
	system("leaks -q philo");
}

int	create_and_join_threads(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos[0].info->number_of_philos)
	{
		if (pthread_create(&(philos[i].thread), NULL, &philo_execution, &philos[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	// while (i < philos[0].info->number_of_philos)
	// {
	// 	if (pthread_join(philos[i].thread, NULL) != 0)
	// 		return (-1);
	// 	i++;
	// }
	return (1);
}

void	loop_philo_state(t_thread_info *info, t_philo *philos)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < info->number_of_philos)
		{
			// printf("Checking Philo %d\n", i);
			if (philo_is_dead(&philos[i]) == 1)
			{
				// printf("Philo %d is dead.\n", i);
				return ;
			}
			i++;
		}
	}
}

// TODO: Add single philo mode.
// TODO: Fix delay in ms.
// TODO: Double check if everything is freed and destroyed.

int	main(int argc, char **argv)
{
	t_thread_info	info;
	t_philo			*philos;

	atexit(check_leaks);
	if (argc < 5 || argc > 6)
		return (printf(E_ARG));

	if (parse_arguments(argv) == -1)
		return (printf(E_PARSE));
	if (init_info_struct(&info, argv) == -1)
		return (printf(E_MALLOC));

	philos = malloc(sizeof(t_philo) * info.number_of_philos);
	if (!philos)
		return (free(info.forks), printf(E_MALLOC));

	if (create_philosophers(&info, philos) == -1)
		return (printf(E_THREAD));
	create_and_join_threads(philos);
	loop_philo_state(&info, philos);
	int i;
	i = 0;
	while (i < philos[0].info->number_of_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	free(philos);
	free(info.forks);
}
