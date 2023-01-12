/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:18:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/12 22:15:22 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_string(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != 48 && atol(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicate(t_stack **head_a)
{
	struct s_stack *node;
	struct s_stack *next;
	int 		i;

	node = (*(head_a))->next;

	i = 0;
	while (node != *head_a)
	{
		node = node->next;
		i++;
	}
	next = node->next;
	while (i > 0)
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
		i--;
	}
	return (0);
}
