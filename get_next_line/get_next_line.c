/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/11/02 19:35:14 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

char *copy_up_to_newline(char *dest, char *src)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (src[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	while (len <= i)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

int	check_newline(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	static char *retstr;
	static char *tmp;
	int i;
	int read_ret;
	int k;

	i = 0;
	read_ret = 1;
	k = 0;
	while (read_ret != 0 && (check_newline(buf) == 0))
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (!retstr)
		{
			retstr = malloc(sizeof(char) * (ft_strlen(buf) + 1));
			ft_memcpy(retstr, buf, (ft_strlen(buf) + 1));
		}
		else
		{
			tmp = malloc(sizeof(char) * (ft_strlen(retstr) + 1));
			ft_memcpy(tmp, retstr, (ft_strlen(retstr) + 1));
			k = ft_strlen(tmp);
			free(retstr);
			retstr = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(tmp) + 1));
			ft_memcpy(retstr, tmp, (ft_strlen(tmp) + 1));
			while (buf[i] != '\0')
			{
				retstr[k] = buf[i];
				if (buf[i] == '\n')
				{
					retstr[k + 1] = '\0';
					break;
				}
				i++;
				k++;
			}
			printf("i : %d\n", i);
			printf("readret: %d\n", i);
			if (buf[i] != '\n')
				retstr[k] = '\0';
			i = 0;
		}
	}
	tmp = copy_up_to_newline(tmp, retstr);
	//free(retstr);
	printf("Final Ret: %s", tmp);
	return tmp;
}

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
}
