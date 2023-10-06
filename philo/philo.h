/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:55 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/16 18:49:56 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define E_ARG "Correct Usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat].\n"
# define E_PARSE "Not all arguments are integers.\n"
# define E_MALLOC "Malloc failed. Execution halted.\n"
# define E_THREAD "Thread Error. Execution halted.\n"
# define E_MUTEX "Mutex Error. Execution halted.\n"
# define FALSE 0
# define TRUE 1
# define TAKE_FORK 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DIED 6

typedef struct s_thread_info
{
	long long		start_time;
	int				number_of_philos;

	int				created_threads;
	pthread_mutex_t	creation_mutex;

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

	int				required_meals;

	int				philo_died;
	pthread_mutex_t	philo_died_mutex;

	pthread_mutex_t	*forks;
}				t_thread_info;
typedef struct s_philo
{
	pthread_t		thread;
	t_thread_info	*info;

	int				id_fork_left;
	int				id_fork_right;
	int				id;

	int				meals_eaten;
	pthread_mutex_t	meals_eaten_mutex;

	long long		last_meal_time;
	pthread_mutex_t	last_meal_time_mutex;

}				t_philo;

long		ft_atol(const char	*nptr);
int			parse_arguments(char **argv);
int			init_philosophers(t_thread_info *info, t_philo *philos);
int			init_info_struct(t_thread_info *info, char **argv);
void		init_philo(t_thread_info *info, t_philo *philos, int i);
long long	get_elapsed_time(void);
int			p_think(t_philo *philo);
int			p_sleep(t_philo *philo);
int			p_eat(t_philo *philo);
int			p_grab_fork(t_philo *philo);
int			p_right_then_left(t_philo *philo);
int			p_left_then_right(t_philo *philo);
int			check_philo_death(t_thread_info *info, t_philo *philo);
int			check_death_or_limit_meals(t_philo *philo);
int			check_thread_creation(t_philo *philo);
int			free_and_destroy(t_thread_info *info);
int			join_and_free(t_thread_info *info, t_philo *philos, int ret_value);
int			destroy_mutexes(t_philo *philos, int fork_mutexes,
				int l_meal_mutexes, int r_meal_mutexes);
void		*philo_execution(void *philosopher);
void		*one_philo(t_philo *philo);
int			create_threads(t_philo *philos);
void		loop_philo_state(t_thread_info *info, t_philo *philos);
int			message_if_alive(t_philo *philo, int message);
void		wait_ms(long long time_to_wait, t_philo *philo);
long long	get_time_since_start(t_philo *philo);
long long	get_elapsed_time(void);

#endif
