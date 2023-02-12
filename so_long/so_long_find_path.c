/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:34:11 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/12 18:42:17 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	position_player_x(char **map_2d)
{
	int	position_x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_2d[i] != NULL)
	{
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'P')
				return i;
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int	position_player_y(char **map_2d)
{
	int	position_y;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_2d[i] != NULL)
	{
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'P')
				return j;
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

void	find_path(char **map_2d, t_game *game)
{
	int	x;
	int	y;

	x = position_player_x(map_2d);
	y = position_player_y(map_2d);
	if (x == -1 || y == -1)
		return ;
	if (map_2d[x + 1][y] == 'E' || map_2d[x - 1][y] == 'E' || map_2d[x][y + 1] == 'E' || map_2d[x][y - 1] == 'E')
	{
		game->path = TRUE;
		return ;
	}
	if (map_2d[x + 1][y] == '0' || map_2d[x + 1][y] == 'C')
		map_2d[x + 1][y] = 'P';
	if (map_2d[x - 1][y] == '0' || map_2d[x - 1][y] == 'C')
		map_2d[x - 1][y] = 'P';
	if (map_2d[x][y + 1] == '0' || map_2d[x][y + 1] == 'C')
		map_2d[x][y + 1] = 'P';
	if (map_2d[x][y - 1] == '0' || map_2d[x][y - 1] == 'C')
		map_2d[x][y - 1] = 'P';
	map_2d[x][y] = 'X';
	find_path(map_2d, game);
}
