/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:21:51 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/11 18:16:44 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string contactInformation[5])
	:_firstName(contactInformation[0]), _lastName(contactInformation[1]),
	_nickname(contactInformation[2]), _phoneNumber(contactInformation[3]),
	_darkestSecret(contactInformation[5])
{
	std::cout << "--- Contact Constructor called ---" << std::endl;
}

Contact::~Contact() {
	std::cout << "--- Contact Destructor called ---" << std::endl;
}

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

