/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:03:41 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/13 13:08:20 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
public:
	Weapon(const std::string &type);
	~Weapon();
	const std::string& getType() const;
	void setType(const std::string &newType);

private:
	std::string _type;
};
