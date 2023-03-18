/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:13:09 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/18 10:27:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name), FragTrap(name), ScavTrap(name){
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";

	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
	std::cout << "DiamondTrap constructor: " << name << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor: " << this->_name << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}