/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:18:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/26 09:22:42 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long	ft_atol(const char	*nptr)
{
	long	sign;
	long	i;
	long	sum;

	i = 0;
	sum = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{	
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		sum *= 10;
		sum += nptr[i++] - '0';
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '\0')
			return (0);
	}
	if ((sum * sign) > INT_MAX || (sum * sign) < INT_MIN)
		return (0);
	return (sum * sign);
}

int	check_string(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != 48 && ft_atol(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	find_duplicate(t_stack *node, t_stack *next, int length)
{
	while (length > 0)
	{
		while (node != next)
		{
			if (node->number == next->number)
				return (1);
			else
				next = next->next;
		}
		node = node->next;
		next = node->next;
		length--;
	}
	return (0);
}

int	check_duplicate(t_stack **head_a)
{
	struct s_stack	*node;
	struct s_stack	*next;
	int				i;

	node = (*(head_a))->next;
	i = 0;
	while (node != *head_a)
	{
		node = node->next;
		i++;
	}
	next = node->next;
	return (find_duplicate(node, next, i));
}

void	check_errors(int argc, char **argv)
{
	if (check_string(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		exit(EXIT_SUCCESS);
	else if (argc == 3)
	{
		if (ft_atol(argv[1]) < ft_atol(argv[2]))
			exit(EXIT_SUCCESS);
		else if (ft_atol(argv[1]) == ft_atol(argv[2]))
		{
			write(2, "Error\n", 6);
			exit(EXIT_SUCCESS);
		}
		else
		{
			write(1, "sa\n", 3);
			exit(EXIT_SUCCESS);
		}
	}
}
