/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:23:38 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/09 12:15:15 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

#define GROUP_SIZE 2

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const & src);

	PmergeMe & operator=(PmergeMe const & src);

	void addNumber(int n);

	std::vector<int> & getVector();
	std::deque<int> & getDeque();
	size_t getSize() const;

	static void insertionSort(std::vector<int> & vec);
	static void insertionSort(std::deque<int> & deque);
	static void merge(std::vector<int> & leftVector, std::vector<int> & rightVector, std::vector<int> & dst);
	static void merge(std::deque<int> & leftDeque, std::deque<int> & rightDeque, std::deque<int> & dst);
	void mergeInsertSort(std::vector<int> & vec);
	void mergeInsertSort(std::deque<int> & deque);

private:
	std::vector<int> _vec;
	std::deque<int> _deque;
};

std::ostream & operator<<(std::ostream & out, PmergeMe & src);
