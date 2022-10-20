/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_misc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:10:36 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 16:10:37 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_prc(va_list *list)
{
	(void) *list;
	write(1, "%", 1);
	return (1);
}