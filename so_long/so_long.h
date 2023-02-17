/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:26:42 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/17 14:40:23 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <stdbool.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define E_MALLOC "Error with malloc.\n"
# define E_ARG "Invalid argument count.\n"
# define E_FILE "Map is empty.\n"
# define E_CHARACTER "Map contains something other than P, E, C, 0, or 1.\n"
# define E_CHARS "Map does not contain P, E, C, 0, and 1s.\n"
# define E_INVALIDMAP "Map is not a rectangle.\n"
# define E_WALLS "Map is not surrounded by walls.\n"
# define E_PATH "Player cannot reach exit.\n"
# define E_PATH_COLLECTIBLES "Player can't reach all collectibles.\n"
# define E_FORMAT "Format file not allowed.\n"
# define E_IMAGE "Image/Texture is incorrect.\n"

typedef struct s_assets
{
	mlx_image_t		*wall;
	mlx_texture_t	*texture_wall;
	mlx_image_t		*character;
	mlx_texture_t	*texture_character;
	mlx_image_t		*exit;
	mlx_texture_t	*texture_exit;
	mlx_image_t		*collectible;
	mlx_texture_t	*texture_collectible;
	mlx_image_t		*floor;
	mlx_texture_t	*texture_floor;
}					t_assets;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_t		*window;
	char		**map;
	int			rows;
	int			columns;
	int			collectibles;
	int			moves;
	bool		win;
	int			exit;
	int			state;
	int			path_exit;
	int			path_collectibles;
	t_assets	assets;
	t_assets	old_assets;
}				t_game;

typedef enum e_state
{
	STATE_NULL = 0,
	STATE_SUCCESS = 1,
	STATE_CLOSING = 2,
	STATE_GAMEOVER = 3,
}				t_state;

void		set_default_game(t_game *game);
void		load_assets(t_game *game);
mlx_image_t	*asset_to_image(t_game *game, char *img_path, int i);
void		free_images_and_textures(t_game *game, int i);
void		load_images_to_window(t_game *game);
void		image_to_window(t_game *game, int column, int row);
int			count_rows(char **map_2d);
void		check_2d_map_walls(t_game *game, char *str_map);
void		free_map(char **map);
void		print_end_result(t_game *game);
void		game_won(t_game *game);
void		ft_error_message(char *str, int error);
void		key_hook(mlx_key_data_t keydata, void *param);
char		*read_map_into_str(char *map);
char		**turn_str_into_2d_map(char *str);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			validate_move(t_game *game, char letter);
void		check_map(char *str_map, t_game *game);
void		check_map_letters(char *map);
void		check_map_letters_amount(char *str_map, t_game *game);
void		check_map_rectangle(char *map);
void		check_error_ber_file(char *argv);
void		init_assets(t_game *game);
void		set_texture(t_game *game, mlx_texture_t *texture, int i);
void		find_path_exit(char **map_2d, t_game *game);
void		find_path_collectibles(char **map_2d, t_game *game);
void		print_map(char **map);
#endif
