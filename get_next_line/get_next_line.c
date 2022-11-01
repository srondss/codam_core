/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/30 17:06:31 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"


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
	int i;
	int j;
	static int k;

	i = 0;
	j = 1;
	k = 0;
	while (j != 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (check_newline(buf) == 0)
		{
			printf("Buf: %s\n", buf);
			printf("Ret: %s\n", retstr);
			if (!retstr)
				retstr = ft_strdup(buf);
			else
			{
		
				//printf("buflen %d\n", ft_strlen(buf));
				printf("strlen1 %d\n", ft_strlen(retstr));
				retstr = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(retstr) + 1));
				//printf("strlen2 %d\n", ft_strlen(retstr));
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
			}
		}
	}
	printf("outside\n");
	printf("Final Buf: %s\n", buf);
	printf("Final Ret: %s\n", retstr);
	return (retstr);
}

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
}
