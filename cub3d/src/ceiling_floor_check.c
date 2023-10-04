/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:18:40 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/04 21:28:12 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_rgb_values(t_map *map, char *tile_name)
{
	if (ft_strncmp("floor", tile_name, 5) == 0)
	{
		if (map->floor_colors.color_B < 0
			|| map->floor_colors.color_B > 255
			|| map->floor_colors.color_G < 0
			|| map->floor_colors.color_G > 255
			|| map->floor_colors.color_R < 0
			|| map->floor_colors.color_R > 255)
			return (false);
		return (true);
	}
	else if (map->ceiling_colors.color_B < 0
		|| map->ceiling_colors.color_B > 255
		|| map->ceiling_colors.color_G < 0
		|| map->ceiling_colors.color_G > 255
		|| map->ceiling_colors.color_R < 0
		|| map->ceiling_colors.color_R > 255)
		return (false);
	return (true);
}

void	set_colors(char **split_rgb, char *tile_name, t_game *game)
{
	if (ft_strncmp("floor", tile_name, 5) == 0)
	{
		game->map->floor_colors.color_R = ft_atoi(split_rgb[0]);
		game->map->floor_colors.color_G = ft_atoi(split_rgb[1]);
		game->map->floor_colors.color_B = ft_atoi(split_rgb[2]);
	}
	else if (ft_strncmp("ceiling", tile_name, 7) == 0)
	{
		game->map->ceiling_colors.color_R = ft_atoi(split_rgb[0]);
		game->map->ceiling_colors.color_G = ft_atoi(split_rgb[1]);
		game->map->ceiling_colors.color_B = ft_atoi(split_rgb[2]);
	}
}
// printf("Floor Color String: %s\n", game->map->floor_color_string);
// printf("R: %d\nG: %d\nB: %d\n", game->map->floor_colors.color_R, game->map->floor_colors.color_G, game->map->floor_colors.color_B);
bool	check_floor_color(t_game *game, char *line, bool found_map)
{
	int		first_digit;
	int		last_digit;
	char	**split_rgb;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	first_digit = get_pos_first_digit(line, 'F');
	if (first_digit == 0 || is_whitespace(line[first_digit - 1]) == false)
		return (printf("Error: Invalid character in floor line.\n"), false);
	last_digit = get_pos_last_digit(line);
	game->map->floor_color_string = ft_substr(line, first_digit, last_digit);
	split_rgb = ft_split(game->map->floor_color_string, ',');
	if (!split_rgb)
		return (printf("Malloc fail\n"), false);
	if (split_rgb[3] != NULL)
		return (printf("Error: Too many ceiling values.\n"), false);
	set_colors(split_rgb, "floor", game);
	if (check_rgb_values(game->map, "floor") == false)
		return (printf("Error: RGB colors invalid.\n"), false);
	last_digit++;
	while (is_whitespace(line[last_digit]))
		last_digit++;
	if (line[last_digit] != '\0')
		return (printf("Error: Invalid Floor_Color line.\n"), false);
	return (true);
}

// printf("Ceiling Color String: %s\n", game->map->ceiling_color_string);
// printf("R: %d\nG: %d\nB: %d\n", game->map->ceiling_colors.color_R, game->map->ceiling_colors.color_G, game->map->ceiling_colors.color_B);
bool	check_ceiling_color(t_game *game, char *line, bool found_map)
{
	int		first_digit;
	int		last_digit;
	char	**split_rgb;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	first_digit = get_pos_first_digit(line, 'C');
	if (first_digit == 0 || is_whitespace(line[first_digit - 1]) == false)
		return (printf("Error: Invalid character in ceiling line.\n"), false);
	last_digit = get_pos_last_digit(line);
	game->map->ceiling_color_string = ft_substr(line, first_digit, last_digit);
	split_rgb = ft_split(game->map->ceiling_color_string, ',');
	if (!split_rgb)
		exit(EXIT_FAILURE);
	if (split_rgb[3] != NULL)
		return (printf("Error: Too many ceiling values.\n"), false);
	set_colors(split_rgb, "ceiling", game);
	if (check_rgb_values(game->map, "ceiling") == false)
		return (printf("Error: RGB colors invalid.\n"), false);
	last_digit++;
	while (is_whitespace(line[last_digit]))
		last_digit++;
	if (line[last_digit] != '\0')
		return (printf("Error: Invalid Ceiling_Color line.\n"), false);
	return (true);
}
