/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:30:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/13 20:51:41 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define WIDTH 512
#define HEIGHT 512
#define TILE_SIZE 64
#define MAP_WIDTH 8
#define MAP_HEIGHT 8


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

// create a function which draws a line from coordinates (x1, y1) to (x2, y2).
void	draw_line_from_to(mlx_image_t *img, int x1, int y1, int x2, int y2, uint32_t color)
{
	int		delta_x;
	int		delta_y;
	int		error;
	int		delta_error;
	int		y;
	int		x;

	printf("Trying to draw a line from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	error = 0;
	delta_error = abs(delta_y / delta_x);
	y = y1;
	for (x = x1; x < x2; x++)
	{
		mlx_put_pixel(img, x, y, color);
		error += delta_error;
		if (error >= 0.5)
		{
			y += 1;
			error -= 1;
		}
	}
}


void	calculate_3d_rays(t_player *player)
{
	float	aTan;

	player->ra = player->angle;
	for (int r = 0; r < 1; r++)
	{
		player->dof = 0;
		aTan = -1 / tan(player->ra);
		if (player->ra > M_PI)
		{
			player->ry = (((int)player->player_images->instances[0].y >> 6) << 6) - 0.0001;
			player->rx = (player->player_images->instances[0].y - player->ry) * aTan + player->player_images->instances[0].x;
			player->yo = -64;
			player->xo = -player->yo * aTan;
			printf("Arrived here.\n");
		}
		else if (player->ra < M_PI)
		{
			player->ry = (((int)player->player_images->instances[0].y >> 6) << 6) + 64;
			player->rx = (player->player_images->instances[0].y - player->ry) * aTan + player->player_images->instances[0].x;
			player->yo = 64;
			player->xo = -player->yo * aTan;
			printf("Arrived here2.\n");
		}
		else if (player->ra == 0 || player->ra == M_PI)
		{
			player->rx = player->player_images->instances[0].x;
			player->ry = player->player_images->instances[0].y;
			player->dof = 8;
			printf("Arrived here3.\n");
		}
		while (player->dof < 8)
		{
			player->mx = (int)(player->rx) >> 6;
			player->my = (int)(player->ry) >> 6;
			player->mp = (player->my * MAP_WIDTH) + player->mx;
			if (player->mp > 0 && player->mp < MAP_WIDTH * MAP_HEIGHT && map[player->mp] == 1)
				player->dof = 8;
			else
			{
				player->rx += player->xo;
				player->ry += player->yo;
				player->dof += 1;
			}
		}
		// draw_line_from_to(player->player_images, player->player_images->instances[0].x, player->player_images->instances[0].y, player->rx, player->ry, 0x00FF00FF);
	}
}


void	draw_line(t_game *game)
{
	float x;
	float y;

	game->player->player_line = mlx_new_image(game->mlx, 50, 50);
	if (!game->player->player_line)
		return ;
	for (int i = 0; i < 20; i++)
	{
		x = cos(game->player->angle) * i; // the cos of the angle is the x component of the distance from the player to the wall.
		y = sin(game->player->angle) * i; // the sin of the angle is the y component of the distance from the player to the wall.
		mlx_put_pixel(game->player->player_line, (x+20), (y+20), 0xFFFFFFFF); // the player is at (25, 25). the desired endpoint is at (50, 50). the distance from the player to the wall is 25.
	}

	mlx_image_to_window(game->mlx, game->player->player_line, game->player->player_images->instances[0].x - 10, game->player->player_images->instances[0].y - 10);
}


t_player	*create_player(t_game *game, int pos_x, int pos_y, float angle)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player_images = mlx_new_image(game->mlx, 20, 20);
	if (!player->player_images)
		return (NULL);
	player->angle = angle;
	player->delta_x = cos(player->angle) * 5;
	player->delta_y = sin(player->angle) * 5;
	for (int y = 0; y < 20; y++)
		for (int x = 0; x < 20; x++)
			mlx_put_pixel(player->player_images, x, y, 0x00FF00FF);

	if (mlx_image_to_window(game->mlx, player->player_images, pos_x, pos_y) < 0)
		return (NULL);
	game->player = player;
	draw_line(game);
	return (player);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		{
			mlx_close_window(game->mlx);
			mlx_terminate(game->mlx);
			exit(EXIT_FAILURE);
			return ;
		}
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
		printf("Subtracting 0.1 radians from angle.\nPlayer Angle Before: %f\n", game->player->angle);
		game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle = ((2 * M_PI) - 0.1);
		printf("Player Angle After: %f\n", game->player->angle);
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
		printf("Delta x: %f\n", game->player->delta_x);
		printf("Delta y: %f\n", game->player->delta_y);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		printf("Adding +0.1 radians to angle\nPlayer Angle Before: %f\n", game->player->angle);
		game->player->angle += 0.1;
		if (game->player->angle > 2 * M_PI)
			game->player->angle = 0.1;
		printf("Player Angle After: %f\n", game->player->angle);
		game->player->delta_x = cos(game->player->angle) * 5;
		game->player->delta_y = sin(game->player->angle) * 5;
		printf("Delta x: %f\n", game->player->delta_x);
		printf("Delta y: %f\n", game->player->delta_y);
	}
	x = game->player->player_images->instances[0].x;
	y = game->player->player_images->instances[0].y;
	mlx_delete_image(game->mlx, game->player->player_line);
	mlx_delete_image(game->mlx, game->player->player_images);
	create_player(game, x, y, game->player->angle);
	(void)(key);
}

int	create_map(mlx_t *mlx)
{
	int			tile;
	uint32_t	color;

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			tile = map[(y * MAP_HEIGHT) + x];
			color = tile == 1 ? 0xFF0000FF : 0x000000FF;
			mlx_image_t *img = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
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

float	deg2rad(float deg)
{
	return ((deg * M_PI) / 180);
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

	t_player *player = create_player(game, WIDTH/2, HEIGHT/2, 0);
	if (!player)
		return (printf("Error creating player.\n"), -1);

	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	free(game->player);
	free(game);
	return (0);
}


