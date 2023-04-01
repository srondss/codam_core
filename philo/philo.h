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
typedef struct s_thread_info
{
	long long		start_time;
	int				number_of_philos;

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

	int				required_meals;
	int				philo_died;

	pthread_mutex_t	*forks;
	pthread_mutex_t philo_died_mutex;
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
	pthread_mutex_t last_meal_time_mutex;

}				t_philo;


long		ft_atol(const char	*nptr);
int			create_philosophers(t_thread_info *info, t_philo *philos);
void		*philo_execution(void *philosopher);
int			init_info_struct(t_thread_info *info, char **argv);
void		init_philo(t_thread_info *info, t_philo *philos, int i);
int			parse_arguments(char **argv);
void		print_error(char *error);
long long	get_elapsed_time(void);
long long	get_time(void);
#endif
