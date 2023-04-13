/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:07:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/13 09:07:22 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_leaks(void)
{
	system("leaks -q minishell");
}

void	print_list(t_token **lst_head)
{
	t_token	*node;

	node = *lst_head;
	while (node)
	{
		printf("Node #%d.| Char %c | Type %d | Cmd %s |.\n", node->index, node->token, node->type, node->cmd);
		node = node->next;
	}
}

