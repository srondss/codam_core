
#include "Weapon.hpp"

std::string Weapon::getType(void)
{
	return (this->type);
}

void		Weapon::setType(const std::string& type)
{
	std::cout << this->type;
	this->type = type;
	std::cout << " changed to " << this->type << std::endl;
	return;
}

