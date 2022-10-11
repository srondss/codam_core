/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:34 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/07 11:12:03 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((char *)s1)[i] - ((char *)s2)[i]);
		i++;
	}
	return (0);
}

/*int main(void)
{
	char str1[50] = "I am a string \000 with a hidden tail";
	char str2[50] = "I am a string \000 equiped with a sneaky part";

	printf("Og: %d\n", memcmp(str1, str2, 50));
	printf("Mine: %d\n", ft_memcmp(str1, str2, 50));
	printf("Strncmp: %d\n", strncmp(str1, str2, 50));
}*/
