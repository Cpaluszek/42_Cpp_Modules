/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:42:20 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 11:23:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false),
			   _requiredSignGrade(150), _requiredExecGrade(150) {
}

AForm::AForm(const AForm &src) : _name(src.getName()), _signed(src.getSigned()),
								_requiredSignGrade(src.getRequiredSignGrade()), _requiredExecGrade(src.getRequiredExecGrade())
{
}

AForm::~AForm() {
}

AForm & AForm::operator=(const AForm &src) {
	if (this != &src) {
		this->_signed = src.getSigned();
	}
	return *this;
}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute):
	_name(name), _signed(false), _requiredSignGrade(gradeToSign), _requiredExecGrade(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

std::string AForm::getName() const {
	return this->_name;
}

int AForm::getRequiredSignGrade() const {
	return this->_requiredSignGrade;
}

int AForm::getRequiredExecGrade() const {
	return this->_requiredExecGrade;
}

bool AForm::getSigned() const {
	return this->_signed;
}

void AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->getRequiredSignGrade()) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm &src) {
	out << src.getName() << "[" << src.getSigned() << "]" << std::endl;
	out << "\t - required sign grade: " << src.getRequiredSignGrade() << std::endl;
	out << "\t - required execution grade: " << src.getRequiredExecGrade() << std::endl;
	return out;
}
