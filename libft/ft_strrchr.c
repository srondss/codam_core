/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:28:06 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/21 14:53:31 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			ptr = (char *)&s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		ptr = (char *)&s[i];
	return (ptr);
}

/*int main(void)
{
	char string[] = "teste";
	
	char *string2 = strrchr(string, '\0');
	char *string3 = ft_strrchr(string, '\0');

	//printf("Og C: %d\n", 't' + 256);
	printf("pointer 0: %p\n", string+5);
	printf("Og: %p\n", string2);
	printf("Mine: %p\n", string3);
}*/
