/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:51:56 by ysrondy           #+#    #+#             */
/*   Updated: 2022/11/04 11:49:26 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	string = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!string)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		string[i] = s1[i];
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
/*
#include <stdio.h>
int main(void)
{
	char str1[] = "mymy";
	char str2[] = "goodbye";
	printf("String: %s", ft_strjoin(NULL, str2));
}*/
