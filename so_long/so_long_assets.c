/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:58:41 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/06 21:47:25 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Creates game assets and associates them to the game window. 
void	load_assets(t_game *game)
{
	game->assets.wall = asset_to_image(game->mlx, "./CuteRPG/wall.png");
	game->assets.character = asset_to_image(game->mlx, "./CuteRPG/player.png");
	game->assets.exit = asset_to_image(game->mlx, "./CuteRPG/exit.png");
	game->assets.collectible = asset_to_image(game->mlx, "./CuteRPG/collectible.png");
	game->assets.floor = asset_to_image(game->mlx, "./CuteRPG/floor.png");
}

// Turns a png into an image capable of being displayed in game window.
mlx_image_t	*asset_to_image(mlx_t *mlx, char *img_path)
{
	mlx_texture_t	*texture;
	mlx_image_t	*img;

	texture = mlx_load_png(img_path);
	if (!texture)
		ft_printf("\n Could not load texture\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_printf("\n Something went wrong...\n");
	return (img);
}

// Frees all previously allocated assets.
void	free_old_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->old_assets.character);
	mlx_delete_image(game->mlx, game->old_assets.floor);
	mlx_delete_image(game->mlx, game->old_assets.exit);
	mlx_delete_image(game->mlx, game->old_assets.collectible);
	mlx_delete_image(game->mlx, game->old_assets.wall);
}

//	checks state of game and loads all images onto the window at their 
//	respective positions if the game has not started yet.
void	load_images_to_window(t_game *game)
{
	int	column;
	int	row;

	row = 0;
	if (game->state == STATE_NULL)
	{
		free_old_images(game);
		game->old_assets = game->assets;
		load_assets(game);
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
//	if (column != 0 || row != 0)
//		mlx_image_to_window(game->mlx, game->assets.floor, row * 32, column * 32);
	if (game->map[row][column] == '1')
		mlx_image_to_window(game->mlx, game->assets.wall, row * 32, column * 32);
	else if (game->map[row][column] == 'E')
		mlx_image_to_window(game->mlx, game->assets.exit, row * 32, column * 32);
	else if (game->map[row][column] == 'P')
		mlx_image_to_window(game->mlx, game->assets.character, row * 32, column * 32);
	else if (game->map[row][column] == 'C')
		mlx_image_to_window(game->mlx, game->assets.collectible, row * 32, column * 32);
//	if (row == 0 && column == 0) // NOT SURE WHY THIS IS NEEDED. 
//		mlx_image_to_window(game->mlx, game->assets.floor, row * 32, column * 32);
}
