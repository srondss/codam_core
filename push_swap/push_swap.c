/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/05 11:17:15 by ysrondy          ###   ########.fr       */
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
		printf("Error: 2 numbers or less in stack");
		exit(0);
	}
	i = 3;
	start_node = stack_a;
	next_node = malloc(sizeof(struct s_stack));
	start_node = stack_a;
	start_node->number = ft_atoi(string[1]);
	start_node->next = next_node;
	next_node->number = ft_atoi(string[2]);
	next_node->prev = start_node;
	
	while (string[i])
	{
		new_node = malloc(sizeof(struct s_stack));
		new_node->prev = next_node;
		next_node->next = new_node;
		next_node = next_node->next;
		new_node->number = ft_atoi(string[i]);
		i++;
	}
	new_node->next = start_node;
	start_node->prev = new_node;
}

int print_stack(t_stack *stack, char delimiter)
{
	int i;
	struct s_stack *start_node;
	
	start_node = stack->next;
	i = 1;
	printf("Number: %d\n", stack->number);
	printf("Prev Node: %p\n", stack->prev);
	printf("Curr Node: %p\n", stack);
	printf("Next Node: %p\n", stack->next);
	while (start_node != stack)
	{
	//	printf("Stack: %p\n", stack);
	//	printf("Start_node: %p\n", start_node);
		printf("Number: %d\n", start_node->number);
		printf("Prev Node: %p\n", start_node->prev);
		printf("Curr Node: %p\n", start_node);
		printf("Next Node: %p\n", start_node->next);
		start_node = start_node->next;
		i++;
	}
	if (delimiter == 'a')
		printf("\n-\na\n\n");
	else
		printf("\n-\nb\n\n");
	return (i);
}

void	free_stack(t_stack *stack)
{
	struct s_stack *last_node;

	last_node = stack->prev;
	while (stack != last_node)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}

int main_1(int argc, char **argv)
{
	struct	s_stack	*stack_a;

	if (argc == 1)
	{
		printf("Error - Too few arguments");
		return (1);
	}
	stack_a = malloc(sizeof(struct s_stack) * argc - 1);

	fill_stack(stack_a, argv, argc);

	print_stack(stack_a, 'a');
	
	sa(&stack_a);
	
	print_stack(stack_a, 'a');
	
	free_stack(stack_a);
	return (0);
}

int main(int argc, char **argv)
{
	main_1(argc, argv);
	system("leaks -q a.out");
}
