/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:35:51 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 12:38:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) :
		AForm("RobotomyRequestForm", 72, 45),
		_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
		AForm(src), _target(src._target) {
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned()) {
		throw Exceptions::NotSignedExection();
	}
	else if (executor.getGrade() > this->getRequiredExecGrade()) {
		throw Exceptions::GradeTooLowException();
	}
	static int i;
	if (i % 2 == 0) {
		std::cout << "BZZZZZT! " << this->_target << " has been robotomized!" << std::endl;
	}
	else {
		std::cout << "Robotomy failed! " << this->_target << " is still alive." << std::endl;
	}
	i++;
}
