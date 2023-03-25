/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:10:04 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/25 10:18:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	Animal* animals[100];
	for (int i = 0; i < 100; i++) {
		if (i % 2) {
			animals[i] = new Dog();
		}
		else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < 100; i++) {
		delete animals[i];
	}
	{
		Animal *animals[2];
		animals[0] = new Dog();
		animals[1] = new Cat();

		Brain *brain = animals[1]->getBrain();
		brain->_ideas[0] = "test";
		brain->_ideas[1] = "idea";
		std::cout << "-------- Assigment operator --------" << std::endl;
		*(animals[0]) = *(animals[1]);
		std::cout << "-------- Brain content --------" << std::endl;
		std::cout << animals[0]->getBrain()->_ideas[0] << std::endl;
		std::cout << animals[0]->getBrain()->_ideas[1] << std::endl;
		std::cout << "-------- Destructors --------" << std::endl;
		delete animals[0];
		delete animals[1];
	}
	return 0;
}
