/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:19:01 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 12:19:24 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

// Todo: create an Exception class and nest sub-classes
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

class NotSignedExection: public std::exception {
public:
	const char * what() const throw() {
		return "Form is not signed";
	}
};
