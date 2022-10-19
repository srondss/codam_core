/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:28:06 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/13 11:14:22 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*word;
	char	*ptr;

	i = 0;
	word = (char *)s;
	ptr = NULL;
	while (s[i] != '\0')
	{
		if (word[i] == (unsigned char)c)
			ptr = &word[i];
		i++;
	}
	if (c == '\0')
		ptr = &word[i];
	return (ptr);
}

/*int main(void)
{
	char string[] = "tripouille";
	
	char *string2 = strrchr(string, 't' + 256);
	char *string3 = ft_strrchr(string, 't' + 256);

	printf("Og C: %d\n", 't' + 256);
	printf("Og: %s\n", string2);
	printf("Mine: %s\n", string3);
}*/
