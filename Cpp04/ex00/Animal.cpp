/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:01:15 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/19 11:07:33 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type) {
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	this->_type = rhs._type;
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "..." << std::endl;
}
