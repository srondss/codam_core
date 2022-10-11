/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:01:01 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/09 16:14:45 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*word;

	word = (char *)s;
	i = 0;
	while (word[i] != '\0')
	{
		if (c == word[i])
		{
			return (&word[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char string[30] = "This is my @mention";
	char *string2 = strchr(string, '@');
	printf("Og: %s\n", string2);
	
	char *string3 = ft_strchr(string, '@');
	printf("Mine: %s\n", string3);
}*/
