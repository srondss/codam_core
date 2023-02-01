/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ysrondy <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 17:08:15 by ysrondy       #+#    #+#                 */
/*   Updated: 2022/12/12 18:57:41 by ysrondy       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
int		ft_strlen(char const *str);
void	fill_string(char *buf, char *str, int i, int len);
#endif
