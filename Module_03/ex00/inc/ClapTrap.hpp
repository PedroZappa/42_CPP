/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:25:13 by passunca          #+#    #+#             */
/*   Updated: 2024/11/02 12:31:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "ansi.h"
#include <iostream>
#include <string>

class ClapTrap {
  public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap(void);

	// Operators Overloads
	ClapTrap &operator=(const ClapTrap &rhs);

	// clapTrap Actions
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// Getters
	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
	bool getStatus(void) const;
	
  private:
	std::string _name;
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
