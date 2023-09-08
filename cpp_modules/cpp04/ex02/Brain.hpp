/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:08:39 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 09:33:33 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);
		Brain	&operator=(const Brain &rhs);

		void		setIdea(std::string idea, int index);
		std::string	getIdea(int i) const;

	private:
		std::string	ideas[100];
};

#endif
