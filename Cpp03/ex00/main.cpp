/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:13 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 15:20:30 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);

int main() {
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);

	Point point1(0.5f, 0.5f);
	Point point2(1.0f, 0.0f);

	if (bsp(a, b, c, point1))
		std::cout << point1 << " is inside the triangle" << std::endl;
	else
		std::cout << point1 << " is outside of the triangle" << std::endl;

	if (bsp(a, b, c, point2))
		std::cout << point2 << " is inside the triangle" << std::endl;
	else
		std::cout << point2 << " is outside of the triangle" << std::endl;
	return 0;
}


