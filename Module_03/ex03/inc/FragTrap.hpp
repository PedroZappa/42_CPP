/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:04:25 by passunca          #+#    #+#             */
/*   Updated: 2024/11/03 10:47:19 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

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
class FragTrap : virtual public ClapTrap {
  public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap(void);

	// Operators Overloads
	FragTrap &operator=(const FragTrap &rhs);

	// Member Functions
	void highFivesGuys(void);
};

#endif
