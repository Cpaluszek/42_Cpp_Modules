/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:11:14 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/07 15:25:45 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::perror(argv[1]);
		return 1;
	}

	std::string buffer;
	std::string left, right;
	float value;

	try {
		BitcoinExchange btc;
		while (std::getline(inputFile, buffer)) {
			if (buffer == "date | value") continue ;
			if (buffer.find('|') == std::string::npos) {
				std::cerr <<  RED << "Error: missing | separator" << END << std::endl;
				continue;
			}
			BitcoinExchange::splitStr(buffer, '|', left, right);
			if (BitcoinExchange::checkDateError(left) || BitcoinExchange::checkAmountError(right)) {
				continue ;
			}
			value = strtod(right.c_str(), NULL);
			btc.convert(left.substr(0, 10), value);
		}
	}
	catch (const std::exception & e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	inputFile.close();
}
