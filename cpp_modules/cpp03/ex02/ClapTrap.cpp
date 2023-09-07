/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:31:49 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/07 08:31:49 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_name = "Unnamed";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;

	// Class attributes
	this->classHitPoints = 10;
	this->classEnergyPoints = 10;
	this->classAttackDamage = 0;
	this->className = "ClapTrap";
	std::cout << "ClapTrap with no name given constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;

	// Class attributes
	this->classHitPoints = 10;
	this->classEnergyPoints = 10;
	this->classAttackDamage = 0;
	this->className = "ClapTrap";
	std::cout << "ClapTrap "<< name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energy_points == 0)
	{
		std::cout << this->className << " " << this->_name << " has no energy points left!" << std::endl;
		return ;
	}
	else if (this->_hit_points == 0)
	{
		std::cout << this->className << " " << this->_name << " has no hit points left!" << std::endl;
		return ;
	}
	std::cout << this->className << " " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
	std::cout << this->className << " " << this->_name << " now has " << this->_energy_points << " energy points left!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points == 0)
	{
		std::cout << this->className << " " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	else if (amount >= this->_hit_points)
	{
		this->_hit_points = 0;
		std::cout << this->className << " " << this->_name << " takes " << amount << " points of damage and dies!" << std::endl;
		return ;
	}
	std::cout << this->className << " " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hit_points -= amount;
	std::cout << this->className << " " << this->_name << " has " << this->_hit_points << " hit points left!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points == 0)
	{
		std::cout << this->className << " " << this->_name << " is dead and cannot be repaired!" << std::endl;
		return ;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << this->className << " " << this->_name << " has no energy points left and cannot be repaired!" << std::endl;
		return ;
	}
	else if (this->_hit_points + amount > this->classHitPoints)
	{
		this->_hit_points = this->classHitPoints;
		std::cout << this->className << " " << this->_name << " is repaired for " << amount << " and is back to full health (" << this->classHitPoints << " hit points)!" << std::endl;
		return ;
	}
	std::cout << this->className << " " << this->_name << " is repaired for " << amount << " points of damage!" << std::endl;
	this->_hit_points += amount;
	std::cout << this->className << " " << this->_name << " now has " << this->_hit_points << " hit points left!" << std::endl;
	this->_energy_points--;
	std::cout << this->className << " " << this->_name << " now has " << this->_energy_points << " energy points left!" << std::endl;
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int amount) {
	this->_hit_points = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount) {
	this->_energy_points = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attack_damage = amount;
}

std::string		ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attack_damage);
}

unsigned int	ClapTrap::getClassAttackDamage(void) const {
	return (this->classAttackDamage);
}

unsigned int	ClapTrap::getClassEnergyPoints(void) const {
	return (this->classEnergyPoints);
}

unsigned int	ClapTrap::getClassHitPoints(void) const {
	return (this->classHitPoints);
}

const std::string	ClapTrap::getClassName(void) const {
	return (this->className);
}
