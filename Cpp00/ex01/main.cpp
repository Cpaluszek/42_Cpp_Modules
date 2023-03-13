/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:55:31 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 11:23:49 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

static void addContact(PhoneBook *phoneBook);
static int getContactField(std::string *fieldContent, const std::string& identifier);

int	main() {
	PhoneBook phoneBook;
	std::string userInput;

	std::cout << GREEN << "Welcome to this crappy phonebook software!" << END << std::endl;
	PhoneBook::displayCommands();
	while (true) {
		std::cout << BLUE << "Enter a command: " << END;
		std::getline(std::cin, userInput);
		if (std::cin.eof())
			return (1);
		if (userInput == "ADD")
			addContact(&phoneBook);
		else if (userInput == "SEARCH")
			phoneBook.printPhoneBook();
		else if (userInput == "EXIT")
			return 0;
		else {
			std::cout << RED << userInput << ": is a not a valid command" << END << std::endl;
			PhoneBook::displayCommands();
		}
	}
}

static void addContact(PhoneBook *phoneBook) {
	std::string contactInformation[5];

	if (getContactField(&contactInformation[0], "First name"))
		return ;
	if (getContactField(&contactInformation[1], "Last name"))
		return ;
	if (getContactField(&contactInformation[2], "Nickname"))
		return ;
	if (getContactField(&contactInformation[3], "Phone number"))
		return ;
	if (getContactField(&contactInformation[4], "Darkest secret"))
		return ;
	Contact newContact(contactInformation);
	phoneBook->addContact(newContact);
}

static int getContactField(std::string *fieldContent, const std::string& identifier) {
	std::cout << identifier << ": ";
	std::getline(std::cin, *fieldContent);
	if (std::cin.eof())
		return 1;
	while (fieldContent->empty())
	{
		std::cout << RED << "A contact can't have empty field" << END << std::endl;
		std::cout << identifier << ": ";
		std::getline(std::cin, *fieldContent);
	}
	return 0;
}
