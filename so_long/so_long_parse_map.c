/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:25:49 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/01 13:13:42 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if map contains other letters besides 0,1,c,e,p.
int	check_map_letters(char *map)
{
	int fd;
	int i;
	char *str;
	
	i = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str) // need to consider empty file.
			return (1);
		printf("%s", str);
		while (i < (ft_strlen(str) - 1))
		{
			if (str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E' || str[i] == 'P')
				i++;
			else
				return (0);
		}
		i = 0;
		free(str);
	}
	close(fd);
}

// Checks if map is rectangular. 
int	check_map_rectangle(char *map)
{
	int fd;
	char *str;
	int size;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	size = ft_strlen(str);

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			return (1);
		if (size != ft_strlen(str))
			return (0);
		free(str);
	}
	close(fd);
}

// Checks if .ber file as argument.
int	check_error_ber_file(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != '.')
			i++;
		else
		{
			if (argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i + 3] == 'r' && argv[i + 4] == '\0')
				return (1);
			return (0);
		}
	}
	return (0);
}

// Need to check if map contains only 1 exit, at least 1 collectible, and only 1 starting position.
// Need to fix.
int	check_st_ex_cltble(char *map)
{
	int	fd;
	char	*str;
	int	start;
	int	collectibles;
	int	exit;

	start = 0;
	collectibles = 0;
	exit = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("%s", str);
		while (i < (ft_strlen(str) - 1))
		{
			if (str[i] == 'C')
				collectibles++;
			else if (str[i] == 'E')
				exit++;
			else if (str[i] == 'P')
				start++;
			i++;
		}
		i = 0;
		free(str);
	}
	if (start > 1 || exit > 1 || collectibles < 1)
		return (0)
	close(fd);
	return (1);
}


// Need to find out if closed/surrounded by walls.


