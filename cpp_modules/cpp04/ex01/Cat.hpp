/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:29:57 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 09:32:51 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);
		Cat		&operator=(const Cat &rhs);

		void		makeSound(void) const;
		void		setIdea(std::string idea, int index);
		std::string	getIdea(int i) const;

	private:
		Brain	*_brain;
};

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &src);
		~WrongCat(void);
		WrongCat	&operator=(const WrongCat &rhs);

		void		makeSound(void) const;
};

#endif
