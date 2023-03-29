/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:41:52 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/29 10:42:42 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

template <typename T>
void iter(T* array, size_t len, void f(const T& item)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}
