/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:42:20 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 11:23:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false),
	_requiredSignGrade(150), _requiredExecGrade(150) {
}

Form::Form(const Form &src) : _name(src.getName()), _signed(src.getSigned()),
	_requiredSignGrade(src.getRequiredSignGrade()), _requiredExecGrade(src.getRequiredExecGrade())
{
}

Form::~Form() {
}

Form Form::operator=(const Form &src) {
	if (this != &src) {
		this->_signed = src.getSigned();
	}
	return *this;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute):
	_name(name), _signed(false), _requiredSignGrade(gradeToSign), _requiredExecGrade(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getRequiredSignGrade() const {
	return this->_requiredSignGrade;
}

int Form::getRequiredExecGrade() const {
	return this->_requiredExecGrade;
}

bool Form::getSigned() const {
	return this->_signed;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->getRequiredSignGrade()) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form &src) {
	out << src.getName() << "[" << src.getSigned() << "]" << std::endl;
	out << "\t - required sign grade: " << src.getRequiredSignGrade() << std::endl;
	out << "\t - required execution grade: " << src.getRequiredExecGrade() << std::endl;
	return out;
}
