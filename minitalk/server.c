/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/15 22:36:01 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	convert_binary_to_ascii(char *string)
{
	int	i;
	int	sum;
	int	square_two;

	i = 0;
	sum = 0;
	square_two = 128;
	while (i < 8)
	{
		if (string[i] == '1')
			sum += square_two;
		square_two /= 2;
		i++; 
	}
//	if (sum == 0)
//		write(1, "\n", 1);
//	else
		write(1, &sum, 1);
}

void	handler_sigusr(int signum)
{
   static char binary_char[8];
   static int	bits = 0;

   if (signum == SIGUSR2)
   	binary_char[bits] = '0';
   else if (signum == SIGUSR1)
	binary_char[bits] = '1';
   bits++;
   if (bits == 8)
   {
	convert_binary_to_ascii(binary_char);
   	bits = 0;
   }
}

int main(void)
{
	printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
	{
		pause();
	}
}
