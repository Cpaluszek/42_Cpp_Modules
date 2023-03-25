/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:25:43 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/25 11:03:08 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
		if (rhs._materias[i] != NULL)
			this->_materias[i] = rhs._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	return *this;
}

AMateria *MateriaSource::getMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
			return this->_materias[i];
		}
	}
	return NULL;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			return ;
		}
	}
	std::cout << "Can't learn any more materia" << std::endl;
}
