/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/11/03 19:26:24 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

char *buff_to_line(char *line, char *buf) //stops if buf[i] == \n
{
	char *tmp;
	int i;
	int len;

	i = 0;
	if (!line)
	{
		line = malloc(sizeof(char) * BUFFER_SIZE + 1);
		ft_memcpy(line, buf, (BUFFER_SIZE + 1));
	}
	else
	{
		len = ft_strlen(line);
		tmp = malloc(sizeof(char) * len + 1);
		ft_memcpy(tmp, line, (len + 1));
		free(line);
		line = malloc(len + BUFFER_SIZE + 1);
		ft_memcpy(line, tmp, (ft_strlen(tmp)));
		free(tmp);
		while (buf[i] != '\0')
		{
			line[len] = buf[i];
			len++;
			i++;
		}
		line[len] = '\0';
	}
	i = 0;
	return (line);
}

char *copy_newline(char *line)
{
	int i;
	int len;
	char *retstr;

	i = 0;
	len = ft_strlen(line);
	retstr = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		retstr[i] = line[i];
		if (line[i] == '\n')
		{
			retstr[i + 1] = '\0';
			break;
		}
		i++;
	}
	return (retstr);
}

int	check_newline(char *buf)
{
	int i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *line_update(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	while (line[i] != '\0') // SEGFAULT here EOF 
	{
		line[j] = line[i + 1];
		j++;
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	static char *line;
	static char *retstr;
	static int 	read_ret;

	if (line)
		line = line_update(line);
	
	read_ret = BUFFER_SIZE;
	// if buf[0]
	// 	copy whatever was inside buffer into line 
	while (!check_newline(line) && read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == 0 && buf[0] == '\0')
			return (free(line), NULL);
		if (read_ret == -1)
			return ("Error, Could'nt read file.");
		buf[read_ret] = '\0';
		line = buff_to_line(line, buf);
	}
	retstr = copy_newline(line);
	return (retstr);
}

int	main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("%s", str);
		free(str);
	}
	system("leaks -q a.out");
	close(fd);
}


