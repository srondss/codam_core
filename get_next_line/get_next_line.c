/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/12/08 19:20:23 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src > dst)
	{
		while (i < len)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			((unsigned char *) dst)[len - 1] = ((unsigned char *) src)[len - 1];
			len--;
		}
	}
	return (dst);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *buff_to_line(char *line, char *buf) //stops if buf[i] == \n
{
	char *str;	
	int i;
	int len;

	i = 0;
	len = ft_strlen(line);
	str = (char *)malloc(sizeof(char) * len + BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, line, (len + 1));
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
	free(line);
	line = ft_strdup(str);
	free(str);
	return (line);
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
			return (i + 1);
		i++;
	}
	return (0);
}

void	buf_update(char *buf)
{
	int i;
	int j;
	char new_buf[BUFFER_SIZE+1];
	
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

char	*get_next_line(int fd)
{
	static char 	buf[BUFFER_SIZE + 1];
	char 		*line;
	int 	read_ret;
	int		i;
	int		j;

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
				break;
			i++;
			j++;
		}
	}
	

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

//		/* 2 */ test_gnl(fd, NULL);


/* imagine i have the following text: he\nllo\nty
and my BUFFER_SIZE=4. it reads the first four letters into my BUF: h-e-\n-l + '\0'
my buff_to_line should copy up to the \n. So my line is: h-e-\n; 
then my buf_update function needs to put move the l to the front of the BUF.
Then I return the line: he\n. 
Then I call the function again but before I start reading into my buffer, I need to copy the l into my line. 
So my line would start of with being l only.
Then i read into my buffer the next four letters: llo\n;
Then I make sure that i start copying from index of ft_strlen(line) instead of 0. and repeat. 
Question: Why do I need to update my buffer? Because if I don't i will duplicate what was written inside due to it being static.
I think I indeed need to update the buffer.*/   

// get_next_line % gcc -Wall -Wextra -Werror get_next_line.c -D BUFFER_SIZE=4 ../libft/ft_calloc.c ../libft/ft_strlcpy.c ../libft/ft_bzero.c ../libft/ft_strdup.c

