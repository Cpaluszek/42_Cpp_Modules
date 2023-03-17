/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 13:28:57 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("clap");
	ScavTrap scav("scav");

	clap.setAttackDamage(2);
	scav.setAttackDamage(1);
	
	std::cout << "----------------------------------------" << std::endl;
	scav.guardGate();
	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i < 2; i++) {
		clap.attack(scav.getName());
		scav.takeDamage(clap.getAttackDamage());
		scav.attack(clap.getName());
		clap.takeDamage(scav.getAttackDamage());
	}
	std::cout << "----------------------------------------" << std::endl;
	clap.takeDamage(1);
	scav.takeDamage(1);
	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i < 10; i++) {
		clap.beRepaired(2);
		scav.beRepaired(2);
	}
	std::cout << "----------------------------------------" << std::endl;
	return 0;
}


