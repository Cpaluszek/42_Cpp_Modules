/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:59 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/26 11:40:34 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <climits>
#include <bits/stdc++.h>

class ScalarConverter {
public:
	static void convert(std::string const & literal);

private:
	static void printChar(std::string const & literal);
	static void printInt(std::string const & literal);
	static void printFloat(std::string const & literal);
	static void printDouble(std::string const & literal);

	static bool checkInt(std::string const & literal);
	static bool checkFloat(std::string const & literal);
	static bool checkDouble(std::string const & literal);

	ScalarConverter();
};
