/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:57:19 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 15:10:34 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float &x, const float &y) :
	_x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &src) :_x(src._x), _y(src._y) {}

Point::~Point() {}

Point &Point::operator=(const Point &rhs) {
	(Fixed) this->_x = rhs.getX();
	(Fixed) this->_y = rhs.getY();
	return *this;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
	out << "[" << point.getX() << ";" << point.getY() << "]";
	return out;
}
