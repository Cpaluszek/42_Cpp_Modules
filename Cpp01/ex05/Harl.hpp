/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:55:44 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/14 17:34:52 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Harl {
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	std::string _levels[4];
	void (Harl::*_functPtrs[4])();

	void debug();
	void info();
	void warning();
	void error();
};
