/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:41:51 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/19 19:05:54 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// create function which checks if stack_a is sorted.
int	check_sorted(t_stack **head)
{
	struct s_stack *node;
	
	node = *head;

	while (node->number < node->next->number)
		node = node->next;
	if (node->next == *head)
		return (1);
	else
		return (0);
}

void	sort_three_b(t_stack **head_b)
{
	struct	s_stack *node;
	int i;
	
	i = 0;
	node = *head_b;
	while (i < 2)
	{
		if (node->number < node->next->number)
			break;
		node = node->next;
		i++;
	}
	if (i == 0 && node->next->next->next == node)
	{
		if (node->next->number < node->next->next->number)
		{
			sb(head_b);
			rrb(head_b);
		}
		else if (node->number < node->next->next->number)
			rb(head_b);	
		else
			sb(head_b);
		return ;
	}
	if (i == 0)
	{
		sb(head_b);
		node = *head_b;
		if (node->next->number < node->next->next->number)
		{
			rb(head_b);
			sb(head_b);
			rrb(head_b);
		}
		node = *head_b;
		if (node->number < node->next->number)
			sb(head_b);
	}
	else if (i == 1)
	{
		node = *head_b;
		if (node->number > node->next->next->number)
		{
			rb(head_b);
			sb(head_b);
			rrb(head_b);
		}
		else if (node->next->next->next == node)
			rrb(head_b);
		else
		{
			rb(head_b);
			sb(head_b);
			rrb(head_b);
			sb(head_b);
		}
	}
	else
		return ;
}


void	sort_three_a(t_stack **head_a)
{
	struct	s_stack *node;
	int i;
	
	i = 0;
	node = *head_a;
	while (i < 2)
	{
		if (node->number > node->next->number)
			break;
		node = node->next;
		i++;
	}
	if (i == 0 && node->next->next->next == node)
	{
		if (node->next->number > node->next->next->number)
		{
			sa(head_a);
			rra(head_a);
		}
		else if (node->number < node->next->next->number)
			sa(head_a);
		else
			ra(head_a);
		return ;
	}
	if (i == 0)
	{
		sa(head_a);
		node = *head_a;
		if (node->next->number > node->next->next->number)
		{
			ra(head_a);
			sa(head_a);
			rra(head_a);
		}
		node = *head_a;
		if (node->number > node->next->number)
			sa(head_a);
	}
	else if (i == 1)
	{
		node = *head_a;
		if (node->number < node->next->next->number)
		{
			ra(head_a);
			sa(head_a);
			rra(head_a);
		}
		else if (node->next->next->next == node)
			rra(head_a);
		else
		{
			ra(head_a);
			sa(head_a);
			rra(head_a);
			sa(head_a);
		}
	}
	else
		return ;
}
