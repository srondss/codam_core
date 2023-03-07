/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:00:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/07 16:18:26 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_support(char **string, t_stack *next_node,
t_stack *start_node)
{
	struct s_stack	*new_node;
	int				i;

	i = 3;
	while (string[i])
	{
		new_node = malloc(sizeof(struct s_stack));
		if (!new_node)
		{
			free_argv(string);
			free_stack(&start_node);
			write(2, "Error\n", 6);
			exit(EXIT_SUCCESS);
		}
		new_node->prev = next_node;
		next_node->next = new_node;
		next_node = next_node->next;
		new_node->number = ft_atol(string[i]);
		i++;
	}
	new_node->next = start_node;
	start_node->prev = new_node;
}

void	fill_stack(t_stack *stack_a, char **string)
{
	struct s_stack	*start_node;
	struct s_stack	*next_node;

	start_node = stack_a;
	next_node = malloc(sizeof(struct s_stack));
	if (!next_node)
	{
		free_argv(string);
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
	start_node = stack_a;
	start_node->number = ft_atol(string[1]);
	start_node->next = next_node;
	next_node->number = ft_atol(string[2]);
	next_node->prev = start_node;
	fill_stack_support(string, next_node, start_node);
}

void	free_stack(t_stack **head_stack)
{
	struct s_stack	*first_node;
	struct s_stack	*last_node;
	struct s_stack	*next_node;

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

void	free_and_exit(t_stack **head_a, t_stack **head_b)
{
	free_stack(head_a);
	free_stack(head_b);
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	check_errors_helper(char **argv, int flag)
{
	if (ft_atol(argv[1]) < ft_atol(argv[2]))
	{
		if (flag == 1)
			free_argv(argv);
		exit(EXIT_SUCCESS);
	}
	else if (ft_atol(argv[1]) == ft_atol(argv[2]))
	{
		write(2, "Error\n", 6);
		if (flag == 1)
			free_argv(argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(1, "sa\n", 3);
		if (flag == 1)
			free_argv(argv);
		exit(EXIT_SUCCESS);
	}
}
