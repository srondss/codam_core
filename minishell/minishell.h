/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:38:17 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/10 10:38:18 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "libft/libft.h"

# define FALSE 0
# define TRUE 1

/*
	An enum to easily identify the type of the token.
*/
typedef enum s_type
{
	LITERAL = 1,
	PIPE = 2,
	LESS = 3,
	GREATER = 4,
}	t_type;

/*
	A token is part of a linked list which refers to every single
	character inputted by the user.
*/
typedef struct s_token
{
	char			*cmd;
	t_type			type;
	struct s_token	*next;
}				t_token;

typedef struct s_commands
{
	char				**cmd;
	// int					(*builtin);
	t_token				*redirections;
	char				*hd_file_name;
	struct s_commands	*next;
}				t_commands;

				/* Parsing Tokens */
int		is_whitespace(char c);
int		find_token_type(char c);
void	parse_input(char *string, t_token **tokens_head);


				/* Linked_List Functions */
t_token	*last_node(t_token **lst_head);
void	add_node_back(t_token **lst_head, t_token *node);
void	create_node(t_token **tokens_head, char *string, int start, int j);
void	print_list(t_token **lst_head);

				/* Utils */
void	check_leaks(void);

#endif
