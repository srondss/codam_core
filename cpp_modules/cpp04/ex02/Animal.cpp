/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:30:53 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 09:46:24 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

A_Animal::A_Animal(void) : _type("A_Animal") {
	std::cout << "A_Animal constructor called" << std::endl;
}

A_Animal::A_Animal(std::string type) : _type(type) {
	std::cout << "A_Animal constructor with type " << type << " called" << std::endl;
}

A_Animal::A_Animal(const A_Animal &src) {
	std::cout << "A_Animal copy constructor called" << std::endl;
	*this = src;
}

A_Animal::~A_Animal(void) {
	std::cout << "A_Animal destructor called" << std::endl;
}

A_Animal	&A_Animal::operator=(const A_Animal &rhs) {
	std::cout << "A_Animal assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string		A_Animal::getType(void) const {
	return (this->_type);
}

void	A_Animal::makeSound(void) const {
}

/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor with type " << type << " called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string		WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal sound" << std::endl;
}

