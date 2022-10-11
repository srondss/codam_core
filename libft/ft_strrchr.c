/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:28:06 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/07 10:38:15 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char	*word;
	char	*ptr;

	i = 0;
	word = (char *)s;
	ptr = NULL;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			ptr = &word[i];
		i++;
	}
	return (ptr);
}

/*int main(void)
{
	char string[30] = "This is a @ment@ion";
	
	char *string2 = strrchr(string, 'i');
	char *string3 = ft_strrchr(string, 'i');

	printf("Og: %s\n", string2);
	printf("Mine: %s\n", string3);
}*/
