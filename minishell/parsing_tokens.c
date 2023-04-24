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
int	find_token_type(char c, char c_next)
{
	if (c == '|')
		return (PIPE);
	if (c == '<' && c_next == '<')
		return (HEREDOC);
	if (c == '>' && c_next == '>')
		return (A_REDIRECTION);
	if (c == '<')
		return (IN_FILE);
	if (c == '>')
		return (REDIRECTION);
	return (LITERAL);
}

int	skip_whitespaces(char *string)
{
	int	i;

	i = 0;
	while (is_whitespace(string[i]))
		i++;
	return (i);
}

/*
	Loops through string and creates t_token nodes delimited by a whitespace or the end of the string.
*/
void	parse_input(char *string, t_token **tokens_head)
{
	int		i;
	int		start;
	int		len;

	i = skip_whitespaces(string);
	len = skip_whitespaces(string);
	start = i;
	while (string[i] != '\0')
	{
		if ((is_whitespace(string[i]) == TRUE \
			&& is_whitespace(string[i - 1]) == FALSE) \
			|| (string[i + 1] == '\0' && is_whitespace(string[i]) == FALSE))
		{
			if (string[i + 1] == '\0')
				len++;
			create_node(tokens_head, string, start, len);
			start = i + 1;
		}
		if (is_whitespace(string[start]))
			start++;
		len++;
		i++;
	}
}
