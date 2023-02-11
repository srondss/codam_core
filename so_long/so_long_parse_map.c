/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:25:49 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/11 17:58:41 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_map(char *str_map, t_game *game)
{
	check_map_letters(str_map);
	check_map_letters_amount(str_map, game);
	check_map_rectangle(str_map);
}

// Checks if map contains other letters besides 0,1,c,e,p.
void	check_map_letters(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C' || map[i] == 'E' || map[i] == 'P' || map[i] == '\n')
			i++;
		else
		{
			free(map);
			ft_error_message(E_CHARACTER, 1);
		}
	}
}

// Checks if there are a valid number of arguments in map.
void	check_map_letters_amount(char *str_map, t_game *game)
{
	int	i;
	int	collectibles;
	int	exit;
	int	player;
	
	i = 0;
	collectibles = 0;
	exit = 0;
	player = 0;

	while (str_map[i++])
	{
		if (str_map[i] == 'C')
			collectibles++;
		if (str_map[i] == 'P')
			player++;
		if (str_map[i] == 'E')
			exit++;
	}
	if (collectibles < 1 || exit != 1 || player != 1)
	{
		free(str_map);
		ft_error_message(E_CHARS, 1);
	}
	game->collectibles = collectibles;
}


// Checks if map is rectangular. 
void	check_map_rectangle(char *map)
{
	int i;
	int size_first_line;
	int size_other_line;

	i = 0;
	size_first_line = 0;
	size_other_line = 0;
	while (map[i] != '\n')
	{
		size_first_line++;
		i++;
	}
	i++;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (size_first_line != size_other_line)
			{
				free(map);
				ft_error_message(E_INVALIDMAP, 1);
			}
			size_other_line = 0;
		}
		else
			size_other_line++;
		i++;
	}
}

// Checks if .ber file as argument.
void	check_error_ber_file(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != '.')
			i++;
		else
		{
			if (argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i + 3] == 'r' && argv[i + 4] == '\0')
				return ;
			ft_error_message(E_FORMAT, 1);
		}
	}
	ft_error_message(E_FORMAT, 1);
}

