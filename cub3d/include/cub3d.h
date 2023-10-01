/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:16:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/10/01 19:00:21 by ysrondy          ###   ########.fr       */
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
	float		delta_x;
	float		delta_y;
	float		angle;
	int			mx;
	int			my;
	int			mp;
	int			dof;
	float		rx; // ray x coordinate
	float		ry; // ray y coordinate
	float		ra; // ray angle
	float		xo;
	float		yo;
}				t_player;

typedef struct s_RGB
{
	int			color_R;
	int			color_G;
	int			color_B;
}				t_RGB;

typedef struct s_map
{
	int		width;
	int		height;
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
int		get_pos_first_digit(char *line);
int		get_num_lines_file(char *map);

#endif
