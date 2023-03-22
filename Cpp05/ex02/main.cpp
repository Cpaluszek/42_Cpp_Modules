/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:45 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 12:45:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bur("pawn", 10);

		std::cout << "---------------- Shrubbery form ----------------" << std::endl;
		ShrubberyCreationForm shrub("shrub");
		bur.signForm(shrub);
		bur.executeForm(shrub);

		std::cout << "---------------- Robotomy form ----------------" << std::endl;
		RobotomyRequestForm robot("robot");
		bur.executeForm(robot);
		bur.signForm(robot);
		bur.executeForm(robot);
		bur.executeForm(robot);

		std::cout << "---------------- Presidential form ----------------" << std::endl;
		PresidentialPardonForm pres("toto");
		bur.executeForm(pres);
		bur.signForm(pres);
		bur.executeForm(pres);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}
