/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:39:27 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/01 11:51:42 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void hook(void *param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	/*	if (mlx_is_key_down(mlx, MLX_KEY_UP))
			g_img->instances[0].y -= 5;
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			g_img->instances[0].y += 5;
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			g_img->instances[0].x -= 5;
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			g_img->instances[0].x += 5;*/
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
	if (check_map_letters(argv[1]) == 0 || check_map_rectangle(argv[1]) == 0)
		return (write(2, "Map Error\n", 10));

	mlx_image_t *g_img;
	mlx_t *mlx;

	//	Here you're essentially initialising a window with a certain width and height.
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		ft_error();

	//	Here you're creating a new image, which needs a pointer to the window, and how big it will be.
	g_img = mlx_new_image(mlx, 100, 100);
	if (!g_img)
		ft_error();

	// Here you're setting the pixels of the image you've created to the color 255 (white),
	// and you specify how many pixels are going to have that color. Why times 4?
	// Since each pixel is represented as an integer, it will be four bytes for four channels.
	// If you only do width * height, then you end up with only 1 / 4 of the image pixelized.
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));

	// Draw the image at coordinate (x, y).
	mlx_image_to_window(mlx, g_img, 200, 200);
	

	// Run the main loop and terminate on quit.
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
