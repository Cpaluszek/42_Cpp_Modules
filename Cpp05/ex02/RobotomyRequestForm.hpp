/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:35:41 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/22 12:45:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string & target);
	RobotomyRequestForm(const RobotomyRequestForm & src);

	void execute(Bureaucrat const & executor) const;

private:
	const std::string	_target;
	RobotomyRequestForm();
};
