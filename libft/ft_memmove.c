/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:56 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/11 14:36:36 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			(d)[n] = (s)[n];
		}
	}
	if (src > dest)
	{
		while (i < n)
		{
			(d)[i] = (s)[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	dest[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int	marr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	mdest[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	memmove(arr+2, arr, sizeof(int)*8);	
	for (int i = 0; i < 10; i++)
		printf("Og: %d\n", arr[i]); 

	ft_memmove(marr+2, marr, sizeof(int)*8);
	for (int i = 0; i < 10; i++)
		printf("My Func: %d\n", marr[i]);
}*/
