/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:43:15 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 13:21:59 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap();

	ClapTrap & operator=(ClapTrap const & rhs);

	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void 	beRepaired(int amount);

	std::string 	getName() const;
	unsigned int	getAttackDamage() const;
	void 			setAttackDamage(unsigned int value);

protected:
	std::string		_name;
	int				_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};
