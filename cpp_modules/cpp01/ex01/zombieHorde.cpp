#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	int	i = 0;

	while (i < N)
	{
        new (&zombies[i]) Zombie(name); // Placement new to construct Zombies directly in the allocated memory
		i++;
	}
	return (zombies);
}
