/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:36:21 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/29 10:39:06 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T & x, T & y) {
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T & min(T & x, T & y) {
	return x < y ? x : y;
}

template <typename T>
T & max(T & x, T & y) {
	return x > y ? x : y;
}
