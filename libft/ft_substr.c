/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:33:32 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/12 13:38:32 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*string;

	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) * len + 1);
	if (!(string))
		return (NULL);
	while (i < start && s[i] != '\0')
		i++;
	while (j < len && s[i] != '\0')
	{
		string[j] = s[i];
		j++;
		i++;
	}
	string[j] = '\0';
	return (string);
}

/*int main(void)
{
	char s[] = "hello,goodbye,doei";
	printf("Substring: %s", ft_substr(s, 6, 7)); 
}*/
