/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:59:49 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/25 10:01:31 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
public:
	Animal();
	Animal(Animal const & src);

	/*
	 * Used to free the object, while deleting instances of the derived class
	 * using a base class pointer.
	 * Using a virtual base class destructor ensure that both base class and derived
	 * class destructor will be called.
	 */
	virtual ~Animal();

	virtual Animal & operator=(Animal const & rhs);

	std::string getType() const;

	virtual void makeSound() const;

	virtual Brain *getBrain() const = 0;

protected:
	std::string _type;

};
