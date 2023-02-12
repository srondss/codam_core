/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:58:41 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/12 15:31:32 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Creates game assets and associates them to the game window.
void	load_assets(t_game *game)
{
	init_assets(game);
	game->assets.wall = asset_to_image(game, "./CuteRPG/wall.png", 0);
	game->assets.character = asset_to_image(game, "./CuteRPG/player.png", 1);
	game->assets.exit = asset_to_image(game, "./CuteRPG/exit.png", 2);
	game->assets.collectible = asset_to_image(game,
			"./CuteRPG/collectible.png", 3);
	game->assets.floor = asset_to_image(game, "./CuteRPG/floor.png", 4);
}
// Turns a png into an image capable of being displayed in game window.

mlx_image_t	*asset_to_image(t_game *game, char *img_path, int i)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(img_path);
	if (!texture)
	{
		free_images_and_textures(game, 0);
		ft_error_message(E_IMAGE, 1);
	}
	set_texture(game, texture, i);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		free_images_and_textures(game, 0);
		ft_error_message(E_IMAGE, 1);
	}
	return (img);
}

void	set_texture(t_game *game, mlx_texture_t *texture, int i)
{
	if (i == 0)
		game->assets.texture_wall = texture;
	else if (i == 1)
		game->assets.texture_character = texture;
	else if (i == 2)
		game->assets.texture_exit = texture;
	else if (i == 3)
		game->assets.texture_collectible = texture;
	else if (i == 4)
		game->assets.texture_floor = texture;
}

//	hook which checks state of game and loads all images onto
//	the window at their respective positions if the game has not started yet.
void	load_images_to_window(t_game *game)
{
	int	column;
	int	row;

	row = 0;
	if (game->state == STATE_NULL)
	{
		while (row < game->rows)
		{
			column = 0;
			while (column < game->columns)
			{
				image_to_window(game, column, row);
				column++;
			}
			row++;
		}
		if (game->exit == TRUE)
			game_won(game);
	}
}

// Draw all images at their respective coordinates on the map.
void	image_to_window(t_game *game, int column, int row)
{
	if (column != 0 || row != 0)
		mlx_image_to_window(game->mlx, game->assets.floor,
			column * 32, row * 32);
	if (game->map[row][column] == '1')
		mlx_image_to_window(game->mlx, game->assets.wall,
			column * 32, row * 32);
	else if (game->map[row][column] == 'E')
		mlx_image_to_window(game->mlx, game->assets.exit,
			column * 32, row * 32);
	else if (game->map[row][column] == 'P')
		mlx_image_to_window(game->mlx, game->assets.character,
			column * 32, row * 32);
	else if (game->map[row][column] == 'C')
		mlx_image_to_window(game->mlx, game->assets.collectible,
			column * 32, row * 32);
}
