/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:29:33 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 11:48:30 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Ansi.h"
#include <iostream>
#include <string>

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

std::ostream &operator<<(std::ostream &os, const t_data &data) {
	os << "{i: " << data.i << ", str: " << data.str << "}";
	return os;
}

// Templates
template <typename T, typename F>
void iter(T *arr, size_t len, F f) {
	for (size_t i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T>
void printElement(const T &element) {
	std::cout << element << " ";
}

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

