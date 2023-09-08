/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:27:11 by youssefsron       #+#    #+#             */
/*   Updated: 2023/09/08 09:42:15 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(rhs.getIdea(i), i);
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}

void	Cat::setIdea(std::string idea, int index) {
	if (index > 99)
		std::cout << "Cats only have space for 100 ideas" << std::endl;
	else
		this->_brain->setIdea(idea, index);
}

std::string	Cat::getIdea(int i) const {
	if (i > 99)
		return ("Cats only have space for 100 ideas");
	else
		return (this->_brain->getIdea(i));
}

/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat sound" << std::endl;
}

