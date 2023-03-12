/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:21:51 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 12:11:50 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string contactInformation[5])
	:_firstName(contactInformation[0]), _lastName(contactInformation[1]),
	_nickname(contactInformation[2]), _phoneNumber(contactInformation[3]),
	_darkestSecret(contactInformation[4])
{}

Contact::~Contact() {}

std::string Contact::GetFirstName() const {
	return this->_firstName;
}

std::string Contact::GetLastName() const {
	return this->_lastName;
}

std::string Contact::GetNickname() const {
	return this->_nickname;
}

std::string Contact::GetPhoneNumber() const {
	return this->_phoneNumber;
}

std::string Contact::GetDarkestSecret() const {
	return this->_darkestSecret;
}

void Contact::PrintContactInfo() const {
	PrintLine(this->_firstName);
	PrintLine(this->_lastName);
	PrintLine(this->_nickname);
	std::cout << std::endl;
}

void Contact::PrintLine(std::string content) {
	content.length() > 10 ? content = content.substr(0, 9).append(".") : content;
	std::cout << std::setw(10) << std::left << std::setfill(' ') << content << "|";
}
