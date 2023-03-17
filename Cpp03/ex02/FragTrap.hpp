/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:32:02 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 13:33:23 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string & name);
	~FragTrap();

	FragTrap & operator=(const FragTrap & rhs);

	void HighFiveGuys();
};
