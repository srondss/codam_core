
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

int	main(void)
{
	PhoneBook	PhoneBook;
	Contact		Contact;
	std::string userInput;

	std::cout << "Welcome to your phonebook!" << std::endl;
    std::cout << "Use ADD to add contacts, SEARCH to check your phonebook and EXIT to quit." << std::endl;
    std::cout << "WARNING! All your contacts will be deleted once you write EXIT." << std::endl;
	while (1)
	{
		std::cout << std::endl << "Your command: ";
		std::getline(std::cin, userInput);
		if (userInput.compare("ADD") == 0)
			PhoneBook.addContact();
		else if (userInput.compare("SEARCH") == 0)
			PhoneBook.displayContact();
		else if (userInput.compare("EXIT") == 0)
			return (EXIT_SUCCESS);
		else if (userInput.compare("\0") == 0)
			continue ;
		else
			std::cout << "Sorry, that command does not exist. Commands are case-sensitive." << std::endl;
	}

	return (EXIT_FAILURE);
}
