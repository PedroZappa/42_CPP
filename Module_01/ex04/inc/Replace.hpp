/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:20:01 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 20:53:18 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "../inc/Ansi.h" // Ansi colors baby!
#include <cstdlib>       // EXIT_FAILURE
#include <exception>     // std::exception
#include <fstream>       // std::ifstream, std::ofstream
#include <iostream>      // std::cout, std::cerr
#include <stdexcept>     // std::invalid_argument

#define WIDTH 42

void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sepColor,
				   const char *color);
void sepPrinter(int inWidth, char sepChar, const char* color, int nLines);

#endif
