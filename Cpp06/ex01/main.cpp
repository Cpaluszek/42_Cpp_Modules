/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:53:36 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/26 14:02:17 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <inttypes.h>

int main() {
	Data data;

	data.a = 42;
	data.b = 1.23f;
	data.c = 'X';

	std::cout << data.a << "-" << data.b << "-" << data.c << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);
	Data *dataSerialized = Serializer::deserialize(ptr);

	std::cout << dataSerialized->a << "-" << dataSerialized->b << "-" << dataSerialized->c << std::endl;
	return 0;
}
