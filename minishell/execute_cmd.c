/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:54:11 by ysrondy           #+#    #+#             */
/*   Updated: 2023/04/20 07:54:12 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Execve takes a path which needs to be passed to the function.
Basically what I need to do is to loop through the path env variable,
which will be given to me in the main through the envp. I need to parse
the envp first to make sure that is ready to be looped through and basically
split the ':'. Once the envp is ready, then I pass each string in my envp as
the first arg to the execve function. If it works, great. Otherwise, I need to
throw an error. I need to use the access() function for this. I will need to create a tools variable to be able to hold the
envp and probably a bunch of other things.
That will enable me to run 1 command.
Then I need to figure out how to use forks and pipes to have multiple commands work.
Explanation: https://www.youtube.com/watch?v=iq7puCxsgHQ
https://www.youtube.com/watch?v=Mqb2dVRe0uo
*/

void	execute(t_commands **cmd_head)
{
	t_commands	*first;

	first = *cmd_head;
	printf("Execution happening now.\n");
	if (execve("/bin/ls", first->cmds, NULL) == -1)
		perror("ERROR -> ");
}
