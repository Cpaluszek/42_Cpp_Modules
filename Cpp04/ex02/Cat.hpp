/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:08:07 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 09:52:54 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat(const Cat & src);

	Cat & operator=(const Cat & rhs);
	Animal & operator=(const Animal & rhs);

	void makeSound() const;
	Brain *getBrain() const;

private:
	Brain* _brain;
};
