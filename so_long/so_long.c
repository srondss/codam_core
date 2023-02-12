/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:39:27 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/12 18:51:24 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_default_game(t_game *game)
{
	game->moves = 0;
	game->state = STATE_NULL;
	game->exit = FALSE;
	game->path = FALSE;
}

void	init_assets(t_game *game)
{
	game->assets.texture_wall = NULL;
	game->assets.texture_character = NULL;
	game->assets.texture_exit = NULL;
	game->assets.texture_collectible = NULL;
	game->assets.texture_floor = NULL;
	game->assets.character = NULL;
	game->assets.floor = NULL;
	game->assets.collectible = NULL;
	game->assets.exit = NULL;
	game->assets.wall = NULL;
}

void	checkleaks(void)
{
	system("leaks -q so_long");
}

void	start_mlx_program(t_game *game)
{
	game->mlx = mlx_init(game->columns * 32, game->rows * 32, "GAME", FALSE);
	if (!(game->mlx))
		return (free_map(game->map));
	load_assets(game);
	load_images_to_window(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	free_map(game->map);
	if (game->state != STATE_SUCCESS)
		free_images_and_textures(game, 1);
	mlx_terminate(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str_map;

	if (argc != 2)
		return (ft_error_message(E_ARG, 1), 1);
	str_map = read_map_into_str(argv[1]);
	set_default_game(&game);
	check_map(str_map, &game);
	game.map = turn_str_into_2d_map(str_map);
	if (game.map == NULL)
		return (free(str_map), ft_error_message(E_MALLOC, 1), 1);
	check_2d_map_walls(&game, str_map);
	find_path(game.map, &game);
	if (game.path == FALSE)
		return (free_map(game.map), free(str_map),
			ft_error_message(E_PATH, 1), 1);
	free_map(game.map);
	game.map = turn_str_into_2d_map(str_map);
	if (game.map == NULL)
		return (free(str_map), ft_error_message(E_MALLOC, 1), 1);
	free(str_map);
	start_mlx_program(&game);
	atexit(checkleaks);
	return (EXIT_SUCCESS);
}
