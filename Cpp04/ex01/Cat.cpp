/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:09:14 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/25 10:13:21 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "Cat copy constructor" << std::endl;
	this->_type = src.getType();
	*(this->_brain) = *(src.getBrain());
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat copy assignment" << std::endl;
	if (this != &rhs) {
		this->_type = rhs.getType();
		*(this->_brain) = *(rhs.getBrain());
	}
	return *this;
}

Animal &Cat::operator=(const Animal &rhs) {
	std::cout << "Animal copy assignment called from cat" << std::endl;
	if (this != &rhs) {
		this->_type = rhs.getType();
		*(this->_brain) = *(rhs.getBrain());
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
	return this->_brain;
}
