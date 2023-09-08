/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:22:23 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 09:48:00 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class A_Animal {
	public:
		A_Animal(void);
		A_Animal(std::string type);
		A_Animal(const A_Animal &src);
		virtual ~A_Animal(void);

		A_Animal	&operator=(const A_Animal &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const=0;

	protected:
		std::string	_type;
};

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
