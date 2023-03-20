/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:33:32 by ysrondy           #+#    #+#             */
/*   Updated: 2022/11/08 18:19:57 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	size_t			slen;
	char			*string;

	j = -1;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (*s == '\0' || start >= slen)
		return (ft_strdup(""));
	if ((slen - start) < len)
		len = (slen - start);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!(string))
		return (NULL);
	i = start;
	while (++j < len && s[i] != '\0')
	{
		string[j] = s[i];
		i++;
	}
	string[j] = '\0';
	return (string);
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "";
	printf("Substring: %s", ft_substr(s, 1, 1)); 
}*/
