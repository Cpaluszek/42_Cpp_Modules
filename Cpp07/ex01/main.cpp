/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:44:15 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/29 10:47:30 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
static void printItem(T const & item) {
	std::cout << item << std::endl;
}

int main() {
	std::cout << "--------- INT ---------" << std::endl;
	int arr[5] = {2, 5, 78, 24, -12};
	iter(arr, 5, printItem);

	std::cout << "--------- STRING ---------" << std::endl;
	std::string arrStr[5] = {"2", "string", "template", "test\n", "%^*&"};
	iter(arrStr, 5, printItem);
}
