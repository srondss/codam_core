/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 06:44:25 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/17 09:04:05 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_stack **head_a, t_stack **head_b, int n_items)
{

	struct s_stack 	*start;
	int	pivot;
	int	pushed_numbers;
	int	i;

	start = *(head_a);

	if (check_sorted(head_a) == 1 || n_items == 0 || n_items == 1)
		return ;
	else if (n_items == 2)
	{
		if (start->number > start->next->number)
			sa(head_a);
		return ;
	}
	else
	{
		pivot = // function which finds the pivot.
		i = 0;
		pushed_numbers = 0;
		while (i < n_items)
		{
			if (start->number <= pivot)
			{
				pb(&stack_a, &stack_b);
				pushed_numbers++;
			}
			else
				ra(&stack_a);
			i++;
		}
		quicksort_a(head_a, head_b, (n_items - pushed_numbers));
		quicksort_b(head_a, head_b, pushed_numbers);
	}
}

void	quicksort_b(t_stack **head_a, t_stack **head_b, int n_items)
{

	struct s_stack 	*start;
	int	pivot;
	int	pushed_numbers;
	int	i;

	start = *(head_b);

// need to create function which checks if sorted descending
	if (check_sorted_desc(head_b) == 1)
	{
		while (start != NULL)
			pa(&stack_a, &stack_b);
	}
	else if (n_items == 0)
		return ; 
	else if (n_items == 1)
		pa(&stack_a, &stack_b);
	else if (n_items == 2)
	{
		if (start->number < start->next->number)
			sb(head_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
	}
	else
	{
		pivot = // function which finds the pivot.
		i = 0;
		pushed_numbers = 0;
		while (i < n_items)
		{
			if (start->number > pivot)
			{
				pa(&stack_a, &stack_b);
				pushed_numbers++;
			}
			rb(&stack_b);
			i++;
		}
		quicksort_a(head_a, head_b, pushed_numbers);
		quicksort_b(head_a, head_b, (n_items - pushed_numbers);
	}
}

// need to create function which finds the pivot. 



