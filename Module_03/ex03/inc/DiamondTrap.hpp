/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:24:12 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 10:46:57 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/** @brief DiamondTrap Class (Solving the Diamond Problem)
 * When a class inherits from two classes that have a common base class, it can
 * lead to ambiguity and duplication of the base class members. This forms a
 * diamond-shaped inheritance pattern.

		 ClapTrap
		/       \
	ScavTrap FragTrap
		\		/
		DiamondTrap
 *
 * ## Virtual Inheritance
 * By using virtual public, you're telling the compiler to create only one
 * instance of the base class (ClapTrap in this case) that will be shared by all
 * classes in the inheritance hierarchy.
 *
 * ## Benefits of Virtual Inheritance:
 * - Avoids duplication of ClapTrap members in DiamondTrap.
 * - Resolves ambiguity when accessing ClapTrap members through DiamondTrap.
 * - Ensures that there's only one instance of ClapTrap's members in the final
 * derived class (DiamondTrap).
 *
 * ## Summary:
 * Using `virtual public` inheritance here is a proactive measure to prevent the
 * diamond problem and ensure clean, unambiguous inheritance when multiple classes
 * derive from ClapTrap, especially if there's a class that combines these derived
 * classes further down the inheritance hierarchy.
 */
class DiamondTrap : public FragTrap, public ScavTrap {
  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &obj);
	~DiamondTrap();

	// Operator Overloads
	DiamondTrap &operator=(const DiamondTrap &obj);

	// Member Functions
	void attack(const std::string &target);
	void whoAmI();

  private:
	std::string _name;
};

// Insertion Operator Overload
std::ostream &operator<<(std::ostream &ofs, const DiamondTrap &rhs);

#endif
