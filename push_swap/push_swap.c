/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/07 19:56:58 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	free_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	copy_into_argv(char **src, char **dst)
{
	int	i;

	i = 0;
	dst[0] = "./push_swap";
	while (src[i] != NULL)
	{
		dst[i + 1] = src[i];
		i++;
	}
	dst[i + 1] = NULL;
}

int	get_length_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	run_algo(int argc, char **argv, int flag)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	check_errors(argc, argv, flag);
	stack_a = malloc(sizeof(struct s_stack) * argc - 1);
	if (!stack_a && flag)
		return (write(2, "Error\n", 6), free_argv(argv), exit(EXIT_SUCCESS));
	else if (!stack_a)
		return (write(2, "Error\n", 6), exit(EXIT_SUCCESS));
	stack_b = NULL;
	fill_stack(stack_a, argv);
	if (flag == 1)
		free_argv(argv);
	if (check_duplicate(&stack_a) == 1)
	{
		free_stack(&stack_a);
		return (write(2, "Error\n", 6), exit(EXIT_SUCCESS));
	}
	quicksort_a(&stack_a, &stack_b, (argc - 1));
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	char			**new_argv;
	int				flag;

	flag = 0;
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return (write(2, "Error\n", 6), 1);
		new_argv = ft_split(argv[1], ' ');
		if (!new_argv)
			return (write(2, "Error\n", 6), 1);
		argc = ((get_length_argv(new_argv)) + 1);
		argv = malloc(sizeof(char *) * argc + 1);
		if (!argv)
			return (write(2, "Error\n", 6), free(new_argv[0]),
				free_argv(new_argv), 1);
		copy_into_argv(new_argv, argv);
		flag = 1;
		free(new_argv);
	}
	run_algo(argc, argv, flag);
	return (0);
}
