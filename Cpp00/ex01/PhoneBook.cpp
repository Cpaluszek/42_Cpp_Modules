/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:22:01 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/13 11:39:32 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentSize(0), _lastContactIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& newContact) {
	if (this->_currentSize < PHONEBOOK_SIZE) {
		this->_contacts[_currentSize] = newContact;
		_currentSize++;
		return ;
	}
	this->_contacts[_lastContactIndex] = newContact;
	this->_lastContactIndex = (this->_lastContactIndex + 1) % PHONEBOOK_SIZE;
}

Contact PhoneBook::getContact(int contactIndex) const {
	return this->_contacts[contactIndex];
}

void PhoneBook::displayCommands() {
	std::cout << "Available commands are:" << std::endl;
	std::cout << "\t- " << BOLD << "ADD" << END << ": save a new contact" << std::endl;
	std::cout << "\t- " << BOLD << "SEARCH" << END << ": display a specific contact information" << std::endl;
	std::cout << "\t- " << BOLD << "EXIT" << END << ": to deliver yourself" << std::endl << std::endl;
}

void PhoneBook::printPhoneBook() const {

	if (this->_currentSize == 0) {
		std::cout << RED << "PhoneBook is currently empty" << END << std::endl;
		return ;
	}
	Contact::printLine("INDEX");
	Contact::printLine("FIRST NAME");
	Contact::printLine("LAST NAME");
	Contact::printLine("NICKNAME");
	std::cout << std::endl;
	for (int i = 0 ; i < this->_currentSize; i++) {
		std::cout << std::setw(10) << std::right << std::setfill(' ') << i << "|";
		this->getContact(i).printContactInfo();
	}
	this->getContactInfo();
}

void PhoneBook::getContactInfo() const {
	std::string indexInput;
	int entryIndex = -1;

	while (entryIndex == -1)
	{
		std::cout << BLUE << "Contact index to display: " << END;
		std::getline(std::cin, indexInput);
		if (std::cin.eof())
			return ;
		if (indexInput.length() == 1 && std::isdigit(indexInput[0])) {
			std::istringstream s(indexInput);
			s >> entryIndex;
			if (entryIndex > this->_currentSize - 1) {
				std::cout << RED << indexInput << " is not a valid index, please give an index between 0 and "
						  << this->_currentSize - 1 << END << std::endl;
				entryIndex = -1;
			}
		}
		else
			std::cout << RED << indexInput << " is not a valid index, please give an index between 0 and " << this->_currentSize - 1 << END << std::endl;
		indexInput.clear();
	}
	Contact contact = this->getContact(entryIndex);
	std::cout << std::setw(15) << std::right << std::setfill(' ') << BOLD << "First Name: " << END << contact.getFirstName() << std:: endl;
	std::cout << std::setw(15) << std::right << std::setfill(' ') << BOLD << "Last Name: " << END << contact.getLastName() << std:: endl;
	std::cout << std::setw(15) << std::right << std::setfill(' ') << BOLD << "Nick Name: " << END << contact.getNickname() << std:: endl;
	std::cout << std::setw(15) << std::right << std::setfill(' ') << BOLD << "Phone Number: " << END << contact.getPhoneNumber() << std:: endl;
	std::cout << std::setw(15) << std::right << std::setfill(' ') << BOLD << "Darkest Secret: " << END << contact.getDarkestSecret() << std:: endl;
}

