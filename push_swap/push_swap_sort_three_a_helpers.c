/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three_a_helpers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:34:01 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/24 11:38:35 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_helper(t_stack **head_a, t_stack *node)
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

void	sort_three_a_helper2(t_stack **head_a)
{
	struct s_stack	*node;

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

void	sort_three_a_helper3(t_stack **head_a, t_stack *node)
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
}
