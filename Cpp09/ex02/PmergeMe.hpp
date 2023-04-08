/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:23:38 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/08 12:11:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const & src);

	PmergeMe & operator=(PmergeMe const & src);

	void addNumber(int n);
	bool isSorted() const;

	std::vector<int> getVector() const;

private:
	std::vector<int> _vec;
	std::deque<int> _deque;
};

std::ostream & operator<<(std::ostream & out, const PmergeMe & src);
