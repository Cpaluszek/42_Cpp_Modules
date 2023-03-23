/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:14:22 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/23 10:14:22 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

class Exceptions {
public:
	class GradeTooHighException : public std::exception {
	public:
		const char * what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char * what() const throw();
	};
};

