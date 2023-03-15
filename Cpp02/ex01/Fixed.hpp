/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:40 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 11:11:25 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(Fixed const & src);
	~Fixed();
	Fixed & operator=(Fixed const & rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float 	toFloat() const;
	int 	toInt() const;

private:
	int	_value;
	static const int _fractionalBits;

//	void printBinaryRepresentation() const;
};

std::ostream & operator<<(std::ostream & out, const Fixed & fixed);