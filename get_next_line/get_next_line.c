/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/12/09 20:09:01 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*buff_to_line(char *line, char *buf)
{
	char	*str;	
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	str = (char *)malloc(sizeof(char) * len + BUFFER_SIZE + 1);
	if (!str)
	{
		free(line);
		return (free(str), NULL);
	}
	ft_strlcpy(str, line, (len + 1));
	fill_string(buf, str, i, len);
	free(line);
	line = ft_strdup(str);
	free(str);
	return (line);
}

int	check_newline(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	buf_update(char *buf)
{
	int		i;
	int		j;
	char	new_buf[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
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
}

char	*create_line(char *line, int read_ret, char *buf, int fd)
{
	while (!check_newline(line) && read_ret == BUFFER_SIZE)
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
	buf_update(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	int				read_ret;
	int				i;
	int				j;

	i = 0;
	j = 0;
	read_ret = BUFFER_SIZE;
	line = ft_calloc(sizeof(char *), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	if (buf[0] != '\0')
	{
		while (buf[i] != '\0')
		{
			line[j] = buf[i];
			if (buf[i] == '\n')
				break ;
			i++;
			j++;
		}
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
