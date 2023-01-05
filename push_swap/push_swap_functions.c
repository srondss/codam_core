/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:39:15 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/05 11:35:48 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// [Swap the first 2 elements at the top of stack a]
void	sa(t_stack **head_ref)
{
	struct s_stack *first = *head_ref;
	struct s_stack *second = first->next;
	struct s_stack *last = second->next;
	struct s_stack *second_last = first->prev;

	first->next = last;
	first->prev = second;
	second->next = first;
	second->prev = second_last;
	second_last->next = second;
	last->prev = first;
	*head_ref = second;
}
// RUN IN TERMINAL: gc push_swap.c push_swap_functions.c libft/ft_*.c

//[Swap the first 2 elements at the top of stack b]
/*void	sb(t_stack *stack_b)
{
	return ;
}

//[sa and sb at the same time.]
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
//	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	struct s_stack *last_node_stack_a;
	struct s_stack *new_node;

	last_node_stack_a = stack_a->prev;
	if (!stack_b)
		return ;
	if (stack_b->next == stack_b)
	{
		new_node = malloc(sizeof(struct s_stack));
		new_node->number = stack_b->number;
		new_node->next = stack_a;
		new_node->prev = last_node_stack_a;
		last_node_stack_a->next = new_node;
		stack_a->prev = new_node;
		free(stack_b);
	}
}*/

/*... pa [Take the first element at the top of b and put it at the top of a]

... pb [Take the first element at the top of a and put it at the top of b.]

... ra [Shift up all elements of stack a by 1] 

... rb [Shift up all elements of stack b by 1]

... rr [ra and rb at the same time.]

... rra [Shift down all elements of stack a by 1.]

... rrb [Shift down all elements of stack b by 1.]

... rrr [rra and rrb at the same time.]
*/
