/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:06:12 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/26 14:16:41 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"


Base * generate() {
	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base * p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void	identify( Base& p )
{
	Base result;

	try
	{
		result = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) { }
	try
	{
		result = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (...) { }
	try
	{
		result = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) { }
}

int main() {
	srand(time(NULL));

	try {
		Base * generated = generate();
		if (generated == NULL)
			return 1;
		identify(generated);
		identify(*generated);

		delete generated;
	}
	catch (std::bad_alloc & e) {
		std::cout << "Failed to allocate memory: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}