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
TODO: Figure out a way to group together the individual tokens of same type.

My first idea is to loop through each token node and if type == next node type, I basically
string join. The question is.. where to store this? Probably the best way is to store it both in cmds and token struct
as it seems like I will need it in two places.
*/

void	join_tokens(t_token **head_list)
{
	t_token *node;

	node = *head_list;
	//...
}
