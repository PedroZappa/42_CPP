/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:38:21 by passunca          #+#    #+#             */
/*   Updated: 2024/11/04 21:00:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "ansi.h"
#include <cstdlib> // EXIT_SUCCESS
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

/** @brief AAnimal Abstract Class
 * Represents a generic Animal */
class AAnimal {
  public:
	AAnimal(void);
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal(void);

	/** @brief Copy Assignment Operator */
	AAnimal &operator=(const AAnimal &copy);

	/** @brief Getters and Setters */
	std::string getType() const;
	void setType(const std::string &type);

	/** @brief Pure Virtual Function
	 * By using a pure virtual function, the AAnimal class establishes a common
	 * interface for all derived animal classes while leaving the specific implementation
	 * of makeSound to each individual animal type. This is a key aspect of polymorphism
	 * in C++, allowing for different animal types to have their own unique sound-making
	 * behavior while still adhering to a common interface */
	virtual void makeSound() const = 0;

  protected:
	std::string _type;
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);
void clearScreen(void);

#endif
