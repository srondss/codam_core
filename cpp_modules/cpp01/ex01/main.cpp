
#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;
	int i = 0;
	int N = 5;

	zombies = zombieHorde(N, "Youssef");
	while (i < N)
	{
		(zombies[i]).announce();
		i++;
	}

	delete[] zombies;

	return (0);
}
