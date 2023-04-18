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
	Prints contents of t_token linked_list.
*/
void	print_token_list(t_token **lst_head)
{
	t_token	*node;

	node = *lst_head;
	while (node)
	{
		printf("Lexer: {%s} | Type: {%d} | Index: {%d}\n", node->cmd, node->type, node->index);
		node = node->next;
	}
}

/*
	Prints contents of t_commands linked_list.
*/
void	print_cmds_list(t_commands **lst_head)
{
	t_commands	*node;
	int i;

	i = 0;
	node = *lst_head;
	while (node)
	{
		while (node->cmds[i] != NULL)
		{
			printf("Cmds: {%s}\n", node->cmds[i]);
			i++;
		}
		if (node->redirections)
			printf("Redirection: {%s}\n", node->redirections->cmd);
		else
			printf("Redirection: {%p}.\n", node->redirections);
		printf("Builtin: {%d}\n", node->builtin);
		node = node->next;
		i = 0;
	}
}

/*
	Returns the last node of the t_token linked list.
*/
t_token	*last_node_token(t_token **lst_head)
{
	t_token	*last;

	last = *lst_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

/*
	Returns the last node of the t_cmds linked list.
*/
t_commands	*last_node_cmds(t_commands **lst_head)
{
	t_commands	*last;

	last = *lst_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

/*
	Adds node to the back of the linked list.
*/
void	add_node_back_token(t_token **lst_head, t_token *node)
{
	t_token	*tmp;

	if (lst_head && node)
	{
		if (*lst_head == NULL)
			*lst_head = node;
		else
		{
			tmp = last_node_token(lst_head);
			tmp->next = node;
		}
	}
}

/*
	Adds node to the back of the linked list.
*/
void	add_node_back_cmds(t_commands **lst_head, t_commands *node)
{
	t_commands	*tmp;

	if (lst_head && node)
	{
		if (*lst_head == NULL)
			*lst_head = node;
		else
		{
			tmp = last_node_cmds(lst_head);
			tmp->next = node;
		}
	}
}

/*
	Creates a t_token node inside the t_token linked list.
*/
void	create_node(t_token **tokens_head, char *string, int start, int len)
{
	t_token		*node;
	static int	i = 0;

	node = malloc(sizeof(t_token) * 1);
	if (!node)
		exit(EXIT_FAILURE);
	// printf("Start Pos: %d, Len %d\n", start, (len - start));
	node->cmd = ft_substr(string, start, (len - start));
	// printf("Created: %s\n", node->cmd);
	node->type = find_token_type(string[start]);
	node->index = i;
	i++;
	node->next = NULL;
	add_node_back_token(tokens_head, node);
}
