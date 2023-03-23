/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:57 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 10:32:15 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat {
public:
	/* Constructors and destructor */
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & rhs);

	Bureaucrat(std::string const & name, int const & grade);

	std::string getName() const;
	int 		getGrade() const;

	void 		incrementGrade();
	void 		decrementGrade();

	/* Exception Classes */
class GradeTooHighException: public std::exception {
public:
	const char * what() const throw();
};
class GradeTooLowException: public std::exception {
	public:
		const char * what() const throw();
	};

private:
	const std::string	_name;
	int 				_grade;

	Bureaucrat();
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & src);