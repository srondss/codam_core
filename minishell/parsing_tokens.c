/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 07:51:57 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/11 07:51:58 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Returns true if the char is a whitespace and false if it is not.
*/
int	is_whitespace(char c)
{
	if (c == '\f' || c == ' ' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (TRUE);
	else
		return (FALSE);
}

/*
	Returns the type of the character.
*/
int	find_token_type(char c)
{
	if (c == '|')
		return (PIPE);
	if (c == '<')
		return (LESS);
	if (c == '>')
		return (GREATER);
	return (LITERAL);
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
	Loops through string and skips char if it is a whitespace.
	Otherwise, will malloc a node, initialise it, and add it to the
	end of the linked_list.
*/
void	parse_input(char *string, t_token **tokens_head)
{
	int		i;
	int		j;
	t_token	*node;

	i = 0;
	j = 0;
	while (string[i] != '\0')
	{
		if (is_whitespace(string[i]) == TRUE)
			i++;
		else
		{
			node = malloc(sizeof(t_token) * 1);
			if (!node)
				exit(EXIT_FAILURE);
			node->token = string[i];
			node->type = find_token_type(string[i]);
			node->cmd = NULL;
			node->index = j;
			node->next = NULL;
			add_node_back(tokens_head, node);
			j++;
			i++;
		}
	}
}
