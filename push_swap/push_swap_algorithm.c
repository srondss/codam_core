/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:41:51 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/24 11:35:42 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// create function which checks if stack_a is sorted.
int	check_sorted(t_stack **head)
{
	struct s_stack	*node;

	node = *head;
	if (!node)
		return (1);
	while (node->number < node->next->number)
		node = node->next;
	if (node->next == *head)
		return (1);
	else
		return (0);
}

void	sort_three_b(t_stack **head_b)
{
	struct s_stack	*node;
	int				i;

	i = 0;
	node = *head_b;
	while (i < 2)
	{
		if (node->number < node->next->number)
			break ;
		node = node->next;
		i++;
	}
	if (i == 0 && node->next->next->next == node)
	{
		sort_three_b_helper3(head_b, node);
		return ;
	}
	if (i == 0)
		sort_three_b_helper(head_b, node);
	else if (i == 1)
		sort_three_b_helper2(head_b);
	else
		return ;
}

void	sort_three_a(t_stack **head_a)
{
	struct s_stack	*node;
	int				i;

	i = 0;
	node = *head_a;
	while (i < 2)
	{
		if (node->number > node->next->number)
			break ;
		node = node->next;
		i++;
	}
	if (i == 0 && node->next->next->next == node)
	{
		sort_three_a_helper3(head_a, node);
		return ;
	}
	if (i == 0)
		sort_three_a_helper(head_a, node);
	else if (i == 1)
		sort_three_a_helper2(head_a);
	else
		return ;
}
