/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:59:49 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/19 11:19:37 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

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

	Animal & operator=(Animal const & rhs);

	std::string getType() const;

	virtual void makeSound() const;

protected:
	std::string _type;

};
