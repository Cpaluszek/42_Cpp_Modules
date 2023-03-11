/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:55:31 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/11 19:44:28 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

static void DisplayCommands();
static void AddContact(PhoneBook *phoneBook);
static int GetContactField(std::string *fieldContent, const std::string& identifier);
static void PrintPhoneBook(PhoneBook *phoneBook);
static void PrintLine(std::string content);
static void PrintContactInfo(const Contact& contact);
static void GetContactInfo(PhoneBook *phoneBook);

int	main() {
	PhoneBook phoneBook;
	std::string userInput;

	std::cout << GREEN << "Welcome to this crappy phonebook software!" << END << std::endl;
	DisplayCommands();
	while (true) {
		std::cout << BLUE << "Enter a command: " << END;
		std::getline(std::cin, userInput);
		if (std::cin.eof())
			return (1);
		if (userInput == "ADD")
			AddContact(&phoneBook);
		else if (userInput == "SEARCH")
			PrintPhoneBook(&phoneBook);
		else if (userInput == "EXIT")
			return 0;
		else {
			std::cout << RED << userInput << ": is a not a valid command" << END << std::endl;
			DisplayCommands();
		}
	}
}

static void DisplayCommands() {
	std::cout << "Available commands are:" << std::endl;
	std::cout << "\t- " << BOLD << "ADD" << END << ": save a new contact" << std::endl;
	std::cout << "\t- " << BOLD << "SEARCH" << END << ": display a specific contact information" << std::endl;
	std::cout << "\t- " << BOLD << "EXIT" << END << ": to deliver yourself" << std::endl << std::endl;
}

static void AddContact(PhoneBook *phoneBook) {
	std::string contactInformation[5];

	if (GetContactField(&contactInformation[0], "First name"))
		return ;
	if (GetContactField(&contactInformation[1], "Last name"))
		return ;
	if (GetContactField(&contactInformation[2], "Nickname"))
		return ;
	if (GetContactField(&contactInformation[3], "Phone number"))
		return ;
	if (GetContactField(&contactInformation[4], "Darkest secret"))
		return ;
	Contact newContact(contactInformation);
	phoneBook->AddContact(newContact);
}

static int GetContactField(std::string *fieldContent, const std::string& identifier) {
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

static void PrintPhoneBook(PhoneBook *phoneBook) {
	int currentSize = phoneBook->GetPhoneBookSize();

	if (currentSize == 0) {
		std::cout << RED << "PhoneBook is currently empty" << END << std::endl;
		return ;
	}
	PrintLine("INDEX");
	PrintLine("FIRST NAME");
	PrintLine("LAST NAME");
	PrintLine("NICKNAME");
	std::cout << std::endl;
	for (int i = 0 ; i < currentSize; i++) {
		std::cout << std::setw(10) << std::left << std::setfill(' ') << i << "|";
		PrintContactInfo(phoneBook->GetContact(i));
	}
	GetContactInfo(phoneBook);
}

static void PrintLine(std::string content) {
	content.length() > 10 ? content = content.substr(0, 9).append(".") : content;
	std::cout << std::setw(10) << std::left << std::setfill(' ') << content << "|";
}

static void PrintContactInfo(const Contact& contact) {
	std::string firstName = contact.GetFirstName();
	std::string lastName = contact.GetLastName();
	std::string nickName= contact.GetNickname();

	PrintLine(firstName);
	PrintLine(lastName);
	PrintLine(nickName);
	std::cout << std::endl;
}

static void GetContactInfo(PhoneBook *phoneBook) {
	std::string indexInput;
	int entryIndex = PHONEBOOK_SIZE;
	int phoneBookLastIndex = phoneBook->GetPhoneBookSize() - 1;
	Contact contact;

	std::cout << BLUE << "Contact index to display: " << END;
	std::getline(std::cin, indexInput);
	if (std::cin.eof())
		return ;
	while (indexInput.length() != 1 || !std::isdigit(indexInput[0]) || entryIndex > phoneBookLastIndex)
	{
		std::cout << RED << indexInput << " is not a valid index, please give an index between 0 and " << phoneBookLastIndex << END << std::endl;
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
	contact = phoneBook->GetContact(entryIndex);
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "First Name: " << END << contact.GetFirstName() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Last Name: " << END << contact.GetLastName() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Nick Name: " << END << contact.GetNickname() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Phone Number: " << END << contact.GetPhoneNumber() << std:: endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << BOLD << "Darkest Secret: " << END << contact.GetDarkestSecret() << std:: endl;
}