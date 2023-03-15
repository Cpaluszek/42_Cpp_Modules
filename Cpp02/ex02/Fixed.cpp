/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:57 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 13:48:58 by cpalusze         ###   ########.fr       */
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

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(n * (1 << Fixed::_fractionalBits)));
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	return a.getRawBits() > b.getRawBits() ? a : b;
}

// --- Operators

bool Fixed::operator>(const Fixed &rhs) const {
	return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->_value != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
	++(this->_value);
	return *this;
}

// Should return a copy of the object before incrementation
Fixed Fixed::operator++(int) {
	Fixed inc(*this);
	(this->_value)++;
	return inc;
}

Fixed &Fixed::operator--() {
	--this->_value;
	return *this;
}

// Should return a copy of the object before incrementation
Fixed Fixed::operator--(int) {
	Fixed dec(*this);
	this->_value--;
	return dec;
}

std::ostream &operator<<(std::ostream & out, const Fixed &fixed) {
	std::cout << fixed.toFloat();
	return out;
}
