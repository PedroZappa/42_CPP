/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:38:51 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 10:45:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/** ## Virtual Inheritance Implementation Details:
 * - The `virtual` keyword in `virtual public ClapTrap` ensures that only one
 * copy of ClapTrap's members is inherited, regardless of how many paths of
 * inheritance there are to it.
 * - This is crucial for maintaining a single, coherent state for the base
 * ClapTrap part of more complex derived classes.
 *
 * ## Potential Drawbacks:
 * - Slightly more complex implementation by the compiler.
 * - Small performance overhead due to the need for runtime resolution of
 * virtual base class subobjects.
 */
class ScavTrap : virtual public ClapTrap {
  public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	virtual ~ScavTrap();

	// Operators Overloads
	ScavTrap &operator=(const ScavTrap &rhs);

	// ScavTrap Actions
	void attack(const std::string &target);
	void guardGate(void) const;
};

#endif
