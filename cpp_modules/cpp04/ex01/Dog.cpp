/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:34:54 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 09:44:22 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(rhs.getIdea(i), i);
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}

void	Dog::setIdea(std::string idea, int index) {
	if (index > 99)
		std::cout << "Unable to set idea. Dogs only have space for 100 ideas." << std::endl;
	else
		this->_brain->setIdea(idea, index);
}

std::string	Dog::getIdea(int i) const {
	if (i > 99)
		return ("Unable to retrieve idea. Dogs only have space for 100 ideas");
	else
		return (this->_brain->getIdea(i));
}

