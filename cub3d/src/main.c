/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:30:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/23 22:49:58 by ysrondy          ###   ########.fr       */
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

// float	deg2rad(float deg)
// {
	// return ((deg * M_PI) / 180);
// }

bool	is_whitespace(char c)
{
	if (c == '\f' || c == ' ' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (true);
	else
		return (false);
}

bool	check_no_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->no_texture = ft_substr(line, i, j);
	printf("Found NO texture: %s\n", game->map->no_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid NO_Texture line.\n"), false);
	return (true);
}

bool	check_so_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->so_texture = ft_substr(line, i, j);
	printf("Found SO texture: %s\n", game->map->so_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid SO_Texture line.\n"), false);
	return (true);
}

bool	check_we_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->we_texture = ft_substr(line, i, j);
	printf("Found WE texture: %s\n", game->map->we_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid WE_Texture line.\n"), false);
	return (true);
}

bool	check_ea_texture(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->ea_texture = ft_substr(line, i, j);
	printf("Found EA texture: %s\n", game->map->ea_texture);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid EA_Texture line.\n"), false);
	return (true);
}

bool	check_floor_color(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->floor_color = ft_substr(line, i, j);
	printf("Found Floor Color: %s\n", game->map->floor_color);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid Floor_Color line.\n"), false);
	return (true);
}

bool	check_ceiling_color(t_game *game, char *line, int i, bool found_map)
{
	int	j;

	if (found_map)
		return (printf("Error: Map should be last element.\n"), false);
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (!is_whitespace(line[j]))
		j++;
	game->map->ceiling_color = ft_substr(line, i, j);
	printf("Found Ceiling Color: %s\n", game->map->ceiling_color);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] != '\0')
		return (printf("Error: Invalid Ceiling_Color line.\n"), false);
	return (true);
}

bool	check_map_line(t_game *game, char *line, int counter)
{
	int	i;
	int	*line_2d;

	i = 0;
	line_2d = malloc(sizeof(int) * ft_strlen(line));
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (line[i] != '1' && line[i] != '0')
				return (false);
			// TODO: FIX THIS COUNTER TO CHECK FOR LAST LINE OF MAP
			else if ((counter == 0 || counter == game->map->num_lines_file - counter) && (line[i] != '1' && !is_whitespace(line[i])))
			{
				printf("Counter: %d\n", counter);
				return (false);
			}
		}
		if (ft_isalpha(line[i]))
		{
			if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
				return (false);
			else
			{
				game->map->direction = line[i];
				game->map->player_count++;
			}
		}
		line_2d[i] = line[i] - '0';
		i++;
	}
	game->map->map_2d[counter] = line_2d;
	printf("Map_Line is correct: %s", line);
	return (true);
}

void	parse_cub_file(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		i;
	bool	found_map;
	int		counter;

	i = 0;
	counter = 0;
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
			if (check_floor_color(game, line, i + 1, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == 'C')
		{
			if (check_ceiling_color(game, line, i + 1, found_map) == false)
				exit(EXIT_FAILURE);
		}
		else if (line[i] == '\0')
			printf("Found empty line.\n");
		else if (ft_isdigit(line[i]))
		{
			printf("Found map.\n");
			found_map = true;
			if (check_map_line(game, line, counter) == false)
			{
				printf("Error: Invalid map line: %s\n", line);
				exit(EXIT_FAILURE);
			}
			counter++;
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
}

bool	check_valid_map(t_game *game, char *map)
{
	if (map == NULL)
		return (printf("Error: No map file specified.\n"), false);
	else if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4) != 0)
		return (printf("Error: Invalid map file specified.\n"), false);
	parse_cub_file(game, map);
	if (game->map->player_count == 0 || game->map->player_count > 1)
		return (printf("Error: Invalid player count.\n"), false);
	return (true);
}

int	get_num_lines_file(char *map)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Unable to open specified map.\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("Found %d lines in map.\n", counter);
	return (counter);
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


