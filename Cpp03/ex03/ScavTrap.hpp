/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:45:01 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/18 10:19:44 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
	ScavTrap();

public:
	ScavTrap(const std::string & name);
	~ScavTrap();

	void attack(const std::string & target);

	void guardGate();
};
