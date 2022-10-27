/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/27 19:01:09 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	static char *retstr;
	static char *tmp;
	int i;
	int j;

	i = 0;
	j = 1;

	while (j != 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		retstr = malloc(sizeof(char) * BUFFER_SIZE + 1);
		while (buf[i] != '\0')
		{
			retstr[i] = buf[i];
			if (buf[i] == '\n')
				break;
			i++;
		}
		retstr[i + 1] = '\0';
		i = 0;
		printf("Buf: %s\n", buf);
		printf("Ret: %s\n", retstr);
		tmp = ft_strjoin(retstr, buf);
		printf("Tmp: %s\n", tmp);
		free(retstr);
	}

	printf("Buf: %s\n", buf);
	printf("Ret: %s\n", tmp);
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
