/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:20:06 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 15:20:06 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
/* CalcTriArea() -
 * Find the area of a triangle. This function uses the 1/2 determinant
 * method. Given three points (x1, y1), (x2, y2), (x3, y3):
 *             | x1 y1 1 |
 * Area = .5 * | x2 y2 1 |
 *             | x3 y3 1 |
 */
Fixed getTriangleArea(Point const& a, Point const& b, Point const& c) {
	Fixed area;

	area = (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
	if (area < Fixed(0))
		area = area * -1.0f;
	return area / 2.0f;
}

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point) {
	Fixed triangleArea = getTriangleArea(a, b, c);
	Fixed area1 = getTriangleArea(point, b, c);
	Fixed area2 = getTriangleArea(point, a, c);
	Fixed area3 = getTriangleArea(point, a, b);
	Fixed areaSum = area1 + area2 + area3;
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	return ((area1 + area2 + area3) <= triangleArea);
}