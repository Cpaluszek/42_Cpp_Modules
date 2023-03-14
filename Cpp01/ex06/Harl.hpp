/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:55:44 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/14 17:39:30 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#define LEVELS_SIZE 4

class Harl {
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	std::string _levels[LEVELS_SIZE];
	void (Harl::*_functPtrs[LEVELS_SIZE])();

	void debug();
	void info();
	void warning();
	void error();
};
