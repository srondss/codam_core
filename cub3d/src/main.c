/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:30:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/02 09:55:49 by ysrondy          ###   ########.fr       */
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

// t_player	*create_player(t_game *game, int pos_x, int pos_y, float angle)
// {
// 	t_player	*player;

// 	player = malloc(sizeof(t_player));
// 	if (!player)
// 		return (NULL);
// 	player->player_images = mlx_new_image(game->mlx, 20, 20);
// 	if (!player->player_images)
// 		return (NULL);
// 	player->angle = angle;
// 	player->delta_x = cos(player->angle) * 5;
// 	player->delta_y = sin(player->angle) * 5;
// 	for (int y = 0; y < 20; y++)
// 		for (int x = 0; x < 20; x++)
// 			mlx_put_pixel(player->player_images, x, y, 0x00FF00FF);

// 	if (mlx_image_to_window(game->mlx, player->player_images, pos_x, pos_y) < 0)
// 		return (NULL);
// 	game->player = player;
// 	draw_line(game);
// 	return (player);
// }

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

// int	create_map(t_game *game)
// {
// 	int			**map;
// 	int			tile;
// 	uint32_t	color;

// 	map = malloc(sizeof(int *) * MAP_HEIGHT);

// 	for (int y = 0; y < MAP_HEIGHT; y++)
// 	{
// 		for (int x = 0; x < MAP_WIDTH; x++)
// 		{
// 			tile = input_map[(y * MAP_HEIGHT) + x];
// 			if (tile == 1)
// 			{
// 				color = 0xFF0000FF;
// 			}
// 			else
// 			{
// 				color = 0x000000FF;
// 			}
// 			mlx_image_t *img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
// 			if (!img)
// 			{
// 				printf("Error creating image.\n");
// 				return (0);
// 			}
// 			for (int ty = 0; ty < TILE_SIZE; ty++)
// 				for (int tx = 0; tx < TILE_SIZE; tx++)
// 					mlx_put_pixel(img, tx, ty, color);
// 			if (mlx_image_to_window(game->mlx, img, x * (TILE_SIZE + 1), y * (TILE_SIZE + 1)) < 0)
// 			{
// 				printf("Error displaying image.\n");
// 				return (0);
// 			}
// 		}
// 	}
// 	game->map = map;
// 	return (1);
// }

// TODO: Handle tabs because they mess up the map parsing.
// Why? Because they take up 4 spaces but are only 1 character.

int	position_player_x(int **map_2d, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height && game->map->map_2d[i])
	{
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'N' || map_2d[i][j] == 'S' || map_2d[i][j] == 'W' || map_2d[i][j] == 'E' || map_2d[i][j] == 'P')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int	position_player_y(int **map_2d, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height && game->map->map_2d[i])
	{
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'N' || map_2d[i][j] == 'S' || map_2d[i][j] == 'W' || map_2d[i][j] == 'E' || map_2d[i][j] == 'P')
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

void	print_map_2d(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height && game->map->map_2d[i])
	{
		while ((game->map->map_2d[i][j]) != '\0')
		{
			printf("%c", game->map->map_2d[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}

bool	find_path_exit(t_game *game, int **map_2d)
{
	int	x;
	int	y;

	x = position_player_x(map_2d, game);
	y = position_player_y(map_2d, game);
	printf("Player is at (%d,%d)\n", x, y);
	print_map_2d(game);
	if (x == -1 || y == -1)
	{
		printf("Player is indeed surrounded by walls.\n");
		return (true);
	}
	if (map_2d[x + 1][y] == '\0' || map_2d[x - 1][y] == '\0'
			|| map_2d[x][y + 1] == '\0' || map_2d[x][y - 1] == '\0'
			|| map_2d[x + 1][y] == ' ' || map_2d[x - 1][y] == ' '
			|| map_2d[x][y + 1] == ' ' || map_2d[x][y - 1] == ' ')
		{
			printf("Player is not surrounded by walls at (%d,%d).\n", x, y);
			printf("%c %c %c %c\n", map_2d[x + 1][y], map_2d[x - 1][y], map_2d[x][y + 1], map_2d[x][y - 1]);
			return (false);
		}
	if (map_2d[x + 1][y] == '0')
		map_2d[x + 1][y] = 'P';
	if (map_2d[x - 1][y] == '0')
		map_2d[x - 1][y] = 'P';
	if (map_2d[x][y + 1] == '0')
		map_2d[x][y + 1] = 'P';
	if (map_2d[x][y - 1] == '0')
		map_2d[x][y - 1] = 'P';
	map_2d[x][y] = 'X';
	printf("\n\n");
	return (find_path_exit(game, map_2d));
}

bool	check_map_line(t_game *game, char *line)
{
	static int	counter = 0;
	int			i;
	int			*line_2d;

	i = 0;
	line_2d = malloc(sizeof(int) * (ft_strlen(line) + 1));
	if (!line_2d)
		return (false);
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (line[i] != '1' && line[i] != '0')
				return (false);
		}
		if (ft_isalpha(line[i]))
		{
			if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
				return (false);
			else
			{
				game->map->direction = line[i];
				game->map->player_count++;
				if (game->map->player_count > 1)
					return (false);
			}
		}
		line_2d[i] = line[i];
		i++;
	}
	line_2d[i] = '\0';
	game->map->map_2d[counter] = line_2d;
	counter++;
	game->map->height = counter;
	return (true);
}

void	parse_cub_file(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		i;
	bool	found_map;

	i = 0;
	fd = open(map, O_RDONLY);
	found_map = false;
	if (fd < 0)
	{
		printf("Error: Unable to open specified map.\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error: Something went wrong while trying to read map.\n");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		printf("%s", line);
		while (is_whitespace(line[i]))
			i++;
		printf("Line[i] = %c\n", line[i]);
		if (line[i] == 'N' && line[i + 1] == 'O')
		{
			if (check_no_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'S' && line[i + 1] == 'O')
		{
			if (check_so_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'W' && line[i + 1] == 'E')
		{
			if (check_we_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'E' && line[i + 1] == 'A')
		{
			if (check_ea_texture(game, line, i + 2, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'F')
		{
			if (check_floor_color(game, line, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'C')
		{
			if (check_ceiling_color(game, line, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == '\0')
			printf("Found empty line.\n");
		else if (ft_isdigit(line[i]))
		{
			printf("Found map.\n");
			found_map = true;
			if (check_map_line(game, line) == false)
			{
				printf("Error: Invalid map line: %s\n", line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("Found invalid line: %s", line);
			exit(EXIT_FAILURE);
		}
		free(line);
		i = 0;
		line = get_next_line(fd);
	}
	close(fd);
}

bool	check_valid_map(t_game *game, char *map)
{
	if (map == NULL)
		return (printf("Error: No map file specified.\n"), false);
	else if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		return (printf("Error: Invalid map file specified.\n"), false);
	parse_cub_file(game, map);
	if (game->map->player_count == 0)
		return (printf("Error: Invalid player count of %d.\n", game->map->player_count), false);
	return (find_path_exit(game, game->map->map_2d));
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
}

// TODO: Handle map parsing where row[x][y] == 0 && row[x + 1][y] == ' '. This is a potentially valid map because there may be a wall at row[x + 2][y].
// In order to handle this edge case, we need to loop through all the rows from x to the last row and check if there is a '1' at the same y coordinate.
// If there is no '1' at the same y coordinate, then the map is invalid.
// If there is a '1' at the same y coordinate, then the map is potentially valid assuming there are no other '0' values in subsequent rows.

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc > 2)
		return (printf("Error: Too many arguments.\n"), -1);
	else if (argc < 2)
		return (printf("Error: Missing map argument.\n"), -1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	init_map(game, argv[1]);
	if (!check_valid_map(game, argv[1]))
		return (EXIT_FAILURE);
	printf("Map is valid.\n");
	return (EXIT_SUCCESS);
	// game->mlx = mlx_init(WIDTH, HEIGHT, "Map", true);
	// if (!game->mlx)
	// 	return (EXIT_FAILURE);
	// bool m_success = create_map(game);
	// if (!m_success)
	// 	return (printf("Error creating map.\n"), -1);

	// t_player *player = create_player(game, WIDTH/2, HEIGHT/2, 0);
	// if (!player)
	// 	return (printf("Error creating player.\n"), -1);

	// mlx_key_hook(game->mlx, key_hook, game);
	// mlx_loop(game->mlx);
	// free(game->player);
	// free(game->map);
	// free(game);
	return (0);
}


