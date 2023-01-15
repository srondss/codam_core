/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mandatory_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:39:15 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/15 17:56:41 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//... pa [Take the first element at the top of b and put it at the top of a]
t_stack	*pa(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct s_stack	*first_b;
	struct s_stack	*second_b;
	struct s_stack	*last_b;
	struct s_stack	*last_a;

	if (*(head_stack_b) == NULL)
		return (NULL);
	first_b = *head_stack_b;
	second_b = first_b->next;
	last_b = first_b->prev;
	second_b->prev = last_b;
	last_b->next = second_b;
	*head_stack_b = second_b;
	if (*(head_stack_a) == NULL)
	{
		*head_stack_a = malloc(sizeof(struct s_stack));
		if (!(*(head_stack_a)))
		{
			free_stack(head_stack_a);
			free_stack(head_stack_b);
			exit(EXIT_SUCCESS);
		}
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
	else
	{
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
	printf("pa\n");
	return (*head_stack_a);
}

//... pb [Take the first element at the top of a and put it at the top of b.]
t_stack	*pb(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct s_stack	*first_a;
	struct s_stack	*second_a;
	struct s_stack	*last_a;
	struct s_stack	*last_b;

	if (*(head_stack_a) == NULL)
		return (NULL);
	first_a = *head_stack_a;
	second_a = first_a->next;
	last_a = first_a->prev;
	second_a->prev = last_a;
	last_a->next = second_a;
	*head_stack_a = second_a;
	if (*(head_stack_b) == NULL)
	{
		*head_stack_b = malloc(sizeof(struct s_stack));
		if (!(*(head_stack_b)))
		{
			free_stack(head_stack_a);
			free_stack(head_stack_b);
			exit(EXIT_SUCCESS);
		}
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
	else
	{
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
	printf("pb\n");
	return (*head_stack_b);
}
