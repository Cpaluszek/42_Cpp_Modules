/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:23:12 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/10 12:08:47 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cerrno>
#include <stdint.h>
#include "PmergeMe.hpp"

# define END	"\033[0m"
# define RED	"\033[1;31m"

double getElapsedTime(clock_t & startTime) {
	return static_cast<double>(clock() - startTime) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
		return 1;
	}
	PmergeMe pmergeMe;
	for (int i = 1; i < argc; i++) {
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos) {
			std::cout << RED << "Error: not a positive integer" << END << std::endl;
			return 1;
		}
		long nb = strtol(argv[i], NULL, 10);
		if (errno != 0 || nb > INT32_MAX) {
			std::cout << RED << "Error: INT overflow" << END << std::endl;
			return 1;
		}
		try {
			pmergeMe.addNumber(static_cast<int>(nb));
		}
		catch (std::exception const & e) {
			std::cout << RED << e.what() << END << std::endl;
			return 1;
		}
	}

	clock_t startTime;
	double elapsedTime;

	std::cout << "Before: " << pmergeMe << std::endl;
	startTime = clock();
	pmergeMe.mergeInsertSort(pmergeMe.getVector());
	elapsedTime = getElapsedTime(startTime);
	std::cout << "After: " << pmergeMe << std::endl;
	std::cout << "Time to process a rang of " << pmergeMe.getSize()
		<< " elements with std::vector: " << elapsedTime << " us" << std::endl;

	startTime = clock();
	pmergeMe.mergeInsertSort(pmergeMe.getDeque());
	elapsedTime = getElapsedTime(startTime);
	std::cout << "Time to process a rang of " << pmergeMe.getSize()
			  << " elements with std::deque: " << elapsedTime << " us" << std::endl;
}

