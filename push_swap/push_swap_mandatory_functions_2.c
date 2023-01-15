/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:51:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/15 17:53:04 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//... rb [Shift up all elements of stack b by 1]
void	rb(t_stack **head_stack_b)
{
	if (*(head_stack_b) == NULL)
		return ;
	*head_stack_b = (*(head_stack_b))->next;
	printf("rb\n");
}

//... rr [ra and rb at the same time.]
void	rr(t_stack **head_stack_a, t_stack **head_stack_b)
{
	ra(head_stack_a);
	rb(head_stack_b);
}

//... rra [Shift down all elements of stack a by 1.]
void	rra(t_stack **head_stack_a)
{
	if (*(head_stack_a) == NULL)
		return ;
	*head_stack_a = (*(head_stack_a))->prev;
	printf("rra\n");
}

//... rrb [Shift down all elements of stack b by 1.]
void	rrb(t_stack **head_stack_b)
{
	if (*(head_stack_b) == NULL)
		return ;
	*head_stack_b = (*(head_stack_b))->prev;
	printf("rrb\n");
}

//... rrr [rra and rrb at the same time.]
void	rrr(t_stack **head_stack_a, t_stack **head_stack_b)
{
	rra(head_stack_a);
	rrb(head_stack_b);
}
