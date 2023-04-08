/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:40:30 by cpalusze          #+#    #+#             */
/*   Updated: 2023/04/08 11:03:31 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN {
public:
	RPN();
	RPN(RPN const & src);
	~RPN();

	RPN & operator=(RPN const & src);

	void addNumber(int n);
	void checkOperator(char c);
	void performOperation(char c);
	int getTop();
	size_t getSize() const;

private:
	std::stack<int> _numbers;
};
