/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:45 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/25 16:22:40 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char str[BUFFER_SIZE + 1];
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		read(fd, &str[i], 1);
		if (str[i] == '\n')
			break;	
		i++;
	}
	str[i + 1] = '\0';
	
	printf("Final Str: %s\n", str);

	return (str);
}

int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
