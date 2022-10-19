/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <ysrondy@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 15:56:26 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/10/19 20:10:11 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef int	(*JUMP_TABLE)(va_list arg); 

int		put_hex(va_list hex);
int		put_uint(va_list list);
int		put_int(va_list list);
int		put_prc(va_list list);
int		ft_putstr(char *str);
int		put_char(va_list list);
int		put_str(va_list list);
int		put_ptr(va_list list);
int 	ft_putrstr(char *str);
int		put_chex(va_list list);
char	*get_hex_ptr(unsigned long hex);
#endif
