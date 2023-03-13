/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:03:28 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/13 14:55:56 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB {
public:
	HumanB(const std::string &name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon &weapon);

private:
	Weapon *_weapon;
	std::string _name;
};
