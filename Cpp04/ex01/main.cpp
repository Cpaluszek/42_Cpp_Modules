/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:10:04 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 10:09:18 by cpalusze         ###   ########.fr       */
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
			animals[i] = new Cat;
		}
	}
	for (int i = 0; i < 100; i++) {
		delete animals[i];
	}
	return 0;
}
