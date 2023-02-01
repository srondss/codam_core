/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:26:42 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/01 11:51:09 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef WIDTH
# define WIDTH 500
# endif 

# ifndef HEIGHT
# define HEIGHT 500
# endif

#include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdbool.h>
#include <fcntl.h>

int	check_map_letters(char *map);
int	check_map_rectangle(char *map);
int	check_error_ber_file(char *argv);

#endif
