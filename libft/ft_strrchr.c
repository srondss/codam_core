/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:28:06 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/12 09:16:17 by ysrondy          ###   ########.fr       */
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
		if (word[i] == c)
			ptr = &word[i];
		i++;
	}
	if (c == '\0')
		ptr = &word[i];
	return (ptr);
}

/*int main(void)
{
	char string[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	
	char *string2 = strrchr((void *)0, '\0');
	char *string3 = ft_strrchr((void *)0, '\0');

	printf("Og: %s\n", string2);
	printf("Mine: %s\n", string3);
}*/
