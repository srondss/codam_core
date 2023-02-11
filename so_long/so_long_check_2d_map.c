/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_2d_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:11:20 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/11 18:12:53 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(char **map_2d)
{
	int i;

	i = 0;
	while (map_2d[i] != NULL)
		i++;
	return (i);
}


// checks if all 1s are in the right place.
void	check_2d_map_walls(t_game *game)
{
	int row;
	int column;
	
	row = 0;
	game->rows = count_rows(game->map);
	game->columns = ft_strlen(game->map[0]);

	while (row < game->rows)
	{
		column = 0;
		while (column < game->columns)
		{
			if (row == 0 && game->map[row][column] != '1')
				return (free(game->map), ft_error_message(E_WALLS, 1));
			if (column == 0 && game->map[row][column] != '1')
				return (free(game->map), ft_error_message(E_WALLS, 1));
			if (row == game->rows - 1 && game->map[row][column] != '1')
				return (free(game->map), ft_error_message(E_WALLS, 1));
			if (column == game->columns - 1 && game->map[row][column] != '1')
				return (free(game->map), ft_error_message(E_WALLS, 1));
			column++;
		}
		row++;
	}
}

void	free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
