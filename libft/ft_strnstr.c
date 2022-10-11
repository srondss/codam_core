/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:12:25 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/11 14:15:51 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{	
		c = i;
		while (little[j] == big[i] && i < len)
		{
			if (little[j + 1] == '\0')
				return (((char *)big) + c);
			else
			{
				j++;
				i++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char haystack[] = "lorem ipsum dolor sit amet";
	char needle[] = "dolor";

	printf("Og: %s\n", strnstr(haystack, needle, 15));
	printf("Mine: %s\n", ft_strnstr(haystack, needle, 15));
}*/
