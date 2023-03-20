/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:36:25 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/19 11:37:35 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal & src);

	WrongAnimal & operator=(const WrongAnimal & rhs);

	void 		makeSound() const;
	std::string getType() const;

protected:
	std::string _type;
};
