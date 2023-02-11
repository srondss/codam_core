/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:12:01 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/11 18:16:11 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
		ft_printf("Error: ./so_long");
	else
	{
		write(2, "Error\n", 7);
		ft_printf("%s", str);
	}
	(void)error;
	exit(error);
}

