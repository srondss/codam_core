/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:34:39 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/07 16:18:38 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	free_stack(t_stack **head_ref);
void	sa(t_stack **head_ref);
void	sb(t_stack **head_ref);
void	ss(t_stack **head_stack_a, t_stack **head_stack_b);
t_stack	*pa(t_stack **head_stack_a, t_stack **head_stack_b);
t_stack	*pb(t_stack **head_stack_a, t_stack **head_stack_b);
void	ra(t_stack **head_stack_a);
void	rb(t_stack **head_stack_b);
void	rr(t_stack **head_stack_a, t_stack **head_stack_b);
void	rra(t_stack **head_stack_a);
void	rrb(t_stack **head_stack_b);
void	rrr(t_stack **head_stack_a, t_stack **head_stack_b);
void	call_algorithm(t_stack **stack_a, t_stack **stack_b);
int		check_string(int argc, char **argv);
int		check_duplicate(t_stack **head_a);
void	fill_stack(t_stack *stack_a, char **argv);
void	free_stack(t_stack **stack);
int		check_sorted(t_stack **stack);
int		check_sorted_desc(t_stack **stack);
void	quicksort_a(t_stack **head_a, t_stack **head_b, int n_items);
void	quicksort_b(t_stack **head_a, t_stack **head_b, int n_items);
void	sort_three_a(t_stack **head_a);
void	sort_three_b(t_stack **head_b);
void	free_and_exit(t_stack **head_a, t_stack **head_b);
void	pa_helper(t_stack **head_a, t_stack **head_b, t_stack *first_b);
void	pb_helper(t_stack **head_a, t_stack **head_b, t_stack *first_a);
void	pa_helper2(t_stack **head_a, t_stack **head_b,
			t_stack *first_b, t_stack *second_b);
void	pb_helper2(t_stack **head_a, t_stack **head_b,
			t_stack *first_a, t_stack *second_a);
void	quicksort_b_helper2(t_stack **head_a, t_stack **head_b, int n_items,
			t_stack *start);
int		quicksort_b_helper(t_stack **head_a, t_stack **head_b, int n_items);
int		quicksort_a_helper(t_stack **head_a, t_stack **head_b, int n_items);
int		get_pivot(t_stack **head, t_stack **head_other, int n_items);
int		*sort_arr(int *arr, int size_arr);
void	sort_three_b_helper3(t_stack **head_b, t_stack *node);
void	sort_three_b_helper2(t_stack **head_b);
void	sort_three_b_helper(t_stack **head_b, t_stack *node);
void	sort_three_a_helper3(t_stack **head_b, t_stack *node);
void	sort_three_a_helper2(t_stack **head_b);
void	sort_three_a_helper(t_stack **head_b, t_stack *node);
void	check_errors(int argc, char **argv, int flag);
void	check_errors_helper(char **argv, int flag);
void	quicksort_b_helper3(t_stack **head_b, int i, int pushed_numbers);
void	quicksort_a_helper3(t_stack **head_a, int i, int pushed_numbers);
long	ft_atol(const char *nptr);
void	free_argv(char **argv);

#endif
