
#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook()
{
	numContacts = 0;
}

void	PhoneBook::addContact()
{
	static int	contactToReplace = 0;
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	if (contactToReplace == 8)
		contactToReplace = 0;

	std::cout << "Enter contact's first name:\n> ";
	std::getline(std::cin, firstName);
	while (firstName.compare("\0") == 0)
	{
		std::cout << "First Name cannot be empty. Try again." << std::endl;
		std::getline(std::cin, firstName);
	}
	std::cout << "Enter contact's last name:\n> ";
	std::getline(std::cin, lastName);
	while (lastName.compare("\0") == 0)
	{
		std::cout << "Last Name cannot be empty. Try again." << std::endl;
		std::getline(std::cin, lastName);
	}
	std::cout << "Enter contact's nickname:\n> ";
	std::getline(std::cin, nickname);
	while (nickname.compare("\0") == 0)
	{
		std::cout << "Nickname cannot be empty. Try again." << std::endl;
		std::getline(std::cin, nickname);
	}
	std::cout << "Enter contact's phone number:\n> ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.compare("\0") == 0)
	{
		std::cout << "Phone number cannot be empty. Try again." << std::endl;
		std::getline(std::cin, phoneNumber);
	}
	std::cout << "Enter contact's darkest secret:\n> ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.compare("\0") == 0)
	{
		std::cout << "Darkest Secret cannot be empty. Try again." << std::endl;
		std::getline(std::cin, darkestSecret);
	}

	contact.setFirstName(firstName);
	contact.setLastName(lastName);
	contact.setNickname(nickname);
	contact.setPhoneNumber(phoneNumber);
	contact.setDarkestSecret(darkestSecret);

	contacts[contactToReplace] = contact;
	contactToReplace++;
	if (numContacts != 8)
		numContacts++;
	std::cout << firstName << " has been added to your contact list." << std::endl;
	std::cout << "Number of contacts in your contact list: " << numContacts << std::endl;
}

void	PhoneBook::displayContact()
{
	int index = -1;
	int	i = 0;
	std::string firstName;
	std::string lastName;
	std::string nickname;

	std::cout << std::endl;
	std::cout << std::setw(10) << "Index";
	std::cout << std::setw(10) << " First Name";
    std::cout << std::setw(10) << " Last Name";
    std::cout << std::setw(10) << " Nickname" << std::endl;

	while (i < numContacts)
	{
		firstName = contacts[i].getFirstName();
		lastName = contacts[i].getLastName();
		nickname = contacts[i].getNickname();
		std::cout << std::setw(10) << i << '|';
		if (firstName.length() > 10)
        	std::cout << firstName.substr(0, 9) + '.';
		else
			std::cout << std::setw(10) << firstName;
		std::cout << '|';
        if (lastName.length() > 10)
			std::cout << lastName.substr(0, 9) + '.';
		else
			std::cout << std::setw(10) << lastName;
			std::cout << '|';
		if (nickname.length() > 10)
			std::cout << nickname.substr(0, 9) + '.';
		else
			std::cout << std::setw(10) << nickname;
		std::cout << std::endl;
		i++;
	}
	if (numContacts > 0)
	{
		std::cout << std::endl << "Input contact index for more information." << std::endl;
		std::cin >> index;
		while (std::cin.fail() || index > 7 || index > (numContacts - 1) || index < 0)
		{
			if (index > 7 || index > (numContacts - 1) || index < 0)
				std::cout << "Index in contact list doesn't exist. Please try again." << std::endl;
			else
				std::cout << "Incorrect input. Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> index;
		}
		std::cout << "First name: " <<		contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " <<		contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " <<		contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << 	contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << 	contacts[index].getDarkestSecret() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << std::endl << "No contacts in your contact list." << std::endl;
	}
}
