/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:32:29 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/10 16:58:18 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	find_c(char const *s, char c, int i);
char	**fill_arr(char const *s, char **arr, char c);

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	len;
	char	**arr;

	i = 0;
	j = find_c(s, c, i);
	len = 0;
	arr = (char **)malloc((j + 1) * sizeof(char *));
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
		{
			arr[j] = malloc((len + 1) * sizeof(char));
			j++;
			len = 0;
		}
		len++;
		i++;
	}
	arr = fill_arr(s, arr, c);
	return (arr);
}

char	**fill_arr(char const *s, char **arr, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == c)
		{
			arr[i][j] = '\0';
			i++;
			j = -1;
		}
		else
		{
			arr[i][j] = s[len];
		}
		j++;
		len++;
	}
	arr[i][j] = '\0';
	return (arr);
}

int	find_c(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

/*int main(void)
{
	char str[] = "hello,goodbye,doei";
	for (int i = 0; i < 3; i++)
		printf("String: %s\n", ft_split(str, ',')[i]);
}*/
