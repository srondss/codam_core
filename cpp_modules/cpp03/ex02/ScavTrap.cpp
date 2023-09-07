/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:07:12 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/07 09:07:13 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	this->setName("Unnamed");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);

	// Class attributes
	this->classHitPoints = 100;
	this->classEnergyPoints = 50;
	this->classAttackDamage = 20;
	this->className = "ScavTrap";
	std::cout << "ScavTrap with no name given constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);

	// Class attributes
	this->classHitPoints = 100;
	this->classEnergyPoints = 50;
	this->classAttackDamage = 20;
	this->className = "ScavTrap";
	std::cout << "ScavTrap "<< name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << std::endl;
}
