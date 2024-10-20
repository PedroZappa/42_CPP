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
 * @brief Construct a new Weapon:: Weapon object
 * @param type the type of the weapon
 * */
Weapon::Weapon(std::string type) : _type(type)
{
}

/**
 * @brief Destroy the Weapon:: Weapon object
 * */
Weapon::~Weapon(void)
{
}

/** 
 * @brief Sets the type of the weapon
 * @param newType the new type of the weapon
 * */
void Weapon::setType(std::string newType)
{
	_type = newType;
}

/** 
 * @brief Gets a reference to the type of the weapon
 * @return std::string& a reference to the type of the weapon
 * */
const std::string &Weapon::getType(void) const
{
	return (_type);
}
