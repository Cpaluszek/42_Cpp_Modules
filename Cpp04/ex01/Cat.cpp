/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:09:14 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 10:02:54 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "Cat copy constructor" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain();
	this->_brain = src._brain;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat copy assignment" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
