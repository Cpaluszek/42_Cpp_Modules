/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:33:02 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 13:36:52 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor: " << name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor: " << this->_name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::attack(const std::string &target) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	this->_energyPoints -= 1;
	std::cout << "FragTrap: " << this->_name << " attacks " << target
			  << ", causing " << this->_hitPoints << " points of damage, "
			  << " Remaining energy: " << this->_energyPoints << std::endl;
}

void FragTrap::HighFiveGuys() {
	std::cout << "FragTrap " << this->_name << " High five" << std::endl;
}
