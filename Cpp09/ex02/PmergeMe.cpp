/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:23:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/10 12:16:39 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() :_groupSize(0){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deque(src._deque), _groupSize(src._groupSize){}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	_vec = src._vec;
	_deque = src._deque;
	_groupSize = src._groupSize;
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

std::vector<int> & PmergeMe::getVector() {
	return this->_vec;
}

size_t PmergeMe::getSize() const {
	return this->_vec.size();
}

std::deque<int> & PmergeMe::getDeque() {
	return this->_deque;
}

void PmergeMe::insertionSort(std::vector<int> &vec) {
	int current;
	for(size_t i = 1; i < vec.size(); i++) {
		current = vec[i];
		int j = static_cast<int>(i) - 1;
		while(j >= 0 && vec[j] > current) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = current;
	}
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec) {
	if (vec.size() <= 1)
		return;
	std::vector<int> leftSide(vec.size() / 2);
	std::vector<int> rightSide(vec.size() - (vec.size() / 2));
	if (this->_groupSize == 0) {
		this->_groupSize = vec.size() / 100 + 2;
	}
	if (vec.size() <= this->_groupSize) {
		insertionSort(vec);
		return ;
	}
	size_t j = 0;
	for (size_t i = 0; i < vec.size(); i++) {
		i < vec.size() / 2 ? leftSide[i] = vec[i] : rightSide[j++] = vec[i];
	}
	mergeInsertSort(leftSide);
	mergeInsertSort(rightSide);
	merge(leftSide, rightSide, vec);
}

void PmergeMe::merge(std::vector<int> &leftVector, std::vector<int> &rightVector, std::vector<int> &dst) {
	int i = 0, left = 0, right = 0;
	while(left < (int)(dst.size() / 2)  && right < (int)(dst.size() - (dst.size() / 2))) {
		leftVector[left] < rightVector[right] ? dst[i] = leftVector[left++] : dst[i] = rightVector[right++];
		i++;
	}
	while(left < (int)dst.size() / 2) {
		dst[i++] = leftVector[left++];
	}
	while(right < (int)(dst.size() - (dst.size() / 2))) {
		dst[i++] = rightVector[right++];
	}
}

void PmergeMe::insertionSort(std::deque<int> &deque) {
	int current;
	for(size_t i = 1; i < deque.size(); i++) {
		current = deque[i];
		int j = static_cast<int>(i) - 1;
		while(j >= 0 && deque[j] > current) {
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = current;
	}
}

void PmergeMe::mergeInsertSort(std::deque<int> &deque) {
	if (deque.size() <= 1)
		return;
	std::deque<int> leftSide(deque.size() / 2);
	std::deque<int> rightSide(deque.size() - (deque.size() / 2));
	if (deque.size() <= GROUP_SIZE) {
		insertionSort(deque);
		return ;
	}
	size_t j = 0;
	for (size_t i = 0; i < deque.size(); i++) {
		i < deque.size() / 2 ? leftSide[i] = deque[i] : rightSide[j++] = deque[i];
	}
	mergeInsertSort(leftSide);
	mergeInsertSort(rightSide);
	merge(leftSide, rightSide, deque);
}

void PmergeMe::merge(std::deque<int> &leftDeque, std::deque<int> &rightDeque, std::deque<int> &dst) {
	int i = 0, left = 0, right = 0;
	while(left < (int)(dst.size() / 2)  && right < (int)(dst.size() - (dst.size() / 2))) {
		leftDeque[left] < rightDeque[right] ? dst[i] = leftDeque[left++] : dst[i] = rightDeque[right++];
		i++;
	}
	while(left < (int)dst.size() / 2) {
		dst[i++] = leftDeque[left++];
	}
	while(right < (int)(dst.size() - (dst.size() / 2))) {
		dst[i++] = rightDeque[right++];
	}
}

std::ostream &operator<<(std::ostream &out, PmergeMe &src) {
	std::vector<int>::iterator it;
	std::vector<int> vec = src.getVector();
	for (it = vec.begin(); it != vec.end(); it++) {
		out << *it << ' ';
		if (it >= vec.begin() + 3) {
			out << "[...]";
			break ;
		}
	}
	return out;
}
