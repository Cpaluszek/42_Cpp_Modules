/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:42:29 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 12:45:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm{
public:
	PresidentialPardonForm(const std::string & target);
	PresidentialPardonForm(const PresidentialPardonForm & src);

	void execute(Bureaucrat const & executor) const;

private:
	const std::string	_target;
	PresidentialPardonForm();
};
