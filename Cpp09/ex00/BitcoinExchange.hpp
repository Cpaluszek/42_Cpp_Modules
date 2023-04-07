/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:11:41 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/07 15:00:33 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <fstream>

# define END	"\033[0m"
# define BOLD	"\033[1m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"

#define DATABASE_PATH "data.csv"

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	void convert(std::string date, float value) const;

	static void splitStr(std::string const & input, char const sep,
						 std::string & left, std::string & right);

	static bool checkAmountError(std::string const & value);
	static bool checkDateError(std::string const &date);

private:
	std::map<std::string, float> _dataSet;

	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator=(BitcoinExchange const & src);

	static bool isLeapYear(unsigned int year);
};
