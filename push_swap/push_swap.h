/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:34:39 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/20 13:50:48 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

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
void	quicksort_a(t_stack **head_a, t_stack **head_b, int n_items);
void	quicksort_b(t_stack **head_a, t_stack **head_b, int n_items);
void	sort_three_a(t_stack **head_a);
void	sort_three_b(t_stack **head_b);

#endif
