/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:30:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/09 01:08:29 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define TILE_SIZE 32


// MLX42 Logic:
// An image is just an empty canvas.
// You can draw on it with mlx_put_pixel.
// Putting pixels requires looping through the image's data array.
// Once the image has been drawn on, you can display it in a window with mlx_image_to_window.

void	draw_line(t_game *game)
{
	float			xn;
	float			yn;
	float			p_x;
	float			p_y;
	// float		aTan;
	// float		y_offset;
	// float		x_offset;

	p_x = game->player->player_images->instances[0].x + (game->player->size / 2);
	p_y = game->player->player_images->instances[0].y + (game->player->size / 2);
	// aTan = -1/tan(game->player->angle);
	printf("Ray is starting at coordinates (%f, %f)\n", p_x, p_y);
	if (game->player->angle < M_PI && game->player->angle > M_PI / 2) // ray is facing top-left
	{
		printf("Ray is facing top-left.\n");
		yn = floor((double)p_y / TILE_SIZE) * TILE_SIZE;
		xn = p_x + -(TILE_SIZE - (yn + TILE_SIZE - p_y));
		printf("Yn: %f\n", yn);
		printf("xn: %f\n", xn);
	}
	else if (game->player->angle > 0 && game->player->angle < M_PI / 2) // ray is facting top-right
	{
		printf("Ray is facing top-right\n");
		yn = p_y - (floor((double)p_y / TILE_SIZE) * TILE_SIZE);
		// yn = p_y - yn;
		xn = yn / tan(game->player->angle);
		yn = p_y - yn;
		xn = p_x + xn;
		printf("Yn: %f\n", yn);
		printf("xn: %f\n", xn);
	}
	else if (game->player->angle > M_PI && game->player->angle < (1.5 * M_PI)) // ray is facing bottom-left.
	{
		printf("Ray is facing bottom-left.\n");
		yn = round((double)p_y / TILE_SIZE) * TILE_SIZE;
		xn = p_x + -(TILE_SIZE - (yn + TILE_SIZE - p_y));
		printf("Yn: %f\n", yn);
		printf("xn: %f\n", xn);
	}
	else // ray is facing bottom-right
	{
		printf("Ray is facing bottom-right.\n");
		yn = ceil((double)p_y / TILE_SIZE) * TILE_SIZE;
		xn = (-(tan(game->player->angle)) * (yn - p_y)) + p_x;
		printf("Yn: %f\n", yn);
		printf("xn: %f\n", xn);
	}
	game->player->player_line = mlx_new_image(game->mlx, (TILE_SIZE) * game->map->largest_row, (TILE_SIZE) * (game->map->height));
	if (!game->player->player_line)
		return ;
	int x_target = xn;
	int y_target = yn;
	printf("Target Coordinates: (%d, %d)\n", x_target, y_target);
	mlx_put_pixel(game->player->player_line, p_x, p_y, 0xFF0000FF);
	printf("Current Coordinates: (%f, %f)\n", p_x, p_y);
	while (p_x != x_target || p_y != y_target)
	{
		if (p_x > x_target)
			p_x -= 0.5;
		else if (p_x < x_target)
			p_x += 0.5;
		else
			;
		if (p_y > y_target)
			p_y -= 0.5;
		else if (p_y < y_target)
			p_y += 0.5;
		else
			;
		mlx_put_pixel(game->player->player_line, p_x, p_y, 0xFF0000FF);
		printf("Current Coordinates: (%f, %f)\n", p_x, p_y);
	}
	// float ys = TILE_SIZE;
	// // float xs = ys / tan(game->player->angle);
	// // float xx_target = p_x + xs;
	// // float yy_target = p_y + ys;
	// // printf("New Target Coordinates: (%f, %f)\n", xx_target, yy_target);
	// // while (p_x != xx_target && p_y != yy_target)
	// // {
	// // 	if (p_x != xx_target)
	// // 		p_x++;
	// // 	if (p_y != yy_target)
	// // 		p_y++;
	// // 	mlx_put_pixel(game->player->player_line, p_x, p_y, 0xFF0000FF);
	// // }

	if (mlx_image_to_window(game->mlx, game->player->player_line, 0, 0) < 0)
		return ;
}



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

t_player	*create_player(t_game *game, int column, int row, double angle)
{
	t_player	*player;
	int			i;
	int			j;

	i = 0;
	j = 0;
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->size = 16;
	player->player_images = mlx_new_image(game->mlx, player->size, player->size);
	if (!player->player_images)
		return (NULL);
	player->angle = angle;
	player->pos_x = game->map->player_row;
	player->pos_y = game->map->player_column;
	// player->delta_x = cos(player->angle) * 5;
	// player->delta_y = sin(player->angle) * 5;
	while (i < player->size)
	{
		while (j < player->size)
		{
			mlx_put_pixel(player->player_images, i, j, 0x00bb00FF);
			j++;
		}
		i++;
		j = 0;
	}
	if (mlx_image_to_window(game->mlx, player->player_images,
			(TILE_SIZE) * column, (TILE_SIZE) * row) < 0)
		return (NULL);
	game->player = player;
	draw_line(game);
	return (player);
}

void	create_tiles(mlx_image_t *img, uint32_t color)
{
	int			tx;
	int			ty;
	uint32_t	og_color;

	tx = 0;
	ty = 0;
	og_color = color;
	while (ty < TILE_SIZE)
	{
		while (tx < TILE_SIZE)
		{
			if (ty == TILE_SIZE - 1 || tx == 0)
				color = 0x000022FF;
			else
				color = og_color;
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
	while (y < game->map->height)
	{
		while (x < get_row_width(game, map, y))
		{
			tile = map[y][x];
			color = 0xFFFFFFFF;
			if (tile == '1')
				color = 0xFF000000;
			img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
			if (!img)
				return (printf("Error:\n Unable to create image.\n"), false);
			create_tiles(img, color);
			if (mlx_image_to_window(game->mlx,
					img, x * (TILE_SIZE), y * (TILE_SIZE)) < 0)
				return (printf("Error displaying image.\n"), false);
			x++;
		}
		x = 0;
		y++;
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
	game->mlx = mlx_init((TILE_SIZE) * game->map->largest_row, (TILE_SIZE) * (game->map->height), "Map", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	if (create_map(game, 0, 0) != true)
		return (printf("Error:\n Unable to create map.\n"), EXIT_FAILURE);
	player = create_player(game, game->map->player_column,
			game->map->player_row, 0.175);
	if (!player)
		return (printf("Error creating player.\n"), -1);
	mlx_loop(game->mlx);


	// mlx_key_hook(game->mlx, key_hook, game);
	// free(game->player);
	// free(game->map);
	// free(game);
	return (0);
}


