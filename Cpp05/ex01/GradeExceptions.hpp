/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeExceptions.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:57:05 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 10:57:05 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

class GradeTooHighException : public std::exception {
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
