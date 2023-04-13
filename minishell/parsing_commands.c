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
	Function that creates the char *cmd inside the t_token struct by mallocing
	a string size 'i', looping through the linked list and checking if it can
	copy the char token into the command by verifying whether non_literals is
	equal to 0. Non_literals will be 0 either if there are no pipes and redirections
	in the linked_list or if we have passed by all previous pipes and redirections
	which means we are at the first node that needs to be copied.
*/
void	create_string(t_token **head_list, t_token *node_token,
			int i, int non_literals)
{
	char	*command;
	t_token	*node;
	int		pos;

	pos = 0;
	node = *head_list;
	command = malloc(sizeof(char) * i);
	if (!command)
		exit(EXIT_FAILURE);
	while (node != node_token)
	{
		if (non_literals == 0)
		{
			command[pos] = node->token;
			pos++;
			if (node->next == node_token)
			{
				command[pos] = '\0';
				node->cmd = command;
			}
		}
		if (node->type != LITERAL)
			non_literals--;
		node = node->next;
	}
}

/*
	Function that calls the create_string function either if we are the end of the
	list, or if the current node has pipes or redirections (i.e is not type LITERAL).
	Sends the number of non_literals we've passed by the time we've reached the current
	non_literal and also sends i + 1 bytes to be malloced to account for '\0' or i + 2 to
	account for sending the create string 1 node early + '\0'.
*/
void	join_tokens(t_token **head_list)
{
	t_token	*node;
	int		i;
	int		non_literals;

	i = 0;
	non_literals = 0;
	node = *head_list;
	while (node)
	{
		if (node->next == NULL)
			create_string(head_list, NULL, i + 2, non_literals);
		if (node->type == LITERAL)
			i++;
		if (node->type != LITERAL)
		{
			create_string(head_list, node, i + 1, non_literals);
			non_literals++;
			i = 0;
		}
		node = node->next;
	}
}
