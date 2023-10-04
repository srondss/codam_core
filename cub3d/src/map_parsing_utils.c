/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:19:49 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/04 21:10:09 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_whitespace(char c)
{
	if (c == '\f' || c == ' ' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (true);
	else
		return (false);
}

int	get_pos_last_digit(char *line)
{
	char	*final_char;
	int		i;

	i = ft_strlen(line);
	final_char = ft_strchr(line, '\0');
	while (ft_isdigit(*final_char) != true)
	{
		final_char--;
		i--;
	}
	return (i);
}

int	get_pos_first_digit(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] != c)
		i++;
	i++;
	while (line[i] != '\0')
	{
		if (is_whitespace(line[i]) == false && ft_isdigit(line[i]) == false)
			return (0);
		if (ft_isdigit(line[i]) == true)
			return (i);
		i++;
	}
	return (0);
}

int	get_num_lines_file(char *map)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Unable to open specified map.\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// printf("Found %d lines in map.\n", counter);
	return (counter);
}
