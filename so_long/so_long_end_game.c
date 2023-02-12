/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_end_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:34:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/12 15:18:33 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_end_result(t_game *game)
{
	if (game->state == STATE_SUCCESS)
		ft_printf("\nCongratulations!\n You won!\n");
	else if (game->state == STATE_CLOSING)
		ft_printf("\n You're not done yet.. sad to see you go.\n");
	return ;
}

void	game_won(t_game *game)
{
	free_images_and_textures(game, 1);
	game->state = STATE_SUCCESS;
	print_end_result(game);
	mlx_close_window(game->mlx);
}
