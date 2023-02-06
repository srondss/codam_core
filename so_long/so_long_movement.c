/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/06 20:53:40 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	column;
	int	row;

	row = -1;
	while (++row < game->rows)
	{
		column = -1;
		while (++column < game->columns)
		{
			if (game->map[row][column] == 'P')
			{
				if (game->map[row - 1][column] == '0' || game->map[row - 1][column] == 'C' || game->map[row - 1][column] == 'E')
				{
					if (validate_move(game, game->map[row - 1][column]) == 1)
						return;
					game->map[row - 1][column] = 'P';
					game->map[row][column] = '0';
					game->moves++;
					ft_printf("Moves: %d\n", game->moves);
				}
			}
		}
	}
}

void	move_left(t_game *game)
{
	int	column;
	int	row;

	row = -1;
	while (++row < game->rows)
	{
		column = -1;
		while (++column < game->columns)
		{
			if (game->map[row][column] == 'P')
			{
				if (game->map[row][column - 1] == '0' || game->map[row][column - 1] == 'C' || game->map[row][column - 1] == 'E')
				{
					if (validate_move(game, game->map[row][column - 1]) == 1)
						return;
					game->map[row][column - 1] = 'P';
					game->map[row][column] = '0';
					game->moves++;
					ft_printf("Moves: %d\n", game->moves);
				}
			}
		}
	}
}

void	move_right(t_game *game)
{
	int	column;
	int	row;

	row = -1;
	while (++row < game->rows)
	{
		column = -1;
		while (++column < game->columns)
		{
			if (game->map[row][column] == 'P')
			{
				if (game->map[row][column + 1] == '0' || game->map[row][column + 1] == 'C' || game->map[row][column + 1] == 'E')
				{
					if (validate_move(game, game->map[row][column + 1]) == 1)
						return;
					game->map[row][column + 1] = 'P';
					game->map[row][column] = '0';
					game->moves++;
					ft_printf("Moves: %d\n", game->moves);
				}
			}
		}
	}
}

void	move_down(t_game *game)
{
	int	column;
	int	row;

	row = -1;
	while (++row < game->rows)
	{
		column = -1;
		while (++column < game->columns)
		{
			if (game->map[row][column] == 'P')
			{
				if (game->map[row + 1][column] == '0' || game->map[row + 1][column] == 'C' || game->map[row + 1][column] == 'E')
				{
					if (validate_move(game, game->map[row + 1][column]) == 1)
						return;
					game->map[row + 1][column] = 'P';
					game->map[row][column] = '0';
					game->moves++;
					ft_printf("Moves: %d\n", game->moves);
				}
			}
		}
	}
}

int	validate_move(t_game *game, char letter)
{
	if (letter == 'C')
	{
		game->collectibles--;
		if (game->collectibles == 0)
			ft_printf("You collected everything! Time to exit.\n");
	}
	else if (letter == 'E' && game->collectibles != 0)
	{
		ft_printf("You still have not collected all collectibles.");
		return (1);
	}
	else if (letter == 'E' && game->collectibles == 0)
		game->exit = TRUE;
	return (0);
}
