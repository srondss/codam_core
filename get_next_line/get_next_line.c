/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/11/01 18:39:30 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"


char	*ft_strcpy(char *dest, char*src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
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
	static char buf[BUFFER_SIZE];
	static char *retstr;
	static char *tmp;
	int i;
	int j;
	int k;

	i = 0;
	j = 1;
	k = 0;
	if (retstr)
	{
		printf("RetB4Free: %s\n", retstr);
		free(retstr);
		printf("RetA5Free: %s\n", retstr);
		free(tmp);
	}
	while (j != 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (check_newline(buf) == 0)
		{
			printf("Buf: %s\n", buf);
			printf("Ret: %s\n", retstr);
			if (!retstr)
			{
				printf("duplicated\n");
				retstr = ft_strdup(buf);
			}
			else
			{
				tmp = ft_strdup(retstr);
				k = ft_strlen(tmp);
	//			printf("strlen1: %d\n", k);
				retstr = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(retstr) + 1));
				ft_strcpy(retstr,tmp);
	//			printf("strlen2 %d\n", ft_strlen(retstr));
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
				i = 0;
				retstr[k + 1] = '\0';
			}
		}
		else
		{
			printf("Final Ret: %s\n", retstr);
			return (retstr);
		}
	}
	printf("outside\n");
	//printf("Final Buf: %s\n", buf);
	printf("Final Ret: %s\n", retstr);
	return (retstr);
}

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
}
