/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mandatory_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:39:15 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/23 11:28:28 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//... pa [Take the first element at the top of b and put it at the top of a]
t_stack	*pa(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct s_stack	*first_b;
	struct s_stack	*second_b;
	struct s_stack	*last_b;

	if (*(head_stack_b) == NULL)
		return (NULL);
	first_b = *head_stack_b;
	second_b = first_b->next;
	last_b = first_b->prev;
	second_b->prev = last_b;
	last_b->next = second_b;
	*head_stack_b = second_b;
	if (*(head_stack_a) == NULL || (*(head_stack_a))->next == (*head_stack_a))
		pa_helper(head_stack_a, head_stack_b, first_b);
	else
		pa_helper2(head_stack_a, head_stack_b, first_b, second_b);
	write(1, "pa\n", 3);
	return (*head_stack_a);
}

//... pb [Take the first element at the top of a and put it at the top of b.]
t_stack	*pb(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct s_stack	*first_a;
	struct s_stack	*second_a;
	struct s_stack	*last_a;

	if (*(head_stack_a) == NULL)
		return (NULL);
	first_a = *head_stack_a;
	second_a = first_a->next;
	last_a = first_a->prev;
	second_a->prev = last_a;
	last_a->next = second_a;
	*head_stack_a = second_a;
	if (*(head_stack_b) == NULL || (*(head_stack_b))->next == (*head_stack_b))
		pb_helper(head_stack_a, head_stack_b, first_a);
	else
		pb_helper2(head_stack_a, head_stack_b, first_a, second_a);
	write(1, "pb\n", 3);
	return (*head_stack_b);
}
