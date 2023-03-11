/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:22:01 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/11 18:54:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "--- PhoneBook Constructor called ---" << std::endl;
	this->_currentSize = 0;
	this->_lastContactIndex = 0;
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
