/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:34:39 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/06 10:39:27 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int	number;
	struct	s_stack *next;
	struct	s_stack *prev;
}	t_stack;

void	sa(t_stack **head_ref);
void	sb(t_stack **head_ref);
void	ss(t_stack **head_stack_a, t_stack **head_stack_b);
void	pb(t_stack **head_stack_a, t_stack **head_stack_b);
