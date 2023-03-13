/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:03:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/13 15:02:11 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(const std::string &name, Weapon& weapon);
	~HumanA();
	void attack() const;

private:
	Weapon& _weapon;
	std::string _name;
};
