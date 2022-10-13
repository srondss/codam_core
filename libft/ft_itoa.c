/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:59:48 by ysrondy           #+#    #+#             */
/*   Updated: 2022/10/12 16:12:03 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static char *ret_positive(char *str, int len, int num, int i);
// TODO: Create ret_negative.
char    *ft_itoa(int n)
{
    char    *str;
    int        len;
    int        num;
    int        i;

    i = 0;
    len = 0;
    num = n;
    if (n >= 0)
    {
        while (n > 0)
        {
            n /= 10;
            len++;
        }
        if (num == 0)
            len++;
        str = (char *)malloc(sizeof(char) * (len + 1));
        str[len] = '\0';
        str = ret_positive(str, len, num, i);
    }
    return (str);
}

static char *ret_positive(char *str, int len, int num, int i)
{
    while (i <= len)
    {
        printf("num: %d, i: %d len: %d\n", num, i, len);
        len--;
        if (num < 9)
        {
            str[len] = num + '0';
            break ;
        }
        str[len] = ((num % 10) + '0');
        num /= 10;
    }
    return (str);
}

int main(void)
{
    int n;
    
    n = 143124;
    printf("Itoa: %s", ft_itoa(n));
}
