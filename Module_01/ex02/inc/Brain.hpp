/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:01:30 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 11:38:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Ansi.h"
#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout
#include <string>   // std::string

#define WIDTH 42

/* UI Printing Functions : printer.cpp */
void headerPrinter(const std::string &headerText, int width);
void sepPrinter(int inWidth);

#endif
