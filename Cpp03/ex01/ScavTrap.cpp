//
// Created by cpalusze on 3/17/23.
//

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

void ScavTrap::guardGate() {
	std::cout << this->_name << " is now in Gate Keeper mode" << std::endl;
}
