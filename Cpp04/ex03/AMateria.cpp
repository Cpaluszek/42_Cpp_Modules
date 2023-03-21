/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:24:10 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 11:32:40 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(const AMateria &src) : _type(src._type) {
}

AMateria::~AMateria() {
}

AMateria::AMateria(const std::string &type) : _type(type) {
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
