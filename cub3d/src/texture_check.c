/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:16:19 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/03 09:38:26 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_no_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (game->map->no_texture)
		return (printf("Error: Duplicate NO found.\n"), false);
	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->no_texture = ft_substr(line, i, j);
	printf("Found NO texture: %s\n", game->map->no_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid NO_Texture line.\n"), false);
	return (true);
}

bool	check_so_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (game->map->so_texture)
		return (printf("Error: Duplicate SO found.\n"), false);
	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->so_texture = ft_substr(line, i, j);
	printf("Found SO texture: %s\n", game->map->so_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid SO_Texture line.\n"), false);
	return (true);
}

bool	check_we_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (game->map->we_texture)
		return (printf("Error: Duplicate WE found.\n"), false);
	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->we_texture = ft_substr(line, i, j);
	printf("Found WE texture: %s\n", game->map->we_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid WE_Texture line.\n"), false);
	return (true);
}

bool	check_ea_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (game->map->ea_texture)
		return (printf("Error: Duplicate EA texture.\n"), false);
	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->ea_texture = ft_substr(line, i, j);
	printf("Found EA texture: %s\n", game->map->ea_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid EA_Texture line.\n"), false);
	return (true);
}
