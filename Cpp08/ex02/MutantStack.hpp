/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:46:30 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/06 14:06:12 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {};
	MutantStack(MutantStack const & src) : std::stack<T>() {
		*this = src;
	}

	MutantStack & operator=(MutantStack const & src) {
		this->c = src.c;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};