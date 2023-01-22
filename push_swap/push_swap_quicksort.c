/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 06:44:25 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/22 20:29:21 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_arr(int *arr, int size_arr)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size_arr)
	{
		while (j < (size_arr - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (arr);
}

int	get_pivot(t_stack **head, t_stack **head_other, int n_items)
{
	int				i;
	int				*arr;
	struct s_stack	*first;
	int				result;

	i = 0;
	arr = (int *)malloc(sizeof(int) * n_items);
	first = *head;
	if (!arr)
		free_and_exit(head, head_other);
	while (i < n_items)
	{
		arr[i] = first->number;
		first = first->next;
		i++;
	}
	arr = sort_arr(arr, n_items);
	i = (n_items / 2);
	if (n_items % 2 == 0)
		result = arr[i - 1];
	else
		result = arr[i];
	free(arr);
	return (result);
}

int	check_sorted_desc(t_stack **head)
{
	struct s_stack	*node;

	node = *head;
	if (!node)
		return (1);
	while (node->number > node->next->number)
		node = node->next;
	if (node->next == *head)
		return (1);
	else
		return (0);
}

void	quicksort_a(t_stack **head_a, t_stack **head_b, int n_items)
{
	struct s_stack	*start;
	int				pivot;
	int				pushed_numbers;
	int				i;

	start = *(head_a);
	if (check_sorted(head_a) == 1 || n_items == 0 || n_items == 1)
		return ;
	else if (n_items == 2)
	{
		if (start->number > start->next->number)
			sa(head_a);
		return ;
	}
	else if (n_items == 3)
		sort_three_a(head_a);
	else
	{
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
		quicksort_a(head_a, head_b, (n_items - pushed_numbers));
		quicksort_b(head_a, head_b, pushed_numbers);
	}
}

void	quicksort_b(t_stack **head_a, t_stack **head_b, int n_items)
{
	struct s_stack	*start;
	int				pivot;
	int				pushed_numbers;
	int				i;

	start = *(head_b);
	if (check_sorted_desc(head_b) == 1)
	{
		while ((*head_b) != NULL)
			pa(head_a, head_b);
	}
	else if (n_items == 0)
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
	else
	{
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
		quicksort_a(head_a, head_b, pushed_numbers);
		quicksort_b(head_a, head_b, (n_items - pushed_numbers));
	}
}
