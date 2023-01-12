/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/12 22:08:51 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack_a, char **string, int argc)
{
	struct	s_stack *start_node;
	struct	s_stack *next_node;
	struct	s_stack *new_node;
	int i;

	if (argc <= 3)
	{
		printf("Error: 2 numbers or less in stack\n");
		exit(EXIT_SUCCESS);
	}
	i = 3;
	start_node = stack_a;
	next_node = malloc(sizeof(struct s_stack));
	if (!next_node)
		return (free(start_node));
	start_node = stack_a;
	start_node->number = ft_atoi(string[1]);
	start_node->next = next_node;
	next_node->number = ft_atoi(string[2]);
	next_node->prev = start_node;
	while (string[i])
	{
		new_node = malloc(sizeof(struct s_stack));
		if (!new_node)
			return (free_stack(&stack_a));
		new_node->prev = next_node;
		next_node->next = new_node;
		next_node = next_node->next;
		new_node->number = ft_atoi(string[i]);
		i++;
	}
	new_node->next = start_node;
	start_node->prev = new_node;
}

int print_stack(t_stack **head_stack, char delimiter)
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
}

void	free_stack(t_stack **head_stack)
{
	struct	s_stack *first_node;
	struct	s_stack *last_node;
	struct	s_stack *next_node;

	first_node = *head_stack;
	if (!first_node)
		return ;
	last_node = first_node->prev;
	next_node = first_node->next;
	if (first_node->next == first_node)
		return (free(first_node));
	while (next_node != last_node)
	{
		next_node = next_node->next;
		free(next_node->prev);
	}
	free(last_node);
	free(first_node);
}

int main_1(int argc, char **argv)
{
	struct	s_stack	*stack_a;
	struct	s_stack *stack_b;
	
	if (check_string(argc, argv) == 1)
		return (printf("Error\n"));
	if (argc == 1)
		return (1);
	else if (argc == 2)
		return (1);
	else if (argc == 3)
	{
		if (ft_atoi(argv[1]) < ft_atoi(argv[2]))
			return (0);
		else
			return (printf("sa\n"));
	}
	stack_a = malloc(sizeof(struct s_stack) * argc - 1);
	if (!stack_a)
		return (1);
	stack_b = NULL;

	fill_stack(stack_a, argv, argc);
	if (check_duplicate(&stack_a) == 1)
	{
		free_stack(&stack_a);
		return (printf("Error\n"));
	}
//	print_stack(&stack_a, 'a');
//	print_stack(&stack_b, 'b');
	
//	Begin algorithm.
	call_algorithm(&stack_a, &stack_b);
//	End algorithm.
	
	print_stack(&stack_a, 'a');
	print_stack(&stack_b, 'b');
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int main(int argc, char **argv)
{
	main_1(argc, argv);
//	system("leaks -q a.out");
}
