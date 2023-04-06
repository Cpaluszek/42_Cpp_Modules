/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:31:50 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/06 10:53:38 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
//	int array[] = { 1, 2, 3, 4, 5, 6};
	std::vector<int> list;
	for (int i = 0; i < 10; i++) {
		list.push_back(i);
	}
	std::vector<int>::iterator search = easyfind(list, 50);
	std::cout << *search << std::endl;


	search = easyfind(list, 5);
	std::cout << *search << std::endl;
}