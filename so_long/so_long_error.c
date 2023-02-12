/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:12:01 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/12 18:50:43 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
		ft_printf("Error: ./so_long");
	else
	{
		write(2, "Error\n", 6);
		ft_printf("%s", str);
	}
	(void)error;
	exit(error);
}

// Frees all previously allocated assets.
void	free_images_and_textures(t_game *game, int i)
{
	if (i == 0)
	{
		free_map(game->map);
		mlx_terminate(game->mlx);
	}
	if (game->assets.texture_wall != NULL)
		mlx_delete_texture(game->assets.texture_wall);
	if (game->assets.texture_character != NULL)
		mlx_delete_texture(game->assets.texture_character);
	if (game->assets.texture_exit != NULL)
		mlx_delete_texture(game->assets.texture_exit);
	if (game->assets.texture_collectible != NULL)
		mlx_delete_texture(game->assets.texture_collectible);
	if (game->assets.texture_floor != NULL)
		mlx_delete_texture(game->assets.texture_floor);
	if (game->assets.character != NULL)
		mlx_delete_image(game->mlx, game->assets.character);
	if (game->assets.floor != NULL)
		mlx_delete_image(game->mlx, game->assets.floor);
	if (game->assets.exit != NULL)
		mlx_delete_image(game->mlx, game->assets.exit);
	if (game->assets.collectible != NULL)
		mlx_delete_image(game->mlx, game->assets.collectible);
	if (game->assets.wall != NULL)
		mlx_delete_image(game->mlx, game->assets.wall);
}
