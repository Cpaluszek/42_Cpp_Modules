/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:35:50 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 16:41:25 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie zombie("Basic zombie");
	zombie.announce();
	Zombie *zombieHeap = newZombie("Heap zombie");
	if (!zombieHeap)
	{
		std::cerr << "Failed to allocate zombie" << std::endl;
		return 1;
	}
	zombieHeap->announce();
	delete zombieHeap;
	randomChump("Stack zombie");
	return 0;
}
