/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort_helpers_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:03:52 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/26 09:04:44 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_b_helper3(t_stack **head_b, int i, int pushed_numbers)
{
	while ((i - pushed_numbers) > 0)
	{
		rrb(head_b);
		i--;
	}
}

void	quicksort_a_helper3(t_stack **head_a, int i, int pushed_numbers)
{
	while ((i - pushed_numbers) > 0)
	{
		rra(head_a);
		i--;
	}
}
