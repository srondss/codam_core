/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:42:20 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/12 08:42:21 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Prints command and type of t_token linked_list.
*/
void	print_list(t_token **lst_head)
{
	t_token	*node;

	node = *lst_head;
	while (node)
	{
		printf("Lexer: {%s} | Type: {%d} \n", node->cmd, node->type);
		node = node->next;
	}
}

/*
	Returns the last node of the linked list.
*/
t_token	*last_node(t_token **lst_head)
{
	t_token	*last;

	last = *lst_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

/*
	Adds node to the back of the linked list.
*/
void	add_node_back(t_token **lst_head, t_token *node)
{
	t_token	*tmp;

	if (lst_head && node)
	{
		if (*lst_head == NULL)
			*lst_head = node;
		else
		{
			tmp = last_node(lst_head);
			tmp->next = node;
		}
	}
}

/*
	Creates a t_token node inside the t_token linked list.
*/
void	create_node(t_token **tokens_head, char *string, int start, int len)
{
	t_token	*node;

	node = malloc(sizeof(t_token) * 1);
	if (!node)
		exit(EXIT_FAILURE);
	// printf("Start Pos: %d, Len %d\n", start, (len - start));
	node->cmd = ft_substr(string, start, (len - start));
	// printf("Created: %s\n", node->cmd);
	node->type = find_token_type(string[start]);
	node->next = NULL;
	add_node_back(tokens_head, node);
}
