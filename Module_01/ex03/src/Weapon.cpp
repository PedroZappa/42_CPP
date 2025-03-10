/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:30:27 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 16:40:13 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

/**
 * @brief Construct a new Weapon object.
 * 
 * Initializes the weapon with the specified type. If the provided type
 * is an empty string, it defaults to "undefined".
 * 
 * @param type The type of the weapon.
 */
Weapon::Weapon(std::string type) : _type(type) {
	if (type.c_str()[0] == '\0')
		type = "undefined";
}

/**
 * @brief Destroy the Weapon object.
 * 
 * This destructor is responsible for cleaning up any resources
 * used by the Weapon object before it is destroyed.
 */
Weapon::~Weapon(void) {
}

/**
 * @brief Set the type of the weapon.
 * 
 * Updates the weapon's type to the specified new type.
 * 
 * @param newType The new type to set for the weapon.
 */
void Weapon::setType(std::string newType) {
	_type = newType;
}

/**
 * @brief Get the type of the weapon.
 * 
 * Retrieves the current type of the weapon.
 * 
 * @return const std::string& The current type of the weapon.
 */
const std::string &Weapon::getType(void) const {
	return (_type);
}
