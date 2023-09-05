
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	private:
		std::string name;
		Weapon		*weapon;

	public:
		HumanB(const std::string _name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
		~HumanB();

};


#endif
