
#include "HumanB.hpp"

HumanB::HumanB(const std::string _name) : name(_name)
{
	this->weapon = new Weapon("bare hands");
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their bare hands!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	delete this->weapon;
	this->weapon = &weapon;
}

HumanB::~HumanB(void)
{
}
