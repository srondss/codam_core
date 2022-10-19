/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 14:42:19 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/13 10:31:30 by ysrondy       ########   odam.nl         */
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
	return (s);
}

/*int main(void)
{
	char buffer[10];
	char mbuffer[10];

	memset(buffer, 'a', sizeof(char) * 10);
	printf("Og: %s\n", buffer);

	ft_memset(mbuffer, 'a', sizeof(char) * 10);
	printf("Mine: %s\n", mbuffer);
}*/
