/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:39:27 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/06 22:10:37 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_default_game(t_game *game)
{
	game->moves = 0;
	game->state = STATE_NULL;
	game->exit = FALSE;
}

int main(int argc, char **argv)
{
	t_game game;
	char	*str_map;

	if (argc < 2)
		return (1);
	
	// Turn map file into one huge string.
	str_map = read_map_into_str(argv[1]);

	// Initialise new game.
	set_default_game(&game);

	// Make sure the map is valid.
	check_map(str_map, &game);

	// Turn one huge string into 2d map (rows and columns). 
	game.map = turn_str_into_2d_map(str_map);
	
	// Free the string because we won't need it anymore.
	free(str_map);

	// Make sure the walls are all 1s.
	check_2d_map_walls(&game);

	// TODO: Need to create function which checks if path exists.
 
	// Initialise game window with 32 pixels + however many columns + rows. 
	game.mlx = mlx_init(game.columns * 64, game.rows * 64, "GAME", FALSE);
	if (!game.mlx)
		exit(EXIT_FAILURE);

	// Need to create function which will load assets into the game.
	load_assets(&game);

	// Need to create the loop & key hooks for interactivity. 
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_key_hook(game.mlx, &key_hook, &game);	

	// loop game.
	mlx_loop(game.mlx);

	// free the map once done.
	free_map(game.map);

	// terminate game which frees everything. 
	mlx_terminate(game.mlx);
//	system("leaks -q so_long");
	return (EXIT_SUCCESS);
}









/*
int	test(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_error_ber_file(argv[1]) == 0)
		return (write(2, "Input Error\n", 12));
	if (check_map_letters(argv[1]) == 0 || check_map_rectangle(argv[1]) == 0 || check_exit_or_start(argv[1]) == 0 || check_collectibles(argv[1]) == 0 || check_walls(argv[1]) == 0) 
		return (write(2, "Map Error\n", 10));

	mlx_t *mlx;
	mlx_texture_t	*texture;
	mlx_image_t	*wall_image;
	
	//	Here you're essentially initialising a window with a certain width and height.
	mlx = mlx_init(16 *  width , 16 *  height  , "MLX42", true);
	if (!mlx)
		ft_error();

	//	Here you're loading a specific texture that will be set on a particular image.
	texture = mlx_load_png("./textures/Actor/Characters/Knight/SeparateAnim/Special1.png");
	if (!texture)
		ft_error();

	//	Here you're creating a new image, which needs a pointer to the window, and how big it will be.
	character_img = mlx_texture_to_image(mlx, texture);
	if (!character_img)
		ft_error();

	// Draw the image at coordinate (x, y).
	mlx_image_to_window(mlx, character_img, 1, 1);
	

	// Here I need to create a while loop which checks if the counter is
	// equal to the number of 1s. If not, it will load a texture on the
	// screen, at the edges, and...

	// Run the main loop and terminate on quit.
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	system("leaks -q so_long");
	return (EXIT_SUCCESS);
}
*/


//gcc -Wall -Wextra -Werror -g so_long.c so_long_map_to_string.c so_long_parse_map.c so_long_assets.c so_long_check_2d_map.c so_long_end_game.c so_long_error.c so_long_hooks.c so_long_movement.c printf/ft_printf.c printf/ft_printf_hex.c printf/ft_printf_ints.c printf/ft_printf_misc.c printf/ft_printf_ptr.c printf/ft_printf_str.c c_libft/ft_split.c c_libft/ft_strlen.c c_libft/ft_substr.c c_libft/ft_itoa.c c_libft/ft_strdup.c MLX42/libmlx42.a -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/ -fsanitize=address
