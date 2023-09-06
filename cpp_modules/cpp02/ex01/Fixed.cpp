/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:20:29 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/05 08:20:30 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

/*
A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
*/
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

/*
A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
*/
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = ((int)roundf(value * (1 << this->_bits)));
}

// converts the fixed-point value to a float value.
float	Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << this->_bits));
}

// converts the fixed-point value to an integer value.
int		Fixed::toInt(void) const {
	return (this->_value >> this->_bits);
}

/*
An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.
*/
std::ostream& operator<< (std::ostream &out, Fixed const& fixed) {
	out << fixed.toFloat();
	return (out);
}

