/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mandatory_helpers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:27:21 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/23 11:33:11 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_helper(t_stack **head_stack_a, t_stack **head_stack_b,
t_stack *first_b)
{
	if (*(head_stack_a) == NULL)
	{
		*head_stack_a = malloc(sizeof(struct s_stack));
		if (!(*(head_stack_a)))
			free_and_exit(head_stack_a, head_stack_b);
		(*(head_stack_a))->number = first_b->number;
		(*(head_stack_a))->next = *head_stack_a;
		(*(head_stack_a))->prev = *head_stack_a;
		free(first_b);
	}
	else if ((*(head_stack_a))->next == (*(head_stack_a)))
	{
		(*(head_stack_a))->next = first_b;
		(*(head_stack_a))->prev = first_b;
		first_b->next = *head_stack_a;
		first_b->prev = *head_stack_a;
		*head_stack_a = first_b;
	}
}

void	pa_helper2(t_stack **head_stack_a, t_stack **head_stack_b,
t_stack *first_b, t_stack *second_b)
{
	struct s_stack	*last_a;

	last_a = (*(head_stack_a))->prev;
	last_a->next = first_b;
	first_b->next = (*(head_stack_a));
	first_b->prev = last_a;
	(*(head_stack_a))->prev = first_b;
	if (first_b == second_b)
	{
		*head_stack_b = NULL;
		*head_stack_a = first_b;
	}
	else
		*head_stack_a = first_b;
}

void	pb_helper(t_stack **head_stack_a, t_stack **head_stack_b,
t_stack *first_a)
{
	if (*(head_stack_b) == NULL)
	{
		*head_stack_b = malloc(sizeof(struct s_stack));
		if (!(*(head_stack_b)))
			free_and_exit(head_stack_a, head_stack_b);
		(*(head_stack_b))->number = first_a->number;
		(*(head_stack_b))->next = *head_stack_b;
		(*(head_stack_b))->prev = *head_stack_b;
		free(first_a);
	}
	else if ((*(head_stack_b))->next == (*(head_stack_b)))
	{
		(*(head_stack_b))->next = first_a;
		(*(head_stack_b))->prev = first_a;
		first_a->next = *head_stack_b;
		first_a->prev = *head_stack_b;
		*head_stack_b = first_a;
	}
}

void	pb_helper2(t_stack **head_stack_a, t_stack **head_stack_b,
t_stack *first_a, t_stack *second_a)
{
	struct s_stack	*last_b;

	last_b = (*(head_stack_b))->prev;
	last_b->next = first_a;
	first_a->next = (*(head_stack_b));
	first_a->prev = last_b;
	(*(head_stack_b))->prev = first_a;
	if (first_a == second_a)
	{
		*head_stack_a = NULL;
		*head_stack_b = first_a;
	}
	else
		*head_stack_b = first_a;
}
