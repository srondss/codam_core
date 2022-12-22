/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:39:15 by ysrondy           #+#    #+#             */
/*   Updated: 2022/12/22 13:11:22 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// [Swap the first 2 elements at the top of stack a]
void	sa(int *array)
{
	int	tmp;

	if (array[1])
	{
		tmp = array[0];
		array[0] = array[1];
		array[1] = tmp;
	}
}

//[Swap the first 2 elements at the top of stack b]
void	sb(int *array)
{
	int	tmp;

	if (array[1])
	{
		tmp = array[0];
		array[0] = array[1];
		array[1] = tmp;
	}
}

//[sa and sb at the same time.]
void	ss(int *array)
{
	sa(array);
	sb(array);
}
// TODO: Fix this function. 
void	pa(int *stack_a, int *stack_b, int stack_a_length)
{
	int *tmp_array;

	tmp_array = malloc(sizeof(char) * stack_a_length + 1);
	if (!tmp_array)
		return ;
	tmp_array[0] = stack_b[0];
	ft_memcpy(tmp_array + 1, stack_a, stack_a_length);
	stack_a = tmp_array;
	free(tmp_array);
}

/*

... pa [Take the first element at the top of b and put it at the top of a]

... pb [Take the first element at the top of a and put it at the top of b.]

... ra [Shift up all elements of stack a by 1] 

... rb [Shift up all elements of stack b by 1]

... rr [ra and rb at the same time.]

... rra [Shift down all elements of stack a by 1.]

... rrb [Shift down all elements of stack b by 1.]

... rrr [rra and rrb at the same time.]
*/
