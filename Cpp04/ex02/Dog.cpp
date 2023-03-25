/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:16:43 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 10:02:54 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog &src) : Animal() {
	std::cout << "Dog copy constructor" << std::endl;
	this->_type = src.getType();
	*(this->_brain) = *(src.getBrain());
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog copy assignment" << std::endl;
	if (this != &rhs) {
		this->_type = rhs.getType();
		*(this->_brain) = *(rhs.getBrain());
	}
	return *this;
}

Animal &Dog::operator=(const Animal &rhs) {
	std::cout << "Animal copy assignment called from Dog" << std::endl;
	if (this != &rhs) {
		this->_type = rhs.getType();
		*(this->_brain) = *(rhs.getBrain());
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain() const {
	return this->_brain;
}
