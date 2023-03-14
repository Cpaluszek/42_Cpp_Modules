/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:11:22 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/14 10:25:44 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
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
	void		addContact(const Contact& newContact);
	void 		printPhoneBook() const;
	void		getContactInfo() const;

	// Static
	static void	displayCommands();

private:
	Contact _contacts[PHONEBOOK_SIZE];
	int 	_currentSize;
	int 	_lastContactIndex;

	Contact		getContact(int contactIndex) const;
};

#endif
