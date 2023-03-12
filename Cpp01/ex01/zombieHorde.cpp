/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:44:34 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 16:52:52 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	if (N < 1) {
		std::cerr << "Zombie amount must be greater than 1" << std::endl;
		return NULL;
	}
	Zombie *zombie = new Zombie[N];
	for (int i = 0 ; i < N; i++)
		zombie[i].setName(name);
	return zombie;
}
