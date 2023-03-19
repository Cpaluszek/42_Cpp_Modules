/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:09:14 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/19 11:16:00 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;

}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
