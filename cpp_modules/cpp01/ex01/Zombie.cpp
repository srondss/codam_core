
#include "Zombie.hpp"


Zombie::Zombie()
{}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name + ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " has been destroyed." << std::endl;
}
