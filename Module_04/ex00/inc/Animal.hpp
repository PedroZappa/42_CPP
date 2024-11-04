/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:38:21 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 18:28:20 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "ansi.h"
#include <cstdlib> // EXIT_SUCCESS
#include <iostream>
#include <limits>
#include <string>

class Animal {
  public:
	Animal(void);
	Animal(const Animal &copy);
	virtual ~Animal(void);

	Animal &operator=(const Animal &copy);

	std::string getType() const;
	
	void setType(const std::string &type);

	virtual void makeSound() const;

  protected:
	std::string _type;
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
