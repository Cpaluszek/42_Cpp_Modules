/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:16:43 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/19 11:16:43 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
