/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:43:48 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/08 11:11:23 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) : _numbers(src._numbers) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src) {
	this->_numbers = src._numbers;
	return *this;
}

void RPN::addNumber(int n) {
	this->_numbers.push(n);
}

size_t RPN::getSize() const {
	return this->_numbers.size();
}

void RPN::checkOperator(char c) {
	switch (c) {
		case '+':
		case '-':
		case '*':
		case '/':
			this->performOperation(c);
			break ;
		case ' ':
			break;
		default:
			throw std::invalid_argument(std::string("Error: invalid character: ") + c);
	}
}

int RPN::getTop() {
	return this->_numbers.top();
}

void RPN::performOperation(char c) {
	if (getSize() < 2) {
		throw std::out_of_range("Error: invalid operation");
	}
	int lhs = this->_numbers.top();
	this->_numbers.pop();
	int rhs = this->_numbers.top();
	this->_numbers.pop();
	switch (c) {
		case '+':
			this->_numbers.push(rhs + lhs);
			break ;
		case '-':
			this->_numbers.push(rhs - lhs);
			break ;
		case '*':
			this->_numbers.push(rhs * lhs);
			break ;
		case '/':
			if (lhs == 0) {
				throw std::runtime_error("Error: Attempted to divide by Zero");

			}
			this->_numbers.push(rhs / lhs);
			break ;
	}
}
