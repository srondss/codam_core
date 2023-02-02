/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:12:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/02 16:08:36 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if there is at least 1 collectible.
int	check_collectibles(char *map)
{
	char	*str;
	int	fd;
	int	i;
	int	collectibles;

	i = 0;
	collectibles = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		while (i < (ft_strlen(str) - 1))
		{
			if (str[i] == 'C')
				collectibles++;
			i++;
		}
		i = 0;
		free(str);
	}
	if (collectibles < 1)
		return (free(str), close(fd), 0);
	return (free(str), close(fd), 1);
}

// Checks if closed/surrounded by walls.
int	check_walls(char *map)
{
	char	*str;
	int	fd;
	int	j;

	fd = open(map, O_RDONLY);
	j = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (j == 0)
		{
			if (helper_check_1s_wall(str, 0, fd) == 0)
				return (free(str), close(fd), 0);						
		}
		else
		{
			if (str[0] != '1' || str[ft_strlen(str) - 2] != '1')
				return (free(str), close(fd), 0);
		}
		j++;
		free(str);
	}
	return (helper_walls(map, j));
}

// Checks if last line doesn't have any 1s in it. 
int	helper_walls(char *map, int j)
{
	int fd;
	int i;
 	char *str;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i < j)
	{
		str = get_next_line(fd);
		if (i + 1 == j)
			break;
		free(str);
		i++;
	}
	if (helper_check_1s_wall(str, 0, fd) == 0)
		return (free(str), close(fd), 0);
	return (free(str), close(fd), 1);
}

// Checks if given line doesn't have a 1. 
int	helper_check_1s_wall(char *str, int i, int fd)
{
	while (i < (ft_strlen(str) - 1))
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
