
#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		int numContacts;
		Contact	contacts[MAX_CONTACTS];

	public:
		PhoneBook();

		void	addContact();
		int		getNumContacts() const;
		void	displayContact();

};

#endif
