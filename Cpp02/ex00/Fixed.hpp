/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:33:40 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/15 10:07:01 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(Fixed const & src);
	~Fixed();
	Fixed & operator=(Fixed const & rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);

private:
	int	_value;
	static const int _fractionalBits;
};
