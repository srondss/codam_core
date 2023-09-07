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
We use the toFloat member function to convert the fixed-point value to a floating-point
value. Why? Because we want to print the floating-point value, not the fixed-point value.
*/
std::ostream& operator<< (std::ostream &out, Fixed const& fixed) {
	out << fixed.toFloat();
	return (out);
}

/*
An overload of the comparison operator (==) that compares the fixed-point value of
the Fixed number with the floating-point value passed as parameter. If the values are
equal, the function returns true. Otherwise, it returns false.
Why didn't we just use the _value member variable for rhs? Because it's private.
*/
bool	Fixed::operator==(const Fixed &rhs) const {
	return (this->_value == rhs.getRawBits());
}

/*
An overload of the comparison operator (!=) that compares the fixed-point value of
the Fixed number with the floating-point value passed as parameter.
*/
bool	Fixed::operator!=(const Fixed &rhs) const {
	return (this->_value != rhs.getRawBits());
}

/*
An overload of the comparison operator (>) that compares the fixed-point value of
the Fixed number with the floating-point value passed as parameter.
*/
bool	Fixed::operator>(const Fixed &rhs) const {
	return (this->_value > rhs.getRawBits());
}

/*
An overload of the comparison operator (<) that compares the fixed-point value of
the Fixed number with the floating-point value passed as parameter.
*/
bool	Fixed::operator<(const Fixed &rhs) const {
	return (this->_value < rhs.getRawBits());
}

/*
An overload of the comparison operator (>=) that compares the fixed-point value of
the Fixed number with the floating-point value passed as parameter.
*/
bool	Fixed::operator>=(const Fixed &rhs) const {
	return (this->_value >= rhs.getRawBits());
}

/*
An overload of the comparison operator (<=) that compares the fixed-point value of
the Fixed number with the floating-point value passed as parameter.
*/
bool	Fixed::operator<=(const Fixed &rhs) const {
	return (this->_value <= rhs.getRawBits());
}

/*
An overload of the arithmetic operator (+) that adds the fixed-point value of the
Fixed number with the fixed-point value of the Fixed number passed as parameter.
Why do we convert the fixed-point values to floating-point values? Because we want
to add the floating-point values, not the fixed-point values.

*/
Fixed	Fixed::operator+(const Fixed &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

/*
An overload of the arithmetic operator (-) that subtracts the fixed-point value of the
Fixed number with the fixed-point value of the Fixed number passed as parameter.
*/
Fixed	Fixed::operator-(const Fixed &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

/*
An overload of the arithmetic operator (*) that multiplies the fixed-point value of the
Fixed number with the fixed-point value of the Fixed number passed as parameter.
*/
Fixed	Fixed::operator*(const Fixed &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

/*
An overload of the arithmetic operator (/) that divides the fixed-point value of the
Fixed number with the fixed-point value of the Fixed number passed as parameter.
*/
Fixed	Fixed::operator/(const Fixed &rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/*
An overload of the pre-increment (++) operator that increments the fixed-point value
of the Fixed number by 1.
*/
Fixed	&Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

/*
An overload of the post-increment (++) operator that increments the fixed-point value
of the Fixed number by 1.
*/
Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

/*
An overload of the pre-decrement (--) operator that decrements the fixed-point value
of the Fixed number by 1.
*/
Fixed	&Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

/*
An overload of the post-decrement (--) operator that decrements the fixed-point value
of the Fixed number by 1.
*/
Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

/*
A static member function min that takes two Fixed numbers as parameters and
returns a reference to the smallest of the two.
*/
Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

/*
A static member function max that takes two Fixed numbers as parameters and
returns a reference to the biggest of the two.
*/
Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

/*
A static member function min that takes two constant Fixed numbers as parameters and
returns a reference to the smallest of the two.
*/
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

/*
A static member function max that takes two constant Fixed numbers as parameters and
returns a reference to the biggest of the two.
*/
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}
