/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:32:29 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/11 16:32:27 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int find_delimiters(char const *s, char c, int i, int count);

char **ft_split(char const *s, char c)
{
	int j;
	int i;
	int count;
	char **test;

	i = 0;
	count = 0;
	test = (char **)malloc(sizeof(char *) * 3);
	j = find_delimiters(s, c, i, count);
	printf("Delimiters: %d", j);

	return (test);
}

int find_delimiters(char const *s, char c, int i, int count)
{
	if (s[i] == '\0')
		return (count);
	while (s[i] != c && s[i])
		i++;
	count++;
	printf("C: %c", s[i]);
	return (find_delimiters(s, c, (i + 1), count));
}

int main(void)
{
	char str[] = "hello,goodbye,doei";
	ft_split(str, ',');
	//for (int i = 0; i < 3; i++)
	//	printf("String: %s\n", ft_split(str, ',')[i]);
}
