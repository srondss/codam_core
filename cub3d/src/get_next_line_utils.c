/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:21:35 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/23 18:59:40 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	fill_string(char *buf, char *str, int i, int len)
{
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		str[len + i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		str[len + i] = '\n';
		str[len + i + 1] = '\0';
	}
	else
		str[len + i] = '\0';
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	if (size != 0 || nmemb != 0)
	{
		i = 0;
		while (i < (size * nmemb))
		{
			((char *)ptr)[i] = '\0';
			i++;
		}
	}
	return ((void *) ptr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] != '\0')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!(ptr))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
