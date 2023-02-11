/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:39:27 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/11 21:49:54 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_default_game(t_game *game)
{
	game->moves = 0;
	game->state = STATE_NULL;
	game->exit = FALSE;
}

void	checkleaks() 
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str_map;

//	if (argc < 2)
//		return (1);
	
	// Turn map file into one huge string.
	str_map = read_map_into_str(argv[1]);
	ft_printf("%s", str_map);

	// Initialise new game.
	set_default_game(&game);

	// Make sure the map is valid.
	check_map(str_map, &game);

	// Turn one huge string into 2d map (rows and columns). 
	game.map = turn_str_into_2d_map(str_map);
	
	if (game.map == NULL)
		return (free(str_map), 1);
	// Free the string because we won't need it anymore.
	free(str_map);

	// Make sure the walls are all 1s.
	check_2d_map_walls(&game);

	// TODO: Need to create function which checks if path exists.
 
	// Initialise game window with 32 pixels + however many columns + rows. 
	game.mlx = mlx_init(game.columns * 32, game.rows * 32, "GAME", FALSE);
	if (!game.mlx)
		return (free(game.map), 1);

	// Need to create function which will load assets into the game.
	load_assets(&game);
	
	// Load images to window.
	load_images_to_window(&game);

	// Checks if a key was pressed and applies movement + rerenders images. 
	mlx_key_hook(game.mlx, &key_hook, &game);

	// loop game.
	mlx_loop(game.mlx);

	// free the map once done.
	free_map(game.map);
	
	if (game.state != STATE_SUCCESS)
		free_images_and_textures(&game);

	// terminate game which frees everything. 
	mlx_terminate(game.mlx);

	atexit(checkleaks);
	return (EXIT_SUCCESS);
}

