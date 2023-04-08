/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:40:05 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/08 11:16:54 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

# define END	"\033[0m"
# define RED	"\033[1;31m"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./RPN <inverted Polish math expression>" << std::endl;
		return 1;
	}

	RPN rpn;
	std::string inputExpression(argv[1]);
	for (size_t i = 0; i < inputExpression.length(); i++) {
		if (std::isdigit(inputExpression[i])) {
			rpn.addNumber(inputExpression[i] - '0');
			continue ;
		}
		else if (inputExpression[i] == '-' && i + 1 < inputExpression.length() &&
				std::isdigit(inputExpression[i + 1])) {
			rpn.addNumber(-(inputExpression[i + 1] - '0'));
			continue;
		}
		try {
			rpn.checkOperator(inputExpression[i]);
		}
		catch (std::exception const & e) {
			std::cerr << RED << e.what() << END << std::endl;
			return 1;
		}
	}
	if (rpn.getSize() != 1){
		std::cerr << RED << "Error: invalid input" << END << std::endl;
		return (1);
	}
	std::cout << rpn.getTop() << std::endl;
	return 0;
}
