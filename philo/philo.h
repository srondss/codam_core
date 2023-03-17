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
# define E_THREAD "Creation of thread failed. Execution halted.\n"

typedef struct s_thread_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	required_meals;
}				t_thread_info;
typedef enum e_state
{
	STATE_WAITING_FOR_FORK = 0,
	STATE_EATING = 1,
	STATE_SLEEPING = 2,
	STATE_THINKING = 3,
	STATE_DEAD = 4,
}				t_state;

typedef struct s_philo
{
	pthread_t		thread;
	int				number;
	int				forks;
	t_state			state;
	struct s_philo	*next;
}				t_philo;

long	ft_atol(const char	*nptr);
t_philo	*get_last_philo(t_philo **head);
void	first_philo(t_philo **head, t_thread_info *philosophers_info, int i);
void	add_philosopher(t_philo **head, t_philo *new_philo, int i);
void	free_philosophers(t_philo **head);
void	create_philosophers(t_thread_info *philosophers_info, t_philo **head);
void	*start_execution(void *philosopher);
t_philo	*get_last_philo(t_philo **head);
void	init_philo_struct(t_thread_info *philosophers_info, char **argv);
void	parse_arguments(char **argv);
void	print_error(char *error);
void	free_philosophers(t_philo **head);
void	join_threads(t_philo **head);

#endif