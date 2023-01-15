/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mandatory_functions_3.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:55:01 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/15 17:56:37 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [Swap the first 2 elements at the top of stack a]
void	sa(t_stack **head_ref)
{
	struct s_stack	*first;
	struct s_stack	*second;
	struct s_stack	*third;
	struct s_stack	*last;

	if (*head_ref == NULL)
		return ;
	if ((*(head_ref))->next == (*(head_ref))->prev)
		*head_ref = (*(head_ref))->next;
	else
	{
		first = *head_ref;
		second = first->next;
		third = second->next;
		last = first->prev;
		first->next = third;
		first->prev = second;
		second->next = first;
		second->prev = last;
		last->next = second;
		third->prev = first;
		*head_ref = second;
	}
	printf("sa\n");
}

//[Swap the first 2 elements at the top of stack b]
void	sb(t_stack **head_ref)
{
	struct s_stack	*first;
	struct s_stack	*second;
	struct s_stack	*third;
	struct s_stack	*last;

	if (*head_ref == NULL)
		return ;
	if ((*(head_ref))->next == (*(head_ref))->prev)
		*head_ref = (*(head_ref))->next;
	else
	{
		first = *head_ref;
		second = first->next;
		third = second->next;
		last = first->prev;
		first->next = third;
		first->prev = second;
		second->next = first;
		second->prev = last;
		last->next = second;
		third->prev = first;
		*head_ref = second;
	}
	printf("sb\n");
}

//[sa and sb at the same time.]
void	ss(t_stack **head_stack_a, t_stack **head_stack_b)
{
	sa(head_stack_a);
	sb(head_stack_b);
}

//... ra [Shift up all elements of stack a by 1] 
void	ra(t_stack **head_stack_a)
{
	if (*(head_stack_a) == NULL)
		return ;
	*head_stack_a = (*(head_stack_a))->next;
	printf("ra\n");
}
