
#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::debug(void) {
	std::cout << "Debug Message" << std::endl;
}

void Harl::info(void) {
	std::cout << "Info Message" << std::endl;
}

void Harl::warning(void) {
	std::cout << "Warning Message" << std::endl;
}

void Harl::error(void) {
	std::cout << "Error Message" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "Invalid complaint.\nPlease choose from 4 options: debug, info, warning, error." << std::endl;
}
