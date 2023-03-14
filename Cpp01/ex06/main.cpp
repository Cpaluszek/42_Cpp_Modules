/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:55:31 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/14 17:59:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	harl.complain("DEBUG");
	std::cout << "--------------------" << std::endl;
	harl.complain("INFO");
	std::cout << "--------------------" << std::endl;
	harl.complain("WARNING");
	std::cout << "--------------------" << std::endl;
	harl.complain("ERROR");
	std::cout << "--------------------" << std::endl;
	harl.complain("NOT A COMMAND");
	return 0;
}
