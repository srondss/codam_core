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

int check_death_or_limit_meals(t_philo *philo)
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

long long get_time_since_start(t_philo *philo)
{
	long long curr_time;

	curr_time = get_elapsed_time();
	return (curr_time - philo->info->start_time);
}

int	message_if_alive(t_philo *philo, int message)
{
	long long	time;

	time = get_time_since_start(philo);
	if (check_death_or_limit_meals(philo) == -1)
		return (-1);
	if (message == TAKE_FORK)
		printf("Philo %d grabbed a fork at [ms: %lld].\n", philo->id, time);
	if (message == EAT)
		printf("Philo %d has started eating at [ms: %lld].\n", philo->id, time);
	if (message == SLEEP)
		printf("Philo %d has started sleeping at [ms: %lld].\n", philo->id, time);
	if (message == THINK)
		printf("Philo %d has started thinking at [ms: %lld].\n", philo->id, time);
	if (message == DIED)
		printf("Philo %d has died at [ms: %lld].\n", philo->id, time);
	return (1);
}

int	p_grab_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id_fork_right]);
	if (message_if_alive(philo, TAKE_FORK) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		return (-1);
	}

	pthread_mutex_lock(&philo->info->forks[philo->id_fork_left]);
	if (message_if_alive(philo, TAKE_FORK) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}
	return (1);
}

void	wait_ms(long long time_to_wait, t_philo *philo)
{
	long long start_time;

	start_time = get_elapsed_time();
	while ((get_elapsed_time() - start_time) < time_to_wait)
	{
		if (philo) // why check if philo here?
		{
			if (check_death_or_limit_meals(philo) == -1)
				return ;
		}
		usleep(250);
	}
}

int	p_eat(t_philo *philo)
{

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_elapsed_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);

	if (message_if_alive(philo, EAT) == -1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
		return (-1);
	}
	if (philo->info->required_meals > 0)
	{
		pthread_mutex_lock(&philo->meals_eaten_mutex);
		philo->meals_eaten += 1;
		pthread_mutex_unlock(&philo->meals_eaten_mutex);
	}
	wait_ms(philo->info->time_to_eat, philo);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_left]);
	pthread_mutex_unlock(&philo->info->forks[philo->id_fork_right]);
	return (1);
}

int	p_sleep(t_philo *philo)
{
	if (message_if_alive(philo, SLEEP) == -1)
		return (-1);
	wait_ms(philo->info->time_to_sleep, philo);
	return (1);
}

int	p_think(t_philo *philo)
{
	if (message_if_alive(philo, THINK) == -1)
		return (-1);
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

int	check_thread_creation(t_philo *philo)
{
	int threads;

	pthread_mutex_lock(&philo->info->creation_mutex);
	threads = philo->info->created_threads;
	pthread_mutex_unlock(&philo->info->creation_mutex);
	if (threads != philo->info->number_of_philos)
		return (-1);
	return (1);

}


void	*philo_execution(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;

	if (check_thread_creation(philo) == -1)
		return (NULL);

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_time_since_start(philo);
	printf("Philo Last Meal Time: %lld.\n", philo->last_meal_time);
	pthread_mutex_unlock(&philo->last_meal_time_mutex);

	if (philo->info->number_of_philos == 1)
		return (one_philo(philo));

	if (philo->id % 2 == 1) // if philo does not have an even id, he will wait to make sure no deadlocks happen.
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

int	create_threads(t_philo *philos)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philos->info->creation_mutex);
	while (i < philos[0].info->number_of_philos)
	{
		if (pthread_create(&(philos[i].thread), NULL, &philo_execution, &philos[i]) != 0)
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

int	check_philo_death(t_thread_info *info, t_philo *philo)
{
	long long curr_time;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	curr_time = get_elapsed_time();
	printf("Elapsed time: %lld", curr_time);
	// printf("Philo Last Meal time: %lld.\n", philo->last_meal_time);
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

void	loop_philo_state(t_thread_info *info, t_philo *philos)
{
	int i;
	int philos_finished_eating;

	while (1)
	{
		i = 0;
		// printf("Stuck in here.\n");
		philos_finished_eating = 0;
		while (i < info->number_of_philos)
		{
			if (info->required_meals > 0)
			{
				pthread_mutex_lock(&philos[i].meals_eaten_mutex);
				if (philos[i].meals_eaten >= info->required_meals)
					philos_finished_eating++;
				pthread_mutex_unlock(&philos[i].meals_eaten_mutex);
			}
			if (philos_finished_eating == info->number_of_philos)
			{
				pthread_mutex_lock(&info->philo_died_mutex);
				info->philo_died = TRUE;
				pthread_mutex_lock(&info->philo_died_mutex);
			}
			if (check_philo_death(info, &philos[i]) == -1)
				return ;
			i++;
		}
		usleep(250);
	}
}


int	free_and_destroy(t_thread_info *info)
{
	free(info->forks);
	pthread_mutex_destroy(&info->philo_died_mutex);
	pthread_mutex_destroy(&info->creation_mutex);
	printf("Mutex or Malloc error.\n");
	return (EXIT_FAILURE);
}


int join_and_free(t_thread_info *info, t_philo *philos, int ret_value)
{
	int i;
	int threads;

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
	pthread_mutex_destroy(&info->philo_died_mutex);
	pthread_mutex_destroy(&info->creation_mutex);
	i = 0;
	while (i < info->number_of_philos)
	{
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&philos[i].last_meal_time_mutex);
		if (info->required_meals > 0)
			pthread_mutex_destroy(&philos[i].meals_eaten_mutex);
		i++;
	}
	free(philos);
	free(info->forks);
	if (ret_value)
	{
		printf(E_THREAD);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// TODO: Fix delay in ms.
// TODO: Add support for required meals.
// TODO: Complete integrtion of creation_mutex.

int	main(int argc, char **argv)
{
	t_thread_info	info;
	t_philo			*philos;

	// atexit(check_leaks);
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
