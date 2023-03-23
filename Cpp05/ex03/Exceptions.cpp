/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:02:27 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/23 10:05:10 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

const char *Exceptions::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Exceptions::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *Exceptions::NotSignedExection::what() const throw() {
	return "Form is not signed";
}
