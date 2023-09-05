/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:20:35 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/05 08:20:36 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// Cannonical Orthodox Form
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &rhs);
		~Fixed(void);

		Fixed(const int value);
		Fixed(const float value);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream& operator<< (std::ostream &out, Fixed const& fixed);



#endif
