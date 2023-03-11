/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:11:55 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/11 17:33:24 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {
public:
	Contact();
	Contact(std::string contactInformation[5]);
	~Contact();

	// Getters
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickname() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
