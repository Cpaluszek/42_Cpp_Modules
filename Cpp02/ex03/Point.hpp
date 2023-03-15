/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:53:55 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 14:03:43 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(float const &x, float const &y);
	Point(const Point &src);
	~Point();

	Point & operator=(Point const & rhs);

	Fixed	getX() const;
	Fixed	getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};

std::ostream & operator<<(std::ostream & out, const Point & point);
