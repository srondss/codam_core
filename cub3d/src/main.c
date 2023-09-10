/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:30:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/10 20:20:18 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define WIDTH 1024
#define HEIGHT 512
#define TILE_SIZE 64
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define PI 3.1415926535


// MLX42 Logic:
// An image is just an empty canvas.
// You can draw on it with mlx_put_pixel.
// Putting pixels requires looping through the image's data array.
// Once the image has been drawn on, you can display it in a window with mlx_image_to_window.

int map[] =
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};

t_player	*create_player(t_game *game, int x, int y, float angle)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player_images = mlx_new_image(game->mlx, 50, 50);
	if (!player->player_images)
		return (NULL);
	player->angle = angle;
	player->delta_x = cos(player->angle) * 5;
	player->delta_y = sin(player->angle) * 5;
	for (int y = 15; y < 35; y++)
		for (int x = 15; x < 35; x++)
			mlx_put_pixel(player->player_images, x, y, 0x00FF00FF);

	// draw a line that rotates with the player to show the direction they're facing
	float a_x;
	float a_y;
	for (int i = 0; i < 25; i++)
	{
		a_x = cos(player->angle) * i;
		a_y = sin(player->angle) * i;
		mlx_put_pixel(player->player_images, (a_x + 25), (a_y + 25), 0xFFFFFFFF);
	}

	if (mlx_image_to_window(game->mlx, player->player_images, x, y) < 0)
		return (NULL);
	game->player = player;
	return (player);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		game->player->player_images->instances[0].x += game->player->delta_x;
		game->player->player_images->instances[0].y += game->player->delta_y;
		printf("Final: Coordinates: (%d, %d)\n", game->player->player_images->instances[0].x, game->player->player_images->instances[0].y);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		game->player->player_images->instances[0].x -= (game->player->delta_x);
		game->player->player_images->instances[0].y -= (game->player->delta_y);
		printf("Final: Coordinates: (%d, %d)\n", game->player->player_images->instances[0].x, game->player->player_images->instances[0].y);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle += (2 * M_PI);
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
		printf("Delta x: %f\n", game->player->delta_x);
		printf("Delta y: %f\n", game->player->delta_y);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player->angle += 0.1;
		if (game->player->angle > 2 * M_PI)
			game->player->angle -= (2 * M_PI);
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
		printf("Delta x: %f\n", game->player->delta_x);
		printf("Delta y: %f\n", game->player->delta_y);
	}
	x = game->player->player_images->instances[0].x;
	y = game->player->player_images->instances[0].y;
	mlx_delete_image(game->mlx, game->player->player_images);
	create_player(game, x, y, game->player->angle);
	(void)(key);
}

int	create_map(mlx_t *mlx)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			int tile = map[(y * MAP_HEIGHT) + x];
			uint32_t color = tile == 1 ? 0xFF0000FF : 0x000000FF;

			mlx_image_t *img = mlx_new_image(mlx, TILE_SIZE - 1, TILE_SIZE - 1);
			if (!img)
			{
				printf("Error creating image.\n");
				return (0);
			}

			for (int ty = 0; ty < TILE_SIZE; ty++)
				for (int tx = 0; tx < TILE_SIZE; tx++)
					mlx_put_pixel(img, tx, ty, color);

			if (mlx_image_to_window(mlx, img, x * (TILE_SIZE + 1), y * (TILE_SIZE + 1)) < 0)
			{
				printf("Error displaying image.\n");
				return (0);
			}
		}
	}
	return (1);
}

int main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init(WIDTH, HEIGHT, "Map", true);
	if (!game->mlx)
		return (-1);

	bool m_success = create_map(game->mlx);
	if (!m_success)
		return (printf("Error creating map.\n"), -1);

	t_player *player = create_player(game, 300, 300, 0);
	if (!player)
		return (printf("Error creating player.\n"), -1);

	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	free(game->player);
	free(game);
	return (0);
}


