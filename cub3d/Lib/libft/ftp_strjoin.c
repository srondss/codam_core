/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_strjoin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/11 17:13:00 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/04/11 17:13:00 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*free_and_set_null(char *s1)
{
	free(s1);
	s1 = NULL;
	return (s1);
}

char	*ftp_strjoin(char *s1, char *s2)
{
	char	*str_join;
	int		s1_len;
	int		s2_len;

	str_join = NULL;
	s1_len = 0;
	s2_len = 0;
	if (s2 == NULL)
	{
		str_join = ft_strdup(s1);
		free(s1);
		return (str_join);
	}
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	str_join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str_join == NULL)
		return (free_and_set_null(s1));
	ft_strlcpy(str_join, s1, s1_len + 1);
	ft_strlcat(str_join, s2, s1_len + s2_len + 1);
	free(s1);
	return (str_join);
}
