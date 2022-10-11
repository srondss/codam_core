/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:46:59 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/11 13:57:45 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
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
	
	ptr = calloc(0,  0); 
	ptr2 = ft_calloc(0, 0);
	for (int i = 0; i < 5; i++)
		ptr[i] = i; 
	for (int j = 0; j < 5; j++)
		printf("Og: %d\n", ptr[j]);
	
	for (int i = 0; i < 5; i++)
		ptr2[i] = i; 
	for (int j = 0; j < 5; j++)
		printf("Mine: %d\n", ptr2[j]);
}*/
