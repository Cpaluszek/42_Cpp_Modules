/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:57 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 11:13:28 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = (n << Fixed::_fractionalBits);
}

// -------------------------------------
// Example: n = 42.42
// n * (1 << 8) => 42.42 * 256 = ~10860
//	-> 0b101010.01101100
//			 42.421875
// -------------------------------------
Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(n * (1 << Fixed::_fractionalBits)));
//	printBinaryRepresentation();
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(static_cast<float>(this->_value) / static_cast<float>(1 << Fixed::_fractionalBits));
}

int Fixed::toInt() const {
	return this->_value >> Fixed::_fractionalBits;
}

std::ostream &operator<<(std::ostream & out, const Fixed &fixed) {
	std::cout << fixed.toFloat();
	return out;
}

//#include <bitset>
//void Fixed::printBinaryRepresentation() const {
//	std::bitset<16> upper(this->_value >> Fixed::_fractionalBits);
//	std::bitset<8> lower(this->_value & 0xFF);
//	std::cout << "\t" << upper << "." << lower << std::endl;
//}
