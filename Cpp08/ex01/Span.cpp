/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:12:38 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/06 13:33:44 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _n(0) {}

Span::~Span() {}

Span::Span(unsigned int N) : _n(N) {}

Span::Span(const Span &src) : _n(src._n), _numbers(src._numbers) {}

Span &Span::operator=(const Span &src) {
	this->_n = src._n;
	this->_numbers = src._numbers;
	return *this;
}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_n) {
		throw Span::TooManyNumbers();
	}
	this->_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (this->_numbers.size() < 2) {
		throw Span::NotEnoughNumbers();
	}
	std::vector<int> temp = this->_numbers;
	std::sort(temp.begin(), temp.end());
	unsigned int min = *temp.begin() - *temp.end();
	for (unsigned int i = 0; i < temp.size() - 1 ; i++) {
		if (std::abs(temp[i] - temp[i + 1]) < min) {
			min = std::abs(temp[i] - temp[i + 1]);
		}
	}
	return min;
}

int Span::longestSpan() const {
	if (this->_numbers.size() < 2) {
		throw Span::NotEnoughNumbers();
	}
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	return max - min;
}
