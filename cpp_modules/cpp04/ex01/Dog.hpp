/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:30:33 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 09:20:16 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &src);
		~Dog(void);
		Dog	&operator=(const Dog &rhs);

		void		makeSound(void) const;
		void		setIdea(std::string idea, int index);
		std::string	getIdea(int i) const;

	private:
		Brain	*_brain;
};

#endif
