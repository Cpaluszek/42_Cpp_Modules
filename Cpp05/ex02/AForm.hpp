/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:42:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 11:23:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(AForm const & src);
	~AForm();
	AForm & operator=(AForm const & src);

	AForm(std::string const & name, int const & gradeToSign, int const & gradeToExecute);

	std::string getName() const;
	int 		getRequiredSignGrade() const;
	int 		getRequiredExecGrade() const;
	bool 		getSigned() const;

	void			beSigned(const Bureaucrat& bur);
	virtual void	execute(Bureaucrat const & executor) const = 0;

private:
	const std::string	_name;
	bool 				_signed;
	const int 			_requiredSignGrade;
	const int 			_requiredExecGrade;

	AForm();
};

std::ostream & operator<<(std::ostream & out, AForm & src);
