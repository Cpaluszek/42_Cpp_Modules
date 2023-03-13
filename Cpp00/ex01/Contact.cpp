/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:21:51 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/13 11:43:06 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string contactInformation[5])
	:_firstName(contactInformation[0]), _lastName(contactInformation[1]),
	_nickname(contactInformation[2]), _phoneNumber(contactInformation[3]),
	_darkestSecret(contactInformation[4]) {}


Contact::~Contact() {}

std::string Contact::getFirstName() const {
	return this->_firstName;
}

std::string Contact::getLastName() const {
	return this->_lastName;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}

void Contact::printContactInfo() const {
	printLine(this->_firstName);
	printLine(this->_lastName);
	printLine(this->_nickname);
	std::cout << std::endl;
}

void Contact::printLine(std::string content) {
	content.length() > 10 ? content = content.substr(0, 9).append(".") : content;
	std::cout << std::setw(10) << std::right << std::setfill(' ') << content << "|";
}
