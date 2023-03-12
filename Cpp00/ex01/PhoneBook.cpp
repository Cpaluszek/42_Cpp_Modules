/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:22:01 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 11:28:22 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentSize(0), _lastContactIndex(0) {
	std::cout << "--- PhoneBook Constructor called ---" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "--- PhoneBook Destructor called ---" << std::endl;
}

void PhoneBook::AddContact(const Contact& newContact) {
	if (this->_currentSize < PHONEBOOK_SIZE) {
		this->_contacts[_currentSize] = newContact;
		_currentSize++;
		return ;
	}
	this->_contacts[_lastContactIndex] = newContact;
	this->_lastContactIndex = (this->_lastContactIndex + 1) % PHONEBOOK_SIZE;
}

int PhoneBook::GetPhoneBookSize() const {
	return this->_currentSize;
}

Contact PhoneBook::GetContact(int contactIndex) const {
	return this->_contacts[contactIndex];
}

void PhoneBook::DisplayCommands() {
	std::cout << "Available commands are:" << std::endl;
	std::cout << "\t- " << BOLD << "ADD" << END << ": save a new contact" << std::endl;
	std::cout << "\t- " << BOLD << "SEARCH" << END << ": display a specific contact information" << std::endl;
	std::cout << "\t- " << BOLD << "EXIT" << END << ": to deliver yourself" << std::endl << std::endl;
}

void PhoneBook::PrintPhoneBook() {

	if (this->_currentSize == 0) {
		std::cout << RED << "PhoneBook is currently empty" << END << std::endl;
		return ;
	}
	Contact::PrintLine("INDEX");
	Contact::PrintLine("FIRST NAME");
	Contact::PrintLine("LAST NAME");
	Contact::PrintLine("NICKNAME");
	std::cout << std::endl;
	for (int i = 0 ; i < this->_currentSize; i++) {
		std::cout << std::setw(10) << std::left << std::setfill(' ') << i << "|";
		this->GetContact(i).PrintContactInfo();
	}
	this->GetContactInfo();
}

void PhoneBook::GetContactInfo() {
	std::string indexInput;
	int entryIndex = PHONEBOOK_SIZE;
	Contact contact;

	std::cout << BLUE << "Contact index to display: " << END;
	std::getline(std::cin, indexInput);
	if (std::cin.eof())
		return ;
	while (indexInput.length() != 1 || !std::isdigit(indexInput[0]) || entryIndex > this->_currentSize - 1)
	{
		std::cout << RED << indexInput << " is not a valid index, please give an index between 0 and " << this->_currentSize - 1 << END << std::endl;
		std::cout << BLUE << "Contact index to display: " << END;
		std::getline(std::cin, indexInput);
		if (std::cin.eof())
			return ;
		if (indexInput.length() == 1 && std::isdigit(indexInput[0])) {
			std::istringstream s(indexInput);
			s >> entryIndex;
			std::cout << "result index: " << entryIndex;
		}
	}
	std::cout << std::endl;
	contact = this->GetContact(entryIndex);
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "First Name: " << END << contact.GetFirstName() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Last Name: " << END << contact.GetLastName() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Nick Name: " << END << contact.GetNickname() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Phone Number: " << END << contact.GetPhoneNumber() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Darkest Secret: " << END << contact.GetDarkestSecret() << std:: endl;
}

