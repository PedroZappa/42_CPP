/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:25:13 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 20:27:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "ansi.h"
#include <iostream>
#include <string>
#include <cstdlib> // EXIT_SUCCESS

class ClapTrap {
  public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	// virtual enables destruction of derived classes through base class pointers
	// Allows for polymorphic behaivior in the destructor call chain
	// Best practice when designing classes intended for inheritance
	// Slightly increases the size of the class due to the addition of a virtual table pointer
	// Crucial to prevent memory leaks when using the class as a base for inheritance
	virtual ~ClapTrap(void);

	// Operators Overloads
	ClapTrap &operator=(const ClapTrap &rhs);

	// clapTrap Actions
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// Getters
	std::string getName(void) const;
	std::string getType(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
	bool getStatus(std::string type) const;

  protected:
	// Protected Attributes are accessible to derived classes
	// Reduce the level of encapsulation compared to private members
	std::string _name;
	std::string _type;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

// Insertion Operator Overload
std::ostream &operator<<(std::ostream &ofs, const ClapTrap &rhs);

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
