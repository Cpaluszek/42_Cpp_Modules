/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 11:07:01 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat pawn("pawn", 2);
		std::cout << pawn << std::endl;
		pawn.incrementGrade();
		std::cout << pawn << std::endl;
		pawn.incrementGrade();
		std::cout << pawn << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}
