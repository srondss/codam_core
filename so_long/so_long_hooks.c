/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:40:09 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/11 17:32:09 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (map[i] != NULL)
	{
		while (j < ft_strlen(map[i]))
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
		j = 0;
	}
}

void hook(void *param)
{
	t_game *game;

	game = param;
	load_images_to_window(game);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = param;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
			game->state = STATE_CLOSING;
			print_end_result(game);
		}
		if (game->exit == FALSE)
		{
			if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
				move_up(game);
			if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
				move_left(game);
			if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
				move_right(game);
			if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
				move_down(game);
		}
		free_images_and_textures(game);
		load_assets(game);
		load_images_to_window(game);
	}
}
