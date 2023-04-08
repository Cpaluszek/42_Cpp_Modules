/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:23:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/08 12:17:32 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deque(src._deque){}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	_vec = src._vec;
	_deque = src._deque;
	return *this;
}

void PmergeMe::addNumber(int n) {
	if (std::find(this->_vec.begin(), this->_vec.end(), n) != this->_vec.end()) {
		std::ostringstream oss;
		oss << n;
		throw std::invalid_argument(std::string("Error: duplicate number: ") + oss.str());
	}
	this->_vec.push_back(n);
	this->_deque.push_back(n);
}

std::vector<int> PmergeMe::getVector() const {
	return this->_vec;
}

bool PmergeMe::isSorted() const {
	std::vector<int>::const_iterator it;
	for (it = this->_vec.begin(); it != this->_vec.end() - 1; it++) {
		if (*it > *(it + 1)) {
			return false;
		}
	}
	return true;
}

std::ostream &operator<<(std::ostream &out, const PmergeMe &src) {
	std::vector<int>::const_iterator it;
	std::vector<int> vec = src.getVector();
	for (it = vec.begin(); it != vec.end(); it++) {
		out << *it << ' ';
		if (it >= vec.begin() + 4) {
			out << "[...]";
			break ;
		}
	}
	return out;
}
