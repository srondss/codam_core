/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:09:20 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/18 08:09:21 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *string)
{
	if (ft_strncmp(string, "cd", 2) == 0)
		return (TRUE);
	if (ft_strncmp(string, "echo", 4) == 0)
		return (TRUE);
	if (ft_strncmp(string, "env", 3) == 0)
		return (TRUE);
	if (ft_strncmp(string, "exit", 4) == 0)
		return (TRUE);
	if (ft_strncmp(string, "export", 6) == 0)
		return (TRUE);
	if (ft_strncmp(string, "pwd", 3) == 0)
		return (TRUE);
	if (ft_strncmp(string, "unset", 5) == 0)
		return (TRUE);
	return (FALSE);
}

void	create_cmd(t_token *start_node, t_token *target_node, t_commands **cmd_head, int num_nodes)
{
	t_commands	*node_cmds;
	int			i;

	i = 0;

	node_cmds = malloc(sizeof(t_commands));
	if (!node_cmds)
		exit(EXIT_FAILURE);
	node_cmds->cmds = malloc(sizeof(char *) * num_nodes);
	if (!node_cmds->cmds)
		exit(EXIT_FAILURE);

	node_cmds->builtin = 0;
	node_cmds->redirections = NULL;
	while (start_node != target_node)
	{
		node_cmds->cmds[i] = start_node->cmd;
		if (start_node->type == GREATER)
			node_cmds->redirections = start_node->next;
		if (is_builtin(start_node->cmd))
			node_cmds->builtin = 1; // temporary
		i++;
		start_node = start_node->next;
	}
	node_cmds->cmds[i] = NULL;
	node_cmds->next = NULL;
	add_node_back_cmds(cmd_head, node_cmds);
}

void	parse_cmds(t_token **tokens_head, t_commands **cmd_head)
{
	t_token		*node_token;
	t_token		*start_node;
	int			num_nodes;

	num_nodes = 0;
	start_node = *tokens_head;
	node_token = *tokens_head;
	while (node_token->next != NULL)
	{
		num_nodes++;
		if (node_token->type == PIPE)
		{
			create_cmd(start_node, node_token, cmd_head, num_nodes);
			start_node = node_token->next;
			num_nodes = 0;
		}
		node_token = node_token->next;
	}
	num_nodes += 2;
	if (node_token->type == LITERAL)
		create_cmd(start_node, node_token->next, cmd_head, num_nodes);
}
