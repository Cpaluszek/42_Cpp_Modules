/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:56:01 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/14 17:51:11 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl() {
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
	this->_functPtrs[0] = &Harl::debug;
	this->_functPtrs[1] = &Harl::info;
	this->_functPtrs[2] = &Harl::warning;
	this->_functPtrs[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG" << std::endl;
}

void Harl::info() {
	std::cout << "INFO" << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING" << std::endl;
}

void Harl::error() {
	std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < LEVELS_SIZE; i++) {
		if (level == this->_levels[i]) {
			(this->*(_functPtrs[i]))();
			return ;
		}
	}
	std::cerr << "Harl cannot complain about: " << level << std::endl;
}
