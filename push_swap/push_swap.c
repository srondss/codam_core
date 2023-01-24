/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/24 12:10:52 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int print_stack(t_stack **head_stack, char delimiter)
{
	int i;
	struct	s_stack *start_node;
	struct	s_stack *next_node;

	start_node = *head_stack;
	if (!start_node)
	{
		printf("Tried printing Stack %c, it doesn't exist\n\n", delimiter);
		return (0);
	}
	next_node = start_node->next;
	i = 1;
	printf("Number: %d\n", start_node->number);
	printf("Prev Node: %p\n", start_node->prev);
	printf("Curr Node: %p\n", start_node);
	printf("Next Node: %p\n", start_node->next);
	while (next_node != start_node)
	{
		printf("Number: %d\n", next_node->number);
		printf("Prev Node: %p\n", next_node->prev);
		printf("Curr Node: %p\n", next_node);
		printf("Next Node: %p\n", next_node->next);
		next_node = next_node->next;
		i++;
	}
	if (delimiter == 'a')
		printf("\n-\na\n\n");
	else
		printf("\n-\nb\n\n");
	return (i);
}*/

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	if (check_string(argc, argv) == 1 || argc == 1 || argc == 2 || argc == 3)
		check_errors(argc, argv);
	stack_a = malloc(sizeof(struct s_stack) * argc - 1);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	fill_stack(stack_a, argv);
	if (check_duplicate(&stack_a) == 1)
	{
		free_stack(&stack_a);
		return (write(2, "Error\n", 6));
	}
	quicksort_a(&stack_a, &stack_b, (argc - 1));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
