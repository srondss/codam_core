/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:10:32 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/06 23:48:46 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	position_player_row(int **map_2d, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height && game->map->map_2d[i])
	{
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'N' || map_2d[i][j] == 'S'
			|| map_2d[i][j] == 'W' || map_2d[i][j] == 'E'
			|| map_2d[i][j] == 'P')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int	position_player_column(int **map_2d, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height && game->map->map_2d[i])
	{
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'N' || map_2d[i][j] == 'S'
			|| map_2d[i][j] == 'W' || map_2d[i][j] == 'E'
			|| map_2d[i][j] == 'P')
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

void	print_map_2d(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height && game->map->map_2d[i])
	{
		while ((game->map->map_2d[i][j]) != '\0')
		{
			printf("%c", game->map->map_2d[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	printf("\n");
}

int	get_row_width(t_game *game, int **map_2d, int row)
{
	int	i;

	i = 0;
	while (map_2d[row] && map_2d[row][i] != '\0')
		i++;
	if (i > game->map->largest_row)
		game->map->largest_row = i;
	return (i);
}

bool	find_path_exit(t_game *game, int **map_2d)
{
	int	x;
	int	y;

	x = position_player_row(map_2d, game);
	y = position_player_column(map_2d, game);
	if (x == -1 || y == -1)
		return (true);
	// print_map_2d(game);
	if (x == 0 || y == 0
		|| x == game->map->height || y == get_row_width(game, map_2d, x)
		|| map_2d[x + 1][y] == '\0' || map_2d[x - 1][y] == '\0'
		|| map_2d[x][y + 1] == '\0' || map_2d[x][y - 1] == '\0')
			return (printf("Error: Player is not surrounded by walls.\n"), false);
	if (map_2d[x + 1][y] == '0' || map_2d[x + 1][y] == ' ')
		map_2d[x + 1][y] = 'P';
	if (map_2d[x - 1][y] == '0' || map_2d[x - 1][y] == ' ')
		map_2d[x - 1][y] = 'P';
	if (map_2d[x][y + 1] == '0' || map_2d[x][y + 1] == ' ')
		map_2d[x][y + 1] = 'P';
	if (map_2d[x][y - 1] == '0' || map_2d[x][y - 1] == ' ')
		map_2d[x][y - 1] = 'P';
	map_2d[x][y] = 'X';
	return (find_path_exit(game, map_2d));
}
