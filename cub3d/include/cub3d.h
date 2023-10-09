/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:16:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/08 23:09:11 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Lib/MLX42/include/MLX42/MLX42.h"
# include "../Lib/libft/libft.h"
# include "./get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_player
{
	mlx_image_t	*player_images;
	mlx_image_t	*player_line;
	float		fov;
	float		direction;
	int			size;
	float		pos_x;
	float		pos_y;
	double		angle;
}				t_player;

typedef struct s_RGB
{
	int			color_R;
	int			color_G;
	int			color_B;
}				t_RGB;

typedef struct s_map
{
	int		height;
	int		largest_row;
	int		**map_2d;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color_string;
	t_RGB	floor_colors;
	char	*ceiling_color_string;
	t_RGB	ceiling_colors;
	char	direction;
	int		player_count;
	int		player_row;
	int		player_column;
	int		num_lines_file;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}				t_game;


// MAP PARSING (TEXTURES)
bool	check_no_texture(t_game *game, char *line, int i, bool found_map);
bool	check_so_texture(t_game *game, char *line, int i, bool found_map);
bool	check_we_texture(t_game *game, char *line, int i, bool found_map);
bool	check_ea_texture(t_game *game, char *line, int i, bool found_map);

// MAP PARSING (FLOOR & CEILING)
bool	check_floor_color(t_game *game, char *line, bool found_map);
bool	check_ceiling_color(t_game *game, char *line, bool found_map);

// MAP PARSING UTILS
bool	is_whitespace(char c);
int		get_pos_last_digit(char *line);
int		get_pos_first_digit(char *line, char c);
int		get_num_lines_file(char *map);

// PATHFINDING
int		position_player_column(int **map_2d, t_game *game);
int		position_player_row(int **map_2d, t_game *game);
void	print_map_2d(t_game *game);
int		get_row_width(t_game *game, int **map_2d, int row);
bool	find_path_exit(t_game *game, int **map_2d);

// CHECK MAP
bool	check_map_line(t_game *game, char *line);
bool	check_elements_exist(t_game *game);
bool	error_if_not_empty(char *line);
void	parse_cub_file(t_game *game, char *map);
bool	check_valid_map(t_game *game, char *map);


#endif
