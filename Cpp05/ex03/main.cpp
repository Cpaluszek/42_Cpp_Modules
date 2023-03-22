/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 13:33:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Bureaucrat bur("pawn", 10);
		Intern randomIntern;
		AForm *form;

		form = randomIntern.makeForm("shrubbery creation", "target");
		if (form == NULL)
			return 1;

		bur.signForm(*form);
		bur.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}
