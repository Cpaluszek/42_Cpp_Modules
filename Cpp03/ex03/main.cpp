/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/18 10:30:39 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond("toto");
	diamond.whoAmI();

	diamond.attack("nothing");
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	return 0;
}


