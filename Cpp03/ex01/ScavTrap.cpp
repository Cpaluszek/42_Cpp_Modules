/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:32:41 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 13:32:41 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor: " << name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor: " << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	ClapTrap::operator=(rhs);
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints < 1 || _hitPoints < 1)
		return ;
	this->_energyPoints -= 1;
	std::cout << "ScavTrap: " << this->_name << " attacks " << target
			  << ", causing " << this->_hitPoints << " points of damage, "
			  << " Remaining energy: " << this->_energyPoints << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << this->_name << " is now in Gate Keeper mode" << std::endl;
}
