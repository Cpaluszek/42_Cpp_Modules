/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:41:22 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 13:21:19 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character();
	~Character();
	Character(std::string name);
	Character(Character const & src);
	Character & operator=(Character const & rhs);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


private:
	AMateria *_inventory[4];
	std::string _name;
	static std::vector<AMateria*> _trash;
	static void clearTrash();
};
