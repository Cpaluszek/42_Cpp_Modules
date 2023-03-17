/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 11:42:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main() {
	ClapTrap clap("clap");
	ClapTrap trap("trap");

	clap.setAttackDamage(2);
	trap.setAttackDamage(1);
	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i < 2; i++) {
		clap.attack(trap.getName());
		trap.takeDamage(clap.getAttackDamage());
		trap.attack(clap.getName());
		clap.takeDamage(trap.getAttackDamage());
	}
	std::cout << "----------------------------------------" << std::endl;
	clap.takeDamage(1);
	trap.takeDamage(1);
	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i < 10; i++) {
		clap.beRepaired(2);
		trap.beRepaired(2);
	}
	std::cout << "----------------------------------------" << std::endl;
	return 0;
}


