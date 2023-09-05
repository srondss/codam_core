#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

	private:
		std::string type;

	public:
		Weapon(const std::string& _type)
			: type(_type) {}
		std::string getType(void);
		void		setType(const std::string& type);

};

#endif
