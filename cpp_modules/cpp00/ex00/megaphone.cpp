/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:57:46 by ysrondy           #+#    #+#             */
/*   Updated: 2023/08/06 10:57:52 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 1;
	int j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}

	while (argv[i])
	{
		while (argv[i][j])
		{
			std::cout << char(std::toupper(argv[i][j]));
			j++;
		}
		i++;
		j = 0;
	}
	std::cout << std::endl;
	return (0);
}
