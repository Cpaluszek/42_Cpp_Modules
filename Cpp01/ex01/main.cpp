/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:35:50 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 16:46:57 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main() {
	Zombie zombie("Basic zombie");
	zombie.announce();

	Zombie* zombies = zombieHorde(5, "Horde");
	if (zombies == NULL) {
		std::cerr << "Failed to allocate zombie" << std::endl;
		return 1;
	}
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
