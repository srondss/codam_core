/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:00:29 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/05 10:00:31 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Let's say we want to represent 8.63 in fixed point notation.
// Why would we want to store a number in fixed point notation?
// Because it's (usually) faster than floating point notation.
// Floating-point support is not always available in hardware.
// We can control the precision and range of the number which is especially useful if we have limited space.
// We can use fixed point notation to represent numbers in a range that is not supported by floating point notation.

// How do we represent a number in fixed point notation?
// Let's say we want to store the value 8.63 in a 8 bit integer with 4 bits for the fractional part.
// We have to first split up the number into integer and fractional parts.
// The 4 leftmost bits will be for the integer part and 4 rightmost bits will be for the fractional part.
// The leftmost bits use the normal binary representation (2^0, 2^1, 2^2, 2^3, 2^4, 2^5, 2^6, 2^7, etc..)
// The rightmost bits use the negative powers of 2 (2^-1, 2^-2, 2^-3, 2^-4, etc..)
// So the binary representation of 8.63 is 1000.1010.
// As 1000 = 0*2^0 + 0*2^1 + 0*2^2 + 0*2^3 + 1*2^4 = 8
// And 1010 = 1/2^-1 + 0/2^-2 + 1/2^-3 + 0/2^-4 = 1/2 + 1/8 = 0.5 + 0.125 = 0.625
// So 8.63 represented in fixed point notation is 8.625.
// As you can see we lost some precision because we only have 4 bits for the fractional part.
// The more bits we have for the fractional part the more precision we will get.

// How do we convert a number from floating point notation to fixed point notation?
// We multiply the number by 2 to the power of the number of bits we have for the fractional part.
// So if we have 4 bits for the fractional part we multiply the number by 2^4 = 16.
// 8.63 * 16 = 138.08
// We round the number to the nearest integer.
// 138.08 rounded to the nearest integer is 138.
// So 8.63 represented in fixed point notation is 138.

// How do we convert a number from fixed point notation to floating point notation?
// We divide the number by 2 to the power of the number of bits we have for the fractional part.
// So if we have 4 bits for the fractional part we divide the number by 2^4 = 16.
// 138 / 16 = 8.625
// So 138 represented in fixed point notation is 8.625.


int main( void ) {

	Fixed a;
	// Fixed const b( 10 );
	// Fixed const c( 42.42f );
	// Fixed const d( b );
	a = Fixed( 8.63f );
	std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
