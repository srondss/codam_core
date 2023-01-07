/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:39:15 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/07 21:39:12 by ysrondy          ###   ########.fr       */
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
void	pa(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct	s_stack *first_b;
	struct	s_stack *second_b;
	struct	s_stack *last_b;
	struct	s_stack *last_a;
	
	if (*(head_stack_b) == NULL)
		return ;
	first_b = *head_stack_b;
	second_b = first_b->next;
	last_b = first_b->prev;

	second_b->prev = last_b;
	last_b->next = second_b;

	*head_stack_b = second_b;
//	case when stack_a is empty. 
	if (*(head_stack_a) == NULL)
	{
		*head_stack_a = malloc(sizeof(struct s_stack));
		(*(head_stack_a))->number = first_b->number;
		(*(head_stack_a))->next = *head_stack_a;
		(*(head_stack_a))->prev = *head_stack_a;
		free(first_b);
	}
//	case when stack_a only has 1 node
	else if ((*(head_stack_a))->next == (*(head_stack_a)))
	{
		(*(head_stack_a))->next = first_b;
		(*(head_stack_a))->prev = first_b;
		first_b->next = *head_stack_a;
		first_b->prev = *head_stack_a;
		*head_stack_a = first_b;
	}
//	every other case.
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
}

//... pb [Take the first element at the top of a and put it at the top of b.]
void	pb(t_stack **head_stack_a, t_stack **head_stack_b)
{
	struct	s_stack *first_a;
	struct	s_stack *second_a;
	struct	s_stack *last_a;
	struct	s_stack *last_b;
	
	if (*(head_stack_a) == NULL)
		return ;
	first_a = *head_stack_a;
	second_a = first_a->next;
	last_a = first_a->prev;

	second_a->prev = last_a;
	last_a->next = second_a;

	*head_stack_a = second_a;
//	case when stack_b is empty. 
	if (*(head_stack_b) == NULL)
	{
		*head_stack_b = malloc(sizeof(struct s_stack));
		(*(head_stack_b))->number = first_a->number;
		(*(head_stack_b))->next = *head_stack_b;
		(*(head_stack_b))->prev = *head_stack_b;
		free(first_a);
	}
//	case when stack_b only has 1 node
	else if ((*(head_stack_b))->next == (*(head_stack_b)))
	{
		(*(head_stack_b))->next = first_a;
		(*(head_stack_b))->prev = first_a;
		first_a->next = *head_stack_b;
		first_a->prev = *head_stack_b;
		*head_stack_b = first_a;
	}
//	every other case.
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

//... ra [Shift up all elements of stack a by 1] 
void	ra(t_stack **head_stack_a)
{
	if (*(head_stack_a) == NULL)
		return ;
	*head_stack_a = (*(head_stack_a))->next;
}
//... rb [Shift up all elements of stack b by 1]
void	rb(t_stack **head_stack_b)
{
	if (*(head_stack_b) == NULL)
		return ;
	*head_stack_b = (*(head_stack_b))->next;
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
}
//... rrb [Shift down all elements of stack b by 1.]
void	rrb(t_stack **head_stack_b)
{
	if (*(head_stack_b) == NULL)
		return ;
	*head_stack_b = (*(head_stack_b))->prev;
}
//... rrr [rra and rrb at the same time.]
void	rrr(t_stack **head_stack_a, t_stack **head_stack_b)
{
	rra(head_stack_a);
	rrb(head_stack_b);
}
