/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:16:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/12 14:22:38 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Lib/MLX42/include/MLX42/MLX42.h"
# include "../Lib/libft/libft.h"
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

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	*player;
	int			*map;
}				t_game;


#endif
