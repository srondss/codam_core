/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:49:13 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/16 18:49:14 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] != '0' && ft_atol(argv[i]) == 0)
			return (printf(E_PARSE), exit(EXIT_FAILURE));
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (printf(E_PARSE), exit(EXIT_FAILURE));
		}
		i++;
		j = 0;
	}
}

void	init_philo_struct(t_thread_info *philosophers_info, char **argv)
{
	philosophers_info->number_of_philosophers = ft_atol(argv[1]);
	philosophers_info->time_to_die = ft_atol(argv[2]);
	philosophers_info->time_to_eat = ft_atol(argv[3]);
	philosophers_info->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philosophers_info->required_meals = ft_atol(argv[5]);
	else
		philosophers_info->required_meals = 0;
}

void	*start_execution(void)
{
	return (1);
}

// TODO: Join the threads using the pthread function in the library.
void	join_threads(t_philo **head)
{
	t_philo *first;

	first = *head;
	while (first != NULL)
	{

	}
}

int	main(int argc, char **argv)
{
	t_thread_info	*philosophers_info;
	t_philo			**head;

	if (argc < 5 || argc > 6)
		return (printf(E_ARG));

	parse_arguments(argv);

	philosophers_info = malloc(sizeof(t_thread_info) * 1);
	if (!philosophers_info)
		return (printf(E_MALLOC));

	init_philo_struct(philosophers_info, argv);
	head = malloc(sizeof(t_philo *) * 1);
	if (!head)
		(free(philosophers_info), print_error(E_MALLOC));

	create_philosophers(philosophers_info, head);

	join_threads(head);

	free(philosophers_info);
}
