/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/18 10:04:01 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap scav("scav");
	FragTrap frag("frag");

	frag.setAttackDamage(2);
	scav.setAttackDamage(1);
	std::cout << "----------------------------------------" << std::endl;
	frag.HighFiveGuys();
	scav.guardGate();
	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i < 2; i++) {
		frag.attack(scav.getName());
		scav.takeDamage(frag.getAttackDamage());
		scav.attack(frag.getName());
		frag.takeDamage(scav.getAttackDamage());
	}
	std::cout << "----------------------------------------" << std::endl;
	frag.takeDamage(1);
	scav.takeDamage(1);
	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i < 10; i++) {
		frag.beRepaired(2);
		scav.beRepaired(2);
	}
	std::cout << "----------------------------------------" << std::endl;
	return 0;
}


