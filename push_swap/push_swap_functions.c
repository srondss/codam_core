/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:39:15 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/06 12:26:41 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// [Swap the first 2 elements at the top of stack a]
void	sa(t_stack **head_ref)
{
	struct s_stack *first; 
	struct s_stack *second; 
	struct s_stack *third; 
	struct s_stack *last; 

	first = *head_ref;
	second = first->next;
	third = second->next;
	last= first->prev;
	
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	*head_ref = second;
}
// RUN IN TERMINAL: gc push_swap.c push_swap_functions.c libft/ft_*.c

//[Swap the first 2 elements at the top of stack b]
void	sb(t_stack **head_ref)
{
	struct s_stack *first = *head_ref;
	struct s_stack *second = first->next;
	struct s_stack *third = second->next;
	struct s_stack *last = first->prev;

	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;

	*head_ref = second;
}

//[sa and sb at the same time.]
void	ss(t_stack **head_stack_a, t_stack **head_stack_b)
{
	sa(head_stack_a);
	sb(head_stack_b);
}

//... pa [Take the first element at the top of b and put it at the top of a]
/*void	pa(t_stack *stack_a, t_stack *stack_b)
{
}*/

//... pb [Take the first element at the top of a and put it at the top of b.]
void	pb(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct	s_stack *first_a;
	struct	s_stack *second_a;
	struct	s_stack *last_a;
	struct	s_stack *last_b;
	
	first_a = *head_stack_a;
	second_a = first_a->next;
	last_a = first_a->prev;

	second_a->prev = last_a;
	last_a->next = second_a;

	*head_stack_a = second_a;
//	Case when stack_b is empty. 
	if (*(head_stack_b) == NULL)
	{
		*head_stack_b = malloc(sizeof(struct s_stack));
		(*(head_stack_b))->number = first_a->number;
		(*(head_stack_b))->next = *head_stack_b;
		(*(head_stack_b))->prev = *head_stack_b;
		free(first_a);
	}
//	Case when stack_b only has 1 node
	else if ((*(head_stack_b))->next == (*(head_stack_b)))
	{
		(*(head_stack_b))->next = first_a;
		(*(head_stack_b))->prev = first_a;
		first_a->next = *head_stack_b;
		first_a->prev = *head_stack_b;
		*head_stack_b = first_a;
	}
//	Every other case.
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
}

/*... ra [Shift up all elements of stack a by 1] 

... rb [Shift up all elements of stack b by 1]

... rr [ra and rb at the same time.]

... rra [Shift down all elements of stack a by 1.]

... rrb [Shift down all elements of stack b by 1.]

... rrr [rra and rrb at the same time.]
*/
