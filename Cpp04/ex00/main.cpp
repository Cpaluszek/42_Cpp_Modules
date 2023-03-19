/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:10:04 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/19 11:51:33 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "-------- Animals ---------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "-------- Types ---------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "-------- Sounds ---------" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "-------- Delete ---------" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "-------- Wrong Animals ---------" << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "-------- Types ---------" << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << "-------- Sounds ---------" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << "-------- static link ---------" << std::endl;
	{
		WrongCat cat = WrongCat();
		cat.makeSound();
	}
	std::cout << "-------- Delete ---------" << std::endl;
	delete wrongAnimal;
	delete wrongCat; // Not a virtual destructor
	return 0;
}
