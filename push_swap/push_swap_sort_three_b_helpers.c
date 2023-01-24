/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three_b_helpers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:34:42 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/24 11:37:01 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b_helper(t_stack **head_b, t_stack *node)
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

void	sort_three_b_helper2(t_stack **head_b)
{
	struct s_stack	*node;

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

void	sort_three_b_helper3(t_stack **head_b, t_stack *node)
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
}
