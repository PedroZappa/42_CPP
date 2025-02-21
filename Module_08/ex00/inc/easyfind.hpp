/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:57:08 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 09:11:44 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "../inc/Ansi.h"
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>

// Template Declaration
template <typename T> typename T::value_type easyfind(T &container, int n);

// Exception Declaration & Definition
class NotFound : public std::exception {
  public:
	virtual const char *what() const throw();
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

// Include easyfind.tpp
#include "easyfind.tpp"

#endif
