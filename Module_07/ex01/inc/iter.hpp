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

#ifndef ITER_HPP
#define ITER_HPP

#include "Ansi.h"
#include <iostream>
#include <string>

// Custom Data Type For testing
typedef struct s_data {
	int i;
	std::string str;

	bool operator<(const s_data &other) const;
	bool operator>(const s_data &other) const;
	s_data &operator=(const s_data &other);
} t_data;

// Inline to avoid ODR violations
inline std::ostream &operator<<(std::ostream &os, const t_data &data);

// Templates
template <typename T, typename F>
void iter(T *arr, size_t len, F f) {
	for (size_t i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T>
void printElement(const T &element) {
	std::cout << YEL << element << NC << " ";
}

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
