
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	public:
		void	attack(void);
		HumanB(std::string name);
		HumanB(std::string name, Weapon weapon);

	private:
		std::string name;
		Weapon		weapon;

};


#endif
