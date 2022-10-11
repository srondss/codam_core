/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 14:42:19 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/05 13:15:47 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/*#include <string.h>*/
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	((char *)s)[i] = '\0';
	return (s);
}
/*
int main(void)
{
	char buffer[10];
	char mbuffer[10];

	memset(buffer, 'a', sizeof(char) * 10);
	printf("Og: %s\n", buffer);

	ft_memset(mbuffer, 'a', sizeof(char) * 10);
	printf("Mine: %s\n", mbuffer);
}*/
