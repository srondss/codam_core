/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_server.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:48 by ysrondy           #+#    #+#             */
/*   Updated: 2023/03/15 12:00:19 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_string_chars(int signum, char **string, int id, int len)
{
	if (*string == NULL)
	{
		*string = malloc(sizeof(char) * (len + 1));
		if (*string == NULL)
			error_handling_server(*string);
	}
	update_string(signum, *string, id);
}

void	error_handling_server(char *str)
{
	if (str)
		free(str);
	printf("Server-side Error\n");
	exit(EXIT_FAILURE);
}
