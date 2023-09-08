/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:00:27 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/08 08:00:28 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->setName("Unnamed");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	// Class attributes
	this->classHitPoints = 100;
	this->classEnergyPoints = 100;
	this->classAttackDamage = 30;
	this->className = "FragTrap";
	std::cout << "FragTrap with no name given constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	// Class attributes
	this->classHitPoints = 100;
	this->classEnergyPoints = 100;
	this->classAttackDamage = 30;
	this->className = "FragTrap";
	std::cout << "FragTrap "<< name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName() << " is asking for a high five!" << std::endl;
}
