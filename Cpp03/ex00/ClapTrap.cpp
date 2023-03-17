/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:44:16 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 11:39:20 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_hitPoints(10), _eneryPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default Constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) :
	_name(src._name), _hitPoints(src._hitPoints),
	_eneryPoints(src._eneryPoints), _attackDamage(src._hitPoints) {
	std::cout << "ClapTrap copy constructor" << std::endl;
}


ClapTrap::ClapTrap(const std::string &name) :
	_name(name), _hitPoints(10), _eneryPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor: " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor: " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_eneryPoints = rhs._eneryPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string & target) {
	if (_eneryPoints < 1 || _hitPoints < 1)
		return ;
	this->_eneryPoints -= 1;
	std::cout << this->_name << " attacks " << target
			  << ", causing " << this->_hitPoints << " points of damage, "
			  << " Remaining energy: " << this->_eneryPoints << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << this->_name << " took " << amount
		<< " points of damage, " << this->_hitPoints << " hitpoints left."
		<< std::endl;
}

void ClapTrap::beRepaired(int amount) {
	if (_eneryPoints < 1 || amount < 1)
		return ;
	this->_hitPoints += amount;
	this->_eneryPoints -= 1;
	std::cout << this->_name << " was repaired by " << amount
			  << " points, " << this->_hitPoints << " hitpoints left"
			  << " Remaining energy: " << this->_eneryPoints << std::endl;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

unsigned int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int value) {
	this->_attackDamage = value;
}
