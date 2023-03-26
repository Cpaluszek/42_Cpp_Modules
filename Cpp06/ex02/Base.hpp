/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:05:08 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/26 14:17:04 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Base {
public:
	virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
