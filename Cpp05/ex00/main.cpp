/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 10:35:43 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat pawn("pawn", 1);
		std::cout << pawn << std::endl;
		pawn.incrementGrade();
		std::cout << pawn << std::endl;
		pawn.decrementGrade();
		std::cout << pawn << std::endl;
		pawn.decrementGrade();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}
