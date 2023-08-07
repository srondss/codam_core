
#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie; // this instantiates a zombie pointer
	zombie = newZombie("Alice"); // uses new because it allocates a new class
	zombie->announce(); // show that Alice exists
	randomChump("Bob");
	delete zombie; // because zombie is on the heap you have to free it.
	return (0);
}
