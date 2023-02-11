/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:58:41 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/11 20:14:15 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Creates game assets and associates them to the game window. 
void	load_assets(t_game *game)
{
	game->assets.wall = asset_to_image(game, "./CuteRPG/wal.png", 0);
	game->assets.character = asset_to_image(game, "./CuteRPG/player.png", 1);
	game->assets.exit = asset_to_image(game, "./CuteRPG/exit.png", 2);
	game->assets.collectible = asset_to_image(game, "./CuteRPG/collectible.png", 3);
	game->assets.floor = asset_to_image(game, "./CuteRPG/floor.png", 4);
}

// Turns a png into an image capable of being displayed in game window.
mlx_image_t	*asset_to_image(t_game *game, char *img_path, int i)
{
	mlx_texture_t	*texture;
	mlx_image_t	*img;

	texture = mlx_load_png(img_path);
	if (!texture)
	{
		free_images_and_textures(game);
		ft_error_message("Shit", 1);
	}
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
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		ft_error_message("Shit2", 1);
	return (img);
}

// Frees all previously allocated assets.
void	free_images_and_textures(t_game *game)
{
	if (game->assets.texture_wall != NULL)
		mlx_delete_texture(game->assets.texture_wall);
	if (game->assets.texture_character != NULL)
		mlx_delete_texture(game->assets.texture_character);
	if (game->assets.texture_exit != NULL)
		mlx_delete_texture(game->assets.texture_exit);
	if (game->assets.texture_collectible != NULL)
		mlx_delete_texture(game->assets.texture_collectible);
	if (game->assets.texture_floor != NULL)
		mlx_delete_texture(game->assets.texture_floor);
	if (game->assets.character != NULL)
		mlx_delete_image(game->mlx, game->assets.character);
	if (game->assets.floor != NULL)
		mlx_delete_image(game->mlx, game->assets.floor);
	if (game->assets.exit != NULL)
		mlx_delete_image(game->mlx, game->assets.exit);
	if (game->assets.collectible != NULL)
		mlx_delete_image(game->mlx, game->assets.collectible);
	if (game->assets.wall != NULL)
		mlx_delete_image(game->mlx, game->assets.wall);
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
		mlx_image_to_window(game->mlx, game->assets.floor, column * 32, row * 32);
	if (game->map[row][column] == '1')
		mlx_image_to_window(game->mlx, game->assets.wall, column * 32, row * 32);
	else if (game->map[row][column] == 'E')
		mlx_image_to_window(game->mlx, game->assets.exit, column * 32, row * 32);
	else if (game->map[row][column] == 'P')
		mlx_image_to_window(game->mlx, game->assets.character, column * 32, row * 32);
	else if (game->map[row][column] == 'C')
		mlx_image_to_window(game->mlx, game->assets.collectible, column * 32, row * 32);
}
