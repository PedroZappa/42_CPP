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

#pragma once

#include "Ansi.h"
#include <iostream>

// Custom Data Type For testing
typedef struct s_data {
	int i;
	std::string str;

	bool operator<(const s_data &other) const {
		return (i < other.i) || (i == other.i && str < other.str);
	}

	bool operator>(const s_data &other) const {
		return (i > other.i) || (i == other.i && str > other.str);
	}

	s_data &operator=(const s_data &other) {
		if (this != &other) {
			i = other.i;
			str = other.str;
		}
		return *this;
	}
} t_data;

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

// Inline to avoid ODR (One Definition Rule) violations
inline std::ostream &operator<<(std::ostream &os, const t_data &data) {
	os << "{i: " << data.i << ", str: " << data.str << "}";
	return os;
}
