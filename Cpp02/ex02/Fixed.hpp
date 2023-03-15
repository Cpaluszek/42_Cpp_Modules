/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:40 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 13:44:03 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(int n);
	Fixed(float n);
	Fixed(Fixed const & src);
	~Fixed();
	Fixed & operator=(Fixed const & rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float 	toFloat() const;
	int 	toInt() const;

	bool 	operator>(const Fixed &rhs) const;
	bool 	operator<(const Fixed &rhs) const;
	bool 	operator>=(const Fixed &rhs) const;
	bool 	operator<=(const Fixed &rhs) const;
	bool 	operator==(const Fixed &rhs) const;
	bool 	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	Fixed	& operator++();
	Fixed	operator++(int);
	Fixed	& operator--();
	Fixed	operator--(int);

	static Fixed		&min(Fixed &a, Fixed &b) ;
	static const Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed		&max(Fixed &a, Fixed &b) ;
	static const Fixed	&max(Fixed const &a, Fixed const &b);

private:
	int	_value;
	static const int _fractionalBits;
};

std::ostream & operator<<(std::ostream & out, const Fixed & fixed);