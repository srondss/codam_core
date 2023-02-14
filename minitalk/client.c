/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:47:37 by ysrondy           #+#    #+#             */
/*   Updated: 2023/02/14 21:45:36 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

// ASCII values go up to 127.
// Because a char is equal to 1 byte or 8 bits,
// although the max value for ascii is 2^7, we store 8 bits of data.

/* We want to print the binary represenation of every character in the string. 
We know 128 can be represented as 1000000. 
So what we want to do is use the & operator to print out the binary
equivalent of every character.
*/


void	send_binary_signals(int pid, char *string)
{
	int i; 
	int bit;

	i = 0;
	while (string[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (string[i] & (128 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(100);
		}
		i++;
	}
}


int main(int argc, char **argv)
{
	if (argc != 3)
		return (printf("Usage: ./client <server_pid> <string>\n"));

	send_binary_signals(atoi(argv[1]), argv[2]);
}
