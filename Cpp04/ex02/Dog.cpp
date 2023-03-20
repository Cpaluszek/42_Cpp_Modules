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
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal() {
	std::cout << "Dog copy constructor" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain();
	this->_brain = src._brain;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog copy assignment" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
