/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_to_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:39:12 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/06 21:33:45 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map_into_str(char *map)
{
	int	fd;
	int	count;
	char	*str_map;
	char	c;

	count = 0;
	check_error_ber_file(map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error_message(E_FILE, 1);
	while (read(fd, &c, 1) == 1) // reads the entire file byte by byte.
	{
		ft_printf("Char: %c\n", c);
		count++;
	}
	if (count == 0)
		ft_error_message(E_FILE, 1);
	str_map = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_map)
		ft_error_message(E_MALLOC, 1);
	close(fd);
	fd = open(map, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	return (str_map);
}

char	**turn_str_into_2d_map(char *str)
{
	return (ft_split(str, '\n'));
}


