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
	char			token;
	t_type			type;
	int				index;
	struct s_lexer	*next;
}				t_token;

#endif
