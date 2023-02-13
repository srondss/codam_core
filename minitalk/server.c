/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:16 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/13 23:12:16 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler_sigusr(int signum)
{
   static int	c = 255;
   static int	bits = 0;

   if (signum == SIGUSR2)
   {
   	printf("0");
   	c ^= (128 >> bits);
   }
   else if (signum == SIGUSR1)
   {
   	printf("1");
   	c |= (128 >> bits);
   }
   bits++;
   if (bits == 8)
   {
   	printf("-> %c\n", c);
   	bits = 0;
   	c = 255;
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
