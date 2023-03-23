/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:42:42 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 12:42:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) :
		AForm("RobotomyRequestForm", 25, 5),
		_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
		AForm(src), _target(src._target) {
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned()) {
		throw Exceptions::NotSignedExection();
	}
	else if (executor.getGrade() > this->getRequiredExecGrade()) {
		throw Exceptions::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
