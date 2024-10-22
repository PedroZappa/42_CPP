/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:13 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 13:59:44 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include "../inc/Ansi.h"

#include <iostream> // std::cout
#include <string>   // std::string
#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE

enum e_exit
{
	FAILURE = 1,
	SUCCESS = 0
};

#define WIDTH 42

class Harl {
private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

public:
  Harl();
  ~Harl();

  void complain(std::string level);
};

// UI Printer
void headerPrinter(const std::string &headerText, int inWidth, char sep,
                   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);
#endif
