/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:05:57 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 10:27:08 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#define MIN_GRADE 1
#define MAX_GRADE 150

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
	const char * what() const throw() {
		return "Grade too high";
	}
};
class GradeTooLowException: public std::exception {
	public:
		const char * what() const throw() {
			return "Grade too low";
		}
	};

private:
	const std::string	_name;
	int 				_grade;

	Bureaucrat();
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & src);