/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:27:15 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/07 08:27:15 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		// Member attributes
		std::string				_name;
		unsigned int			_hit_points;
		unsigned int			_energy_points;
		unsigned int			_attack_damage;

	public:
		// Cannonical Orthodox Form
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &rhs);
		~ClapTrap(void);

		// Class attributes
		std::string			className;
		unsigned int			classAttackDamage;
		unsigned int			classEnergyPoints;
		unsigned int			classHitPoints;

		// Member functions
		void					attack(const std::string& target);
		void					takeDamage(unsigned int amount);
		void					beRepaired(unsigned int amount);

		// Setters
		void					setName(std::string name);
		void					setHitPoints(unsigned int amount);
		void					setEnergyPoints(unsigned int amount);
		void					setAttackDamage(unsigned int amount);

		// Getters
		std::string				getName(void) const;
		unsigned int			getHitPoints(void) const;
		unsigned int			getEnergyPoints(void) const;
		unsigned int			getAttackDamage(void) const;
		unsigned int			getClassAttackDamage(void) const;
		unsigned int			getClassEnergyPoints(void) const;
		unsigned int			getClassHitPoints(void) const;
		const std::string		getClassName(void) const;
};

#endif
