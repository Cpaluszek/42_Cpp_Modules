/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:11:22 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/11 19:38:23 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define PHONEBOOK_SIZE	8

# define END	"\033[0m"
# define BOLD	"\033[1m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	AddContact(const Contact& newContact);
	int		GetPhoneBookSize() const;
	Contact	GetContact(int contactIndex) const;

private:
	Contact _contacts[PHONEBOOK_SIZE];
	int 	_currentSize;
	int 	_lastContactIndex;
};

#endif
