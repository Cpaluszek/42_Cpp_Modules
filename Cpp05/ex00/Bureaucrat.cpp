/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:07:28 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 11:06:36 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) :
	_name(name), _grade(grade) {
	if (this->_grade > 150) {
		Bureaucrat::GradeTooLowException();
	}
	else if (this->_grade < 1) {
		Bureaucrat::GradeTooHighException();
	}
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
