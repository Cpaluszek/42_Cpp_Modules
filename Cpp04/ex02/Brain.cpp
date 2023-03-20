/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:24 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 09:49:50 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << "Brain copy assignment" << std::endl;
	for (int i = 0; i < BRAIN_SIZE; i++) {
		this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
