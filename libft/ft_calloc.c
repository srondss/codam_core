/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:46:59 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/09 08:40:39 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	while (i < (nmemb * size))
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

/*int main(void)
{
	int *ptr;
	int *ptr2;
	
	ptr = calloc(5, sizeof(int)); 
	ptr2 = ft_calloc(5, sizeof(int));
 
	for (int i = 0; i < 5; i++)
		ptr[i] = i; 
	for (int j = 0; j < 5; j++)
		printf("Og: %d\n", ptr[j]);
	
	for (int i = 0; i < 5; i++)
		ptr2[i] = i; 
	for (int j = 0; j < 5; j++)
		printf("Mine: %d\n", ptr2[j]);
}*/
