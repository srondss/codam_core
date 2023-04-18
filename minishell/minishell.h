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
	int				index;
	t_type			type;
	struct s_token	*next;
}				t_token;

typedef struct s_commands
{
	char				**cmds;
	int					builtin;
	t_token				*redirections;
	char				*hd_file_name;
	struct s_commands	*next;
}				t_commands;

				/* Parsing Tokens */
int		is_whitespace(char c);
int		find_token_type(char c);
void	parse_input(char *string, t_token **tokens_head);

				/* Parsing Commands */
void	parse_cmds(t_token **tokens_head, t_commands **cmd_head);
void	create_cmd(t_token *start_node, t_token *target_node,
			t_commands **cmd_head, int num_nodes);
int		is_builtin(char *string);

				/* Linked_List Functions */
t_token		*last_node_token(t_token **lst_head);
t_commands	*last_node_cmds(t_commands **lst_head);
void		add_node_back_token(t_token **lst_head, t_token *node);
void		add_node_back_cmds(t_commands **lst_head, t_commands *node);
void		create_node(t_token **tokens_head, char *string, int start, int j);
void		print_token_list(t_token **lst_head);
void		print_cmds_list(t_commands **lst_head);


				/* Utils */
void	check_leaks(void);

#endif
