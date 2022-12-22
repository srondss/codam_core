/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2022/12/22 13:10:29 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// This function populates "array" with all input values as digits.
int 	*fill_function(int argc, char **argv)
{
	int i;
	int *array;

	i = 0;
	array = malloc(sizeof(int) * argc);
	if (!array)
		return (NULL);
	while (i < argc) 
	{
		array[i] = ft_atoi(argv[(i + 1)]);
		if (array[i] < 0)
		{
			printf("Error\n");
			return (free(array), NULL);
		}
		i++;
	}
	return (array);
}

int print_array(int *array)
{
	int i;
	
	i = 0;
	while (array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}
	if (array)
		printf("\n-\n\n");
	return (i);
}

int main(int argc, char **argv)
{
	int *stack_a;
	int stack_b[1];
	int length;

	stack_a = fill_function((argc - 1), argv);
	stack_b[0] = 5;
	length = print_array(stack_a);
	pa(stack_a, stack_b, length);
	length = print_array(stack_a);

	return (0);
}
