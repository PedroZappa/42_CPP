/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:30:40 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 11:08:12 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "Ansi.h"
#include <iostream>

// Template Functions
template <typename T> void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T a, T b) {
	return (a < b ? a : b);
}

template <typename T> T max(T a, T b) {
	return (a > b ? a : b);
}


#endif
