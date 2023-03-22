/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 11:29:30 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bur("pawn", 42);
		Form form("Dummy form", 10, 10);
		std::cout << form << std::endl;
		bur.signForm(form);

		Form form2("Dummy form", 50, 10);
		std::cout << form2 << std::endl;
		bur.signForm(form2);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}
