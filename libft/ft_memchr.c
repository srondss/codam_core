/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:51:17 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/07 11:01:52 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*bytes;

	i = 0;
	bytes = (void *)s;
	while (i < n)
	{
		if (((char *)bytes)[i] == c)
			return (&bytes[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char str[6] = "hello";
	char *ptr = memchr(str, 'l', sizeof(char) * 6);
	printf("%s\n", ptr);
	char *mptr = ft_memchr(str, 'l', sizeof(char) * 6);
	printf("%s\n", mptr);
}*/
