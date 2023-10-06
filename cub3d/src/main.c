/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:30:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/06 23:54:28 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define TILE_SIZE 32


// MLX42 Logic:
// An image is just an empty canvas.
// You can draw on it with mlx_put_pixel.
// Putting pixels requires looping through the image's data array.
// Once the image has been drawn on, you can display it in a window with mlx_image_to_window.

// void	draw_line(t_game *game)
// {
// 	float	i;
// 	float	yn;
// 	float	xn;
// 	float	pos_x;
// 	float	pos_y;
// 	float	tangent;

// 	game->player->player_line = mlx_new_image(game->mlx, WIDTH, HEIGHT);
// 	pos_x = game->player->player_images->instances[0].x;
// 	pos_y = game->player->player_images->instances[0].y;
// 	if (!game->player->player_line)
// 		return ;
// 	i = 0;
// 	tangent = tan(game->player->angle);
// 	yn = 0;
// 	while (i < WIDTH * 2)
// 	{
// 		if (tangent != 0)
// 		{
// 			yn = -(game->player->player_images->instances[0].y - (int)(game->player->player_images->instances[0].y / TILE_SIZE) * TILE_SIZE);
// 			xn = yn / tangent;
// 			if (yn >= HEIGHT || xn >= WIDTH)
// 				;
// 			else
// 			{
// 				while (pos_x != xn + game->player->player_images->instances[0].x)
// 				{
// 					mlx_put_pixel(game->player->player_line, pos_x, pos_y, 0xFFFFFFFF);
// 					pos_x += 0.1;
// 				}
// 			}
// 			mlx_put_pixel(game->player->player_line, xn + game->player->player_images->instances[0].x, (yn + game->player->player_images->instances[0].y), 0xFFFFFFFF);
// 			printf("Horizontal || Put pixel at (%f, %f)\n", xn + game->player->player_images->instances[0].x, yn + game->player->player_images->instances[0].y);
// 		}
// 		else if (tangent != 1)
// 		{
// 			xn = -(game->player->player_images->instances[0].x - (int)(game->player->player_images->instances[0].x / TILE_SIZE) * TILE_SIZE);
// 			yn = tangent * xn;
// 			if (yn >= HEIGHT || xn >= WIDTH)
// 				;
// 			else
// 				mlx_put_pixel(game->player->player_line, xn + game->player->player_images->instances[0].x, yn + game->player->player_images->instances[0].y, 0xFFFFFFFF);
// 			printf("Vertical || Put pixel at (%f, %f)\n", xn + game->player->player_images->instances[0].x, yn + game->player->player_images->instances[0].y);
// 		}
// 		i++;
// 	}
// 	mlx_image_to_window(game->mlx, game->player->player_line, 0, 0);
// }

// // every tile is 64x64 pixels.
// // i am at a certain coordinate. If i move by 64 pixels in any direction, i am now in a new tile.
// // If i am in a new tile, I need to check if this tile is a wall.
// // If i am a wall, i need to stop drawing pixels and end it there.


// void	key_hook(mlx_key_data_t key, void *param)
// {
// 	t_game	*game;
// 	int		x;
// 	int		y;

// 	game = param;

// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		{
// 			mlx_close_window(game->mlx);
// 			mlx_terminate(game->mlx);
// 			exit(EXIT_FAILURE);
// 			return ;
// 		}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 	{
// 		game->player->player_images->instances[0].x += game->player->delta_x;
// 		game->player->player_images->instances[0].y += game->player->delta_y;
// 		printf("Final: Coordinates: (%d, %d)\n", game->player->player_images->instances[0].x, game->player->player_images->instances[0].y);
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 	{
// 		game->player->player_images->instances[0].x -= (game->player->delta_x);
// 		game->player->player_images->instances[0].y -= (game->player->delta_y);
// 		printf("Final: Coordinates: (%d, %d)\n", game->player->player_images->instances[0].x, game->player->player_images->instances[0].y);
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 	{
// 		printf("Subtracting 0.1 radians from angle.\nPlayer Angle Before: %f\n", game->player->angle);
// 		game->player->angle -= 0.1;
// 		if (game->player->angle < 0)
// 			game->player->angle = ((2 * M_PI) - 0.1);
// 		printf("Player Angle After: %f\n", game->player->angle);
// 		game->player->delta_x = cos(game->player->angle) * 5;
// 		game->player->delta_y = sin(game->player->angle) * 5;
// 		printf("Delta x: %f\n", game->player->delta_x);
// 		printf("Delta y: %f\n", game->player->delta_y);
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 	{
// 		printf("Adding +0.1 radians to angle\nPlayer Angle Before: %f\n", game->player->angle);
// 		game->player->angle += 0.1;
// 		if (game->player->angle > 2 * M_PI)
// 			game->player->angle = 0.1;
// 		printf("Player Angle After: %f\n", game->player->angle);
// 		game->player->delta_x = cos(game->player->angle) * 5;
// 		game->player->delta_y = sin(game->player->angle) * 5;
// 		printf("Delta x: %f\n", game->player->delta_x);
// 		printf("Delta y: %f\n", game->player->delta_y);
// 	}
// 	x = game->player->player_images->instances[0].x;
// 	y = game->player->player_images->instances[0].y;
// 	mlx_delete_image(game->mlx, game->player->player_line);
// 	mlx_delete_image(game->mlx, game->player->player_images);
// 	create_player(game, x, y, game->player->angle);
// 	(void)(key);
// }

t_player	*create_player(t_game *game, int column, int row, float angle)
{
	t_player	*player;
	int			i;
	int			j;

	i = -1;
	j = -1;
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player_images = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!player->player_images)
		return (NULL);
	player->angle = angle;
	player->delta_x = cos(player->angle) * 5;
	player->delta_y = sin(player->angle) * 5;
	while (++i < TILE_SIZE)
	{
		while (++j < TILE_SIZE)
			mlx_put_pixel(player->player_images, i, j, 0xFFFF00FF);
		j = 0;
	}
	if (mlx_image_to_window(game->mlx, player->player_images,
			(TILE_SIZE + 1) * column, (TILE_SIZE + 1) * row) < 0)
		return (NULL);
	game->player = player;
	// draw_line(game);
	return (player);
}

void	create_tiles(mlx_image_t *img, uint32_t color)
{
	int	tx;
	int	ty;

	tx = 0;
	ty = 0;
	while (ty < TILE_SIZE)
	{
		while (tx < TILE_SIZE)
		{
			mlx_put_pixel(img, tx, ty, color);
			tx++;
		}
		tx = 0;
		ty++;
	}
}

bool	create_map(t_game *game, int x, int y)
{
	int			**map;
	int			tile;
	uint32_t	color;
	mlx_image_t	*img;

	map = game->map->map_2d;
	while (++y < game->map->height)
	{
		while (++x < get_row_width(game, map, y))
		{
			tile = map[y][x];
			color = 0x00000000;
			if (tile == '1')
				color = 0xffffffff;
			img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
			if (!img)
				return (printf("Error:\n Unable to create image.\n"), false);
			create_tiles(img, color);
			if (mlx_image_to_window(game->mlx,
					img, x * (TILE_SIZE + 1), y * (TILE_SIZE + 1)) < 0)
				return (printf("Error displaying image.\n"), false);
		}
		x = 0;
	}
	return (true);
}

void	init_map(t_game *game, char *map)
{
	int	len;

	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		printf("Malloc fail\n");
		exit(EXIT_FAILURE);
	}
	len = get_num_lines_file(map);
	game->map->num_lines_file = len;
	game->map->map_2d = malloc(sizeof(int *) * len);
	if (!game->map->map_2d)
	{
		printf("Malloc fail\n");
		exit(EXIT_FAILURE);
	}
	game->map->player_count = 0;
	game->map->no_texture = NULL;
	game->map->so_texture = NULL;
	game->map->we_texture = NULL;
	game->map->ea_texture = NULL;
	game->map->floor_color_string = NULL;
	game->map->ceiling_color_string = NULL;
	game->map->direction = '\0';
	game->map->height = 0;
	game->map->largest_row = 0;
}

int main(int argc, char **argv)
{
	t_game		*game;
	t_player	*player;

	if (argc > 2)
		return (printf("Error: Too many arguments.\n"), -1);
	else if (argc < 2)
		return (printf("Error: Missing map argument.\n"), -1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (printf("Error:\n Malloc failed.\n"), EXIT_FAILURE);
	init_map(game, argv[1]);
	if (!check_valid_map(game, argv[1]))
		return (EXIT_FAILURE);
	printf("Map is valid.\n");
	game->mlx = mlx_init((TILE_SIZE + 1) * game->map->largest_row, (TILE_SIZE + 1) * (game->map->height), "Map", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	if (create_map(game, -1, -1) != true)
		return (printf("Error:\n Unable to create map.\n"), EXIT_FAILURE);
	print_map_2d(game);
	player = create_player(game, game->map->player_column,
			game->map->player_row, 0);
	if (!player)
		return (printf("Error creating player.\n"), -1);
	mlx_loop(game->mlx);


	// mlx_key_hook(game->mlx, key_hook, game);
	// free(game->player);
	// free(game->map);
	// free(game);
	return (0);
}


