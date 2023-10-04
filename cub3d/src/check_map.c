/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:12:25 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/04 21:08:39 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_and_set_line(int *line_2d, char *line, int i, t_game *game)
{
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (line[i] != '1' && line[i] != '0')
				return (false);
		}
		if (ft_isalpha(line[i]))
		{
			if (line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'W' && line[i] != 'E')
				return (false);
			else
			{
				game->map->direction = line[i];
				game->map->player_count++;
			}
		}
		line_2d[i] = line[i];
		i++;
	}
	line_2d[i] = '\0';
	return (true);
}

bool	check_map_line(t_game *game, char *line)
{
	static int	counter = 0;
	int			*line_2d;

	line_2d = malloc(sizeof(int) * ((ft_strlen(line) * 4) + 1));
	if (!line_2d)
		return (false);
	if (check_and_set_line(line_2d, line, 0, game) == false)
		return (false);
	game->map->map_2d[counter] = line_2d;
	counter++;
	game->map->height = counter;
	return (true);
}

bool	check_elements_exist(t_game *game)
{
	if (game->map->no_texture == NULL)
		return (false);
	if (game->map->so_texture == NULL)
		return (false);
	if (game->map->we_texture == NULL)
		return (false);
	if (game->map->ea_texture == NULL)
		return (false);
	if (game->map->floor_color_string == NULL)
		return (false);
	if (game->map->ceiling_color_string == NULL)
		return (false);
	return (true);
}

bool	error_if_not_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_whitespace(line[i]) == false && line[i] != '\0')
			return (printf("Error: Line is not empty: %s\n", line), false);
		i++;
	}
	return (true);
}

void	parse_cub_file(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		i;
	bool	found_map;

	i = 0;
	fd = open(map, O_RDONLY);
	found_map = false;
	if (fd < 0)
	{
		printf("Error: Unable to open specified map.\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error: Something went wrong while trying to read map.\n");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		// printf("%s", line);
		while (is_whitespace(line[i]))
			i++;
		// printf("Line[i] = %c\n", line[i]);
		if (line[i] == 'N' && line[i + 1] == 'O')
		{
			if (check_no_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'S' && line[i + 1] == 'O')
		{
			if (check_so_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'W' && line[i + 1] == 'E')
		{
			if (check_we_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'E' && line[i + 1] == 'A')
		{
			if (check_ea_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'F')
		{
			if (check_floor_color(game, line, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'C')
		{
			if (check_ceiling_color(game, line, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if ((line[i] == '\0'|| is_whitespace(line[i])) && found_map == false)
			;
		else if ((line[i] == '\0'|| is_whitespace(line[i])) && found_map == true)
		{
			error_if_not_empty(line);
		}
		else if (ft_isdigit(line[i]))
		{
			found_map = true;
			if (check_elements_exist(game) == false)
			{
				printf("Error: Missing map elements.\n");
				exit(EXIT_FAILURE);
			}
			if (check_map_line(game, line) == false)
			{
				printf("Error: Invalid map line: %s\n", line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("Found invalid line: %s", line);
			exit(EXIT_FAILURE);
		}
		free(line);
		i = 0;
		line = get_next_line(fd);
	}
	close(fd);
}

bool	check_valid_map(t_game *game, char *map)
{
	if (map == NULL)
		return (printf("Error: No map file specified.\n"), false);
	else if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		return (printf("Error: Invalid map file specified.\n"), false);
	parse_cub_file(game, map);
	if (game->map->player_count == 0 || game->map->player_count > 1)
		return (printf("Error: Invalid player count of %d.\n",
				game->map->player_count), false);
	return (find_path_exit(game, game->map->map_2d));
}
