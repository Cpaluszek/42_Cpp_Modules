/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:42:59 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/20 09:46:48 by cpalusze         ###   ########.fr       */
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

private:
	std::string _ideas[BRAIN_SIZE];
};
