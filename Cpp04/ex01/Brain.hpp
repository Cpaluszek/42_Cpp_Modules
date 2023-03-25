/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:42:59 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/25 10:09:22 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define BRAIN_SIZE 100

class Brain {
public:
	Brain();
	Brain(const Brain & src);
	~Brain();

	Brain & operator=(const Brain & rhs);

	std::string ideas[BRAIN_SIZE];
};
