/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/11/27 19:47:24 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

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
//	printf("Line in buff_to_line: %s\n", line);
//	printf("Length of Line: %d\n", len);
	str = (char *)malloc(sizeof(char) * len + BUFFER_SIZE + 1);
	ft_strlcpy(str, line, (len + 1));
//	printf("Str in buff_to_line: %s\n", str);
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
//	printf("Final_Str in buff_to_line: %s\n", str);
	free(line);
	line = ft_strdup(str);
	free(str);
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
			return (i + 1);
		i++;
	}
	return (0);
}

char	*buf_update(char *buf)
{
	int i;

	i = 0;
//	printf("Buf dans buf_update: %s\n", buf);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] != '\0')
	{
//		printf("length Buf: %d\n", ft_strlen(buf));
		ft_memmove(buf, buf+(i + 1), (ft_strlen(buf) - (i - 1)));
	}
	return (buf); 
}

char	*get_next_line(int fd)
{
	static char 	buf[BUFFER_SIZE + 1];
	char 		*line;
	static int 	read_ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	read_ret = BUFFER_SIZE;
	line = ft_calloc(sizeof(char *), BUFFER_SIZE + 1);
//	printf("Begin Buffer: %s\n", buf);
	if (buf[0] != '\0')
	{
		while (buf[i] != '\0')
		{
	//		printf("enter\n");
			line[j] = buf[i];
			i++;
			j++;
		}
	}
//	printf("Line before start: %s\n", line);
	while (!check_newline(line) && read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == 0 && buf[0] == '\0')
			return (free(line), NULL);
		if (read_ret == -1)
			return (free(line), NULL);
		buf[read_ret] = '\0';
	//	printf("Updated Buffer: %s\n", buf);
		line = buff_to_line(line, buf);
	//	printf("Line: %s\n", line);
	}
	buf_update(buf);
	return (line);
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

