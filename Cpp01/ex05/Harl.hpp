/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:55:44 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/14 13:58:20 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Harl {
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
};
