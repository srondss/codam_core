#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>

class Zombie {

	public:
		void announce( void );
		Zombie();
		Zombie(std::string name);
		~Zombie();

	private:
		std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
