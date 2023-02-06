/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:32:29 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/06 21:23:02 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**free_everything(char **string, int i);
static int	find_strlen(char const *s, char c);
static int	get_nstrings(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	len;
	char	**strings;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	len = get_nstrings(s, c);
	strings = (char **)malloc(sizeof(char *) * (len + 1));
	if (!strings)
		return (0);
	while (++i < len)
	{
		while (s[j] == c)
			j++;
		strings[i] = ft_substr(s, j, find_strlen(&s[j], c));
		if (strings[i] == NULL)
			return (free_everything(strings, i));
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	strings[i] = NULL;
	return (strings);
}

static char	**free_everything(char **string, int i)
{
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
	return (NULL);
}

static int	get_nstrings(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static int	find_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		else
			i++;
	}
	return (i);
}

/*
#include <stdio.h>
int main(void)
{
	//char str[] = "hello,goodbye,doei";
	char **str2 = ft_split(NULL, ',');
	printf("String: %s", str2[0]);
	//for (int i = 0; i < 3; i++)
	//	printf("String: %s\n", str2[i]);
}*/
