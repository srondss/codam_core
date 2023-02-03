/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:39:27 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/03 13:41:57 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t *character_img;

void hook(void *param)
{
	mlx_t *mlx;
	
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		character_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		character_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		character_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		character_img->instances[0].x += 5;
}

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t main(int argc, char **argv)
{
	if (argc != 2 || check_error_ber_file(argv[1]) == 0)
		return (write(2, "Input Error\n", 12));
	if (check_map_letters(argv[1]) == 0 || check_map_rectangle(argv[1]) == 0 || check_exit_or_start(argv[1]) == 0 || check_collectibles(argv[1]) == 0 || check_walls(argv[1]) == 0) 
		return (write(2, "Map Error\n", 10));

	mlx_t *mlx;
	mlx_texture_t	*texture;

	//	Here you're essentially initialising a window with a certain width and height.
	mlx = mlx_init(16 * /* width */, 16 * /* height */ , "MLX42", true);
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
	

	// Run the main loop and terminate on quit.
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	system("leaks -q so_long");
	return (EXIT_SUCCESS);
}

/*
TODO:
1.	Figure out how big the rectangle is [WIDTH + HEIGHT] (fairly easy, just copy from parsing functions).
2.	Once I know how big the rectangle is, let's say that every image will be 16x16...
	That means that width must be 16px * number of 1s per row. 
	and HEIGHT must be 16* number of rows.
3	If 1 = generate wall, if 0 = generate boilerplate, if P = generate character,
	if C = generate collectible, if E = generate exit.	
*/




