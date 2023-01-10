/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/10 21:54:09 by ysrondy          ###   ########.fr       */
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
	
	if (argc == 1)
		return (printf("Error - Too few arguments"));
	else if (argc == 2)
		return (1);
	else if (argc == 3)
	{
		if (ft_atoi(argv[1]) < ft_atoi(argv[2]))
			return (printf("Sorted."));
		else
			return (printf("sa\n"));
	}
	stack_a = malloc(sizeof(struct s_stack) * argc - 1);
	if (!stack_a)
		return (1);
	stack_b = NULL;

	fill_stack(stack_a, argv, argc);
	
	print_stack(&stack_a, 'a');
	print_stack(&stack_b, 'b');
	
//	Begin algorithm.
	while (stack_a)
	{
		struct s_stack *head_b;
		int		i;
		
	// if stack b is empty, just push a to b.
		if (!stack_b)
			pb(&stack_a, &stack_b);
	// if top stack a is bigger than top stack b, just push to stack b.
		else if (stack_a->number > stack_b->number)
			pb(&stack_a, &stack_b);
		else
		{
			i = 0;
			head_b = stack_b;
	// while top of stack a is bigger than stack b, increment i and then go to next node in stack b.
			while (stack_a->number < head_b->number)
			{
	//		if there's only 1 node in stack b, then just push a to b and swap both.
				if (stack_b->prev == stack_b->next && stack_b->next->number == stack_b->number)
				{
					pb(&stack_a, &stack_b);
					sb(&stack_b);
					break;
				}
				head_b = head_b->next;
	//		if you went through all the nodes, increment + break;
				if (head_b == stack_b)
				{
					i++;
					break;
				}
				i++;
			}
	//		if stack b has more than 1 node but only 1 number is bigger than top of stack a
	//		the just push a to b and swap.
			if (i == 1)
			{
				pb(&stack_a, &stack_b);
				sb(&stack_b);
			}
			else if (i > 1)
			{
	//		while there are i numbers bigger than top of stack a, push b to a and rotate so 
	//		top of stack a is still the same initial number.
				while (i > 0)
				{
					pa(&stack_a, &stack_b);
					ra(&stack_a);
					i--;
				}
	//		when you've pushed everything back to a, push a to b so the initial number is now at top of stack b.
				pb(&stack_a, &stack_b);
			}
		}
//debugging	print_stack(&stack_a, 'a');
//debugging	print_stack(&stack_b, 'b');
	}
	// push everything back to stack a since it's sorted.
	while (stack_b)
		pa(&stack_a, &stack_b);
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
