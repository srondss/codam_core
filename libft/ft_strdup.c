/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:40:59 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/09 08:56:03 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int	i;
	char	*ptr;

	i = 0;
	while (s[i] != '\0')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!(ptr))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main(void)
{
	char str[6] = "hello";
	char *newstr;
	char *mystr;

	newstr = strdup(str);
	mystr = ft_strdup(str);
	printf("%s\n", newstr);
	printf("%s\n", mystr);
}*/
