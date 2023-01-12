/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:41:51 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/12 21:18:09 by ysrondy          ###   ########.fr       */
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

void	call_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	struct s_stack *head_b;
	int		i;
	
	if (check_sorted(stack_a) && !(*stack_b))
		return ;
//	Begin algorithm.
	while (*stack_a)
	{
	// if stack b is empty, just push a to b.
		if (!(*stack_b))
			pb(stack_a, stack_b);
	// if top stack a is bigger than top stack b, just push to stack b.
		else if ((*(stack_a))->number > (*(stack_b))->number)
			pb(stack_a, stack_b);
		else
		{
			i = 0;
			head_b = *stack_b;
	// while top of stack a is bigger than stack b, increment i and then go to next node in stack b.
			while ((*(stack_a))->number < head_b->number)
			{
	//		if there's only 1 node in stack b, then just push a to b and swap both.
				if ((*(stack_b))->prev == (*(stack_b))->next && (*(stack_b))->next->number == (*(stack_b))->number)
				{
					pb(stack_a, stack_b);
					sb(stack_b);
					break;
				}
				head_b = head_b->next;
	//		if you went through all the nodes, increment + break;
				if (head_b == *stack_b)
				{
					i++;
					break;
				}
				i++;
			}
	//		if stack b has more than 1 node but only 1 number is bigger than top of stack a
	//		the just push a to b and swap.
			if (i == 1)
			{
				pb(stack_a, stack_b);
				sb(stack_b);
			}
			else if (i > 1)
			{
	//		while there are i numbers bigger than top of stack a, push b to a and rotate so 
	//		top of stack a is still the same initial number.
				while (i > 0)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
					i--;
				}
	//		when you've pushed everything back to a, push a to b so the initial number is now at top of stack b.
				pb(stack_a, stack_b);
			}
		}
	}
	// push everything back to stack a since it's sorted.
	while (*stack_b)
		pa(stack_a, stack_b);
}

