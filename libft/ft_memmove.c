/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:56 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/07 10:26:59 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	diff;

	i = -1;
	diff = ((char *)dest) - ((char *)src);
	if (((char *)dest) > ((char *)src))
	{
		while (--n > diff - 1)
				((char *)dest)[n] = ((char *)dest)[n - diff];
		while (++i < diff)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
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
