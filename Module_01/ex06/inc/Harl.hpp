/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:13 by passunca          #+#    #+#             */
/*   Updated: 2024/10/22 14:41:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include "../inc/Ansi.h"
#include <iostream> // std::cout
#include <string>   // std::string

enum err_code
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

#define WIDTH 42

class Harl
{
  public:
	Harl();
	~Harl();

	void complain(std::string level);

  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

// UI Printer
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
