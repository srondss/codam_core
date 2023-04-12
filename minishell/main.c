/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:38:04 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/12 08:22:10 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

Project needs to be divided into the following sections:

Parsing Input:
The first step in creating a shell is to parse the input from the user.
You will need to read the input from the user and then parse it into a series of tokens that represent the command and its arguments.
You can use functions like strtok() to split the input into tokens.

Creating a Command Execution Engine:
Once the input is parsed, you will need to execute the command.
For this, you will need to create a command execution engine that can execute different types of commands, such as built-in commands like cd and exit, and external commands like ls, grep, etc.

Implementing Built-In Commands:
You will need to implement the built-in commands like cd, exit, and echo.
These commands are executed directly by the shell and do not require forking a new process.

Implementing I/O Redirection:
I/O redirection is an important feature of the shell that allows the user to redirect input and output from and to files.
You will need to implement redirection using system calls like open(), close(), and dup2().

Implementing Pipes:
Pipes allow the user to chain together multiple commands, where the output of one command is passed as input to the next command.
You will need to implement pipes using system calls like pipe() and dup2().

Implementing Job Control:
Job control is a feature that allows the user to control and manage multiple processes running in the shell.
You will need to implement job control using system calls like fork(), waitpid(), and kill().
*/

#include "minishell.h"

void	free_list(t_token **lst_head)
{
	t_token	*tmp;
	t_token	*first;

	first = *lst_head;
	tmp = first->next;
	while (tmp != NULL)
	{
		free(first);
		first = tmp;
		tmp = tmp->next;
	}
	free(first);
	free(lst_head);
}

int	main(int argc, char **argv)
{
	char	*string;
	t_token	**tokens;

	tokens = malloc(sizeof(t_token *) * 1);
	if (!tokens)
		return (EXIT_FAILURE);
	if (argc != 1)
		return (EXIT_FAILURE);

	*tokens = NULL;

	while (1)
	{
		string = readline("Minishell: ");
		parse_input(string, tokens);
		free(string);
	}

	free_list(tokens);
	(void)(argv);
	return (0);
}
