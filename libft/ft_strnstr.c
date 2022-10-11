/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:12:25 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/07 13:58:18 by ysrondy          ###   ########.fr       */
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
	while (i < len && big[i] != '\0')
	{	
		c = i;
		while (little[j] == big[i])
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
	char haystack[] = "This is thth12312dasfthdsthe way.";
	char needle[] = "the";

	printf("Og: %s\n", strnstr(haystack, needle, 30));
	printf("Mine: %s\n", ft_strnstr(haystack, needle, 30));
}*/
