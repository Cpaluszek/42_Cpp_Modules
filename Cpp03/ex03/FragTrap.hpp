/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:32:02 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/18 10:18:41 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
	FragTrap();

public:
	FragTrap(const std::string & name);
	~FragTrap();

	void attack(const std::string & target);

	void HighFiveGuys();
};
