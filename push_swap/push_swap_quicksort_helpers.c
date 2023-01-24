/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort_helpers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:09:00 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/24 11:11:23 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quicksort_a_helper(t_stack **head_a, t_stack **head_b, int n_items)
{
	int	pivot;
	int	i;
	int	pushed_numbers;

	pivot = get_pivot(head_a, head_b, n_items);
	i = 0;
	pushed_numbers = 0;
	while (i < n_items)
	{
		if ((*(head_a))->number <= pivot)
		{
			pb(head_a, head_b);
			pushed_numbers++;
		}
		else if ((*(head_a))->next != (*(head_a)))
			ra(head_a);
		i++;
	}
	while ((i - pushed_numbers) > 0)
	{
		rra(head_a);
		i--;
	}
	return (pushed_numbers);
}

int	quicksort_b_helper(t_stack **head_a, t_stack **head_b, int n_items)
{
	int	pivot;
	int	i;
	int	pushed_numbers;

	pivot = get_pivot(head_b, head_a, n_items);
	i = 0;
	pushed_numbers = 0;
	while (i < n_items)
	{
		if ((*(head_b))->number > pivot)
		{
			pa(head_a, head_b);
			pushed_numbers++;
		}
		else if ((*(head_b))->next != (*(head_b)))
			rb(head_b);
		i++;
	}
	while ((i - pushed_numbers) > 0)
	{
		rrb(head_b);
		i--;
	}
	return (pushed_numbers);
}

void	quicksort_b_helper2(t_stack **head_a, t_stack **head_b, int n_items,
t_stack *start)
{
	if (n_items == 0)
		return ;
	else if (n_items == 1)
		pa(head_a, head_b);
	else if (n_items == 2)
	{
		if (start->number < start->next->number)
			sb(head_b);
		pa(head_a, head_b);
		pa(head_a, head_b);
	}
	else if (n_items == 3)
	{
		sort_three_b(head_b);
		pa(head_a, head_b);
		pa(head_a, head_b);
		pa(head_a, head_b);
	}
}
