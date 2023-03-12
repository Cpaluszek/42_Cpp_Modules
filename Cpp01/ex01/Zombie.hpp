/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:25:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 16:25:13 by cpalusze         ###   ########.fr       */
/*                                                                            */

/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Zombie {
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void announce() const;
	void setName(const std::string &name);

private:
	std::string _name;
};
