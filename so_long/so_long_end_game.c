/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_end_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:34:44 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/06 16:42:03 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_end_result(t_game *game)
{
	if (game->state == STATE_SUCCESS)
		ft_printf("\nCongratulations!\n You won!\n");
	else if (game->state == STATE_CLOSING)
		ft_printf("\n You're not done yet.. sad to see you go.\n");
	else if (game->state == STATE_GAMEOVER)
		ft_printf("\n GAME OVER... \n");
}

void	game_won(t_game *game)
{
	free_old_images(game);
	game->old_assets = game->assets;
	free_old_images(game); // WHY CALL TWICE?
	game->state = STATE_SUCCESS;
	print_end_result(game);
	mlx_close_window(game->mlx);
}
