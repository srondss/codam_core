/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:38:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/01/02 21:31:37 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack_a, char **string)
{
	struct s_stack *node;
/* Okay, so essentially, what i need here is to run a loop. At this point, I can assume
that there are at least 2 integers in my stack. Hence, I will malloc 2 nodes. I will set
begin_node->number to argv[1] and next_node->number to argv[2]. Then I will set next_node->prev = begin_node and
begin_node->next to next_node. So at this point, they both point at each other. Then I start my loop which keeps on going
as long as there is something in my argv. Everytime the loop executes, it mallocs new node. New_node will set 
new_node->prev = next_node, and next_node will set next_node->next = new_node. Then next_node = next_node->next, hence it becomes the 
new node. After that, New_node->number = argv[i]. Then loop starts over. At the end of the loop, we can assume that there 
is nothing left in the string, so all numbers have been attached, however new_node still exists without a next node. So,
we must set new_node->next = begin_node.

and... voila! A circular double-linked list. 

Dev Diary: Linked lists are really cool! I learnt today how to create a double-linked list. 
*/
}

/*int print_array(int *array)
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
}*/

int main(int argc, char **argv)
{
	struct	s_stack	*stack_a;
	struct	s_stack	*stack_b;

	stack_a = malloc(sizeof(struct s_stack) * argc - 1);
	stack_b = malloc(sizeof(struct s_stack) * argc - 1);

	fill_stack(stack_a, argv);

	free(stack_a);
	free(stack_b);
	return (0);
}
