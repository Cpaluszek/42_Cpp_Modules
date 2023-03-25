/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:07:38 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 09:52:54 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const Dog & src);

	Dog & operator=(const Dog & rhs);
	Animal & operator=(const Animal & rhs);

	void makeSound() const;
	Brain *getBrain() const;

private:
	Brain* _brain;
};
