/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:25:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/07 09:58:24 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	c = i + j;
	if (i > (size))
		return (j + size);
	else
	{
		j = 0;
		while (i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (c);
}

/*int main(void)
{
	char src[6] = "hello";
	char dest[8] = "bye";
	
	char src2[6] = "hello";
	char dest2[8] = "bye";
	
	printf("Return Og: %lu\n", strlcat(dest, src, 5));
	printf("Return Mine: %lu\n", ft_strlcat(dest2, src2, 5));
	
	printf("String Og: %s\n", dest);
	printf("String Mine: %s\n", dest2);
}*/
