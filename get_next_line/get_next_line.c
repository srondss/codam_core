/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/12/14 16:59:15 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

static int	check_newline(char *buf, char c)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	if (c == '\n')
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else
	{
		while (buf[i] != '\0')
			i++;
	}
	return (i);
}

static char	*buff_to_line(char *line, char *buf)
{
	char	*str;	
	int		line_len;
	int		buf_len;

	buf_len = check_newline(buf, '\n');
	if (buf_len == 0)
		buf_len = check_newline(buf, '\0');
	line_len = check_newline(line, '\0');
	str = (char *)malloc(sizeof(char) * (line_len + buf_len + 1));
	if (!str)
		return (free(str), free(line), NULL);
	ft_strlcpy(str, line, (line_len + 1));
	fill_string(buf, str, 0, line_len);
	free(line);
	line = ft_strdup(str);
	free(str);
	return (line);
}

static bool	buf_update(char *buf)
{
	int		i;
	int		j;
	char	*new_buf;

	j = 0;
	i = (check_newline(buf, '\n') - 1);
	new_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_buf)
		return (false);
	if (buf[i] != '\0')
	{
		i++;
		while (buf[i] != '\0')
		{
			new_buf[j] = buf[i];
			i++;
			j++;
		}
		new_buf[j] = '\0';
		ft_strlcpy(buf, new_buf, (ft_strlen(new_buf) + 1));
	}
	else
		buf[0] = '\0';
	return (free(new_buf), true);
}

static char	*create_line(char *line, int read_ret, char *buf, int fd)
{
	while (!check_newline(line, '\n') && read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == 0 && buf[0] == '\0')
			return (free(line), NULL);
		if (read_ret == -1)
		{
			buf[0] = '\0';
			return (free(line), NULL);
		}
		buf[read_ret] = '\0';
		line = buff_to_line(line, buf);
		if (!line)
			return (NULL);
	}
	if (!buf_update(buf))
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	int				read_ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_ret = BUFFER_SIZE;
	line = ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	if (buf[0] != '\0')
	{
		line = buff_to_line(line, buf);
		if (!line)
			return (NULL);
	}
	line = create_line(line, read_ret, buf, fd);
	return (line);
}

/*int	main()
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
}*/
