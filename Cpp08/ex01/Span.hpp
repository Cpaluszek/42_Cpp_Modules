/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:12:24 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/06 13:22:17 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

class Span {
public:
	~Span();
	Span(unsigned int N);
	Span(Span const & src);
	Span & operator=(Span const & src);

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	class TooManyNumbers : std::exception {
	public:
		const char * what() const throw(){
			return "Too many numbers stored";
		}
	};

	class NotEnoughNumbers : std::exception {
	public:
		const char * what() const throw(){
			return "Not enough numbers in collection";
		}
	};

private:
	unsigned int _n;
	std::vector<int> _numbers;

	Span();
};

std::ostream & operator<<(std::ostream & out, Span const & src);
