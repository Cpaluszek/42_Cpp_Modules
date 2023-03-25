/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:51:58 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/25 11:10:16 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::vector<AMateria*> Character::_trash;

Character::Character() : _name("random") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &src) : _name(src._name)  {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
	Character::clearTrash();
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
	std::cout << "Not enough space in inventory to equip" << std::endl;
}

void Character::unequip(int idx) {
	if (this->_inventory[idx] != NULL)
	{
		Character::_trash.push_back(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
		std::cout << this->_name << " unequipped [" << idx << "]" << std::endl;
	}
	else {
		std::cout << this->_name << " Cannot unequip [" << idx << "]" << std::endl;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	}
}

void Character::clearTrash() {
	std::vector<AMateria*>::iterator it;
	int i = 0;
	for (it = Character::_trash.begin(); it != Character::_trash.end(); it++, i++) {
		delete Character::_trash[i];
	}
	Character::_trash.clear();
}
