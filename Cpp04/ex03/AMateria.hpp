/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:20:11 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 11:50:15 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;

public:
	AMateria(std::string const & type);
	AMateria();
	virtual ~AMateria();
	AMateria(AMateria const & src);
	AMateria & operator=(AMateria const & rhs);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
