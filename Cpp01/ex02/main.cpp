/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:47:44 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/13 12:47:46 by cpalusze         ###   ########.fr       */
/*                                                                            */

/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
	std::string welcomeMessage = "HI THIS IS BRAIN";
	std::string *stringPTR = &welcomeMessage;
	std::string &stringREF = welcomeMessage;

	std::cout << "Memory addresses:" << std::endl;
	std::cout << "\t- string: " << &welcomeMessage << std::endl;
	std::cout << "\t- stringPTR: " << stringPTR << std::endl;
	std::cout << "\t- stringREF: " << &stringREF << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << "\t- string: " << welcomeMessage << std::endl;
	std::cout << "\t- stringPTR: " << *stringPTR << std::endl;
	std::cout << "\t- stringREF: " << stringREF << std::endl;
}
