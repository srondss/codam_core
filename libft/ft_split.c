/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:32:29 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/12 15:02:24 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int find_strlen(char const *s, char c);
static int find_delimiters(char const *s, char c, size_t i, size_t count);

char **ft_split(char const *s, char c)
{
	size_t j;
	size_t i;
	size_t count;
	size_t len;
	char **words;

	i = 0;
	count = 0;
	len = 0;
	j = find_delimiters(s, c, i, count);
	if (j == 0)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (j + 1));
	while (len < j && words)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		count = find_strlen(&s[i], c);
		words[len] = malloc(sizeof(**words) * (count + 1));
	//	ft_strncpy(words[len], &s[i], count);
		words[len][count] = '\0';
		while (s[i] != '\0' && s[i] != c)
			i++;
		len++;
	}
	words[len] = NULL;
	return (words);
}

static int find_delimiters(char const *s, char c, size_t i, size_t count)
{
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

static int find_strlen(char const *s, char c)
{
	size_t i;

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

/*int main(void)
{
	char str[] = "hello,,,,";
	char **str2 = ft_split(str, ',');
	for (int i = 0; i < 3; i++)
		printf("String: %s\n", str2[i]);
}*/
