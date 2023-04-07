/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:21:09 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/07 15:28:28 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream dataFile(DATABASE_PATH);
	if (!dataFile.is_open()) {
		throw std::ios_base::failure(std::string("BitcoinExchange: ") + DATABASE_PATH);
	}
	std::string buffer;
	std::string key, value;
	while (std::getline(dataFile, buffer)) {
		if (buffer == "date,exchange_rate") {
			continue ;
		}
		splitStr(buffer, ',', key, value);
		this->_dataSet[key] = strtod(value.c_str(), NULL);
	}
	dataFile.close();
	std::cout << "... dataSet created, contains " << this->_dataSet.size() << " entries ..." << std::endl;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _dataSet(src._dataSet) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	this->_dataSet = src._dataSet;
	return *this;
}

void BitcoinExchange::convert(std::string date, float value) const {
	float dollarValue;

	if (date < this->_dataSet.begin()->first) {
		std::cout << "Btc did not exist in " << date << std::endl;
		return ;
	}
	for (std::map<std::string, float>::const_iterator it = this->_dataSet.begin(); it != this->_dataSet.end(); it++) {
		if (it->first >= date) {
			if (it->first > date) {
				it--;
			}
			dollarValue = value * it->second;
			break ;
		}
	}
	std::cout << date << "-> " << value << " BTC = " << dollarValue << "$" << std::endl;
}

void BitcoinExchange::splitStr(const std::string &input, const char sep,
							   std::string &left, std::string &right) {
	size_t pos = input.find(sep);
	if (pos != std::string::npos) {
		left = input.substr(0, pos);
		right = input.substr(pos + 1);
	}
	else {
		left = input;
		right = "";
	}
}

bool BitcoinExchange::checkAmountError(const std::string &value) {
	if (value.length() == 0) {
		std::cerr << RED << "Error: no value found" << END << std::endl;
		return true;
	}
	if (value[0] != ' ') {
		std::cerr << RED << "Error: space is required after | separator" << END << std::endl;
		return true;
	}
	if (!std::isdigit(value[1])) {
		std::cerr << RED << "Error: invalid value, only numbers are allowed" << END << std::endl;
		return true;
	}

	size_t dot = value.find('.');
	if (dot != std::string::npos) {
		if (value.find('.', dot + 1) != std::string::npos) {
			std::cerr << RED << "Error: invalid float format" << END << std::endl;
			return true;
		}
	}
	for (size_t i = 1; i < value.length(); i++) {
		if (value[i] != '.' && !std::isdigit(value[i])) {
			std::cerr << RED << "Error: invalid float format" << END << std::endl;
			return true;
		}
	}

	float amount = strtod(value.c_str(), NULL);
	if (amount < 0.0f || amount > 1000.0f) {
		std::cerr << RED <<"Error: value must be between 0 and 1000" << END << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::checkDateError(const std::string &date) {
	if (date.length() != 11) {
		std::cerr << RED << "Error: invalid date format" << END << std::endl;
		return true;
	}
	for (size_t i = 0; i < date.length() - 1; i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-') {
				std::cerr << RED << "Error: invalid date format" << END << std::endl;
				return true;
			}
		}
		else if (!std::isdigit(date[i])) {
			std::cerr << RED << "Error: invalid date format" << END << std::endl;
			return true;
		}
	}
	int day, month, year;
	year = atoi(date.c_str());
	month = atoi(date.c_str() + 5);
	day = atoi(date.c_str() + 8);
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year)) {
		days[1] = 29;
	}
	if (month < 1 || month > 12) {
		std::cerr << RED << "Error: invalid month" << END << std::endl;
		return true;
	}
	if (day < 1 || day > days[month - 1]) {
		std::cerr << RED << "Error: invalid day" << END << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::isLeapYear(unsigned int year) {
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 != 0)
		return false;
	return true;
}
