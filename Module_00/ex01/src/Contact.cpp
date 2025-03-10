/**
 * @defgroup ContactModule Contact Management Module
 * @{
 *
 * This module provides functionalities for managing contact information,
 * including initialization, storage, and retrieval of contact details such as
 * first name, last name, nickname, phone number, and darkest secret.
 *
 * @version 1.0
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:30:52 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 19:13:41 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

/// @brief Constructs a Contact object with specified details
/// @param fN First name of the contact
/// @param lN Last name of the contact
/// @param nN Nickname of the contact
/// @param pN Phone number of the contact
/// @param dS Darkest secret of the contact
Contact::Contact(std::string fN, std::string lN, std::string nN, std::string pN,
                 std::string dS) {
  this->_firstName = fN;
  this->_lastName = lN;
  this->_nickName = nN;
  this->_phoneNumber = pN;
  this->_darkestSecret = dS;
}

/// @brief Prints the contact information to the console
void Contact::printContact(void) {
  std::cout << std::endl;
  std::cout << "\tContact Info\t" << std::endl;
  std::cout << std::endl;
  std::cout << "\tFirst Name\t: " << this->_firstName << std::endl;
  std::cout << "\tLast Name\t: " << this->_lastName << std::endl;
  std::cout << "\tNickname\t: " << this->_nickName << std::endl;
  std::cout << "\tPhone Number\t: " << this->_phoneNumber << std::endl;
  std::cout << "\tDarkest Secret\t: " << this->_darkestSecret << std::endl;
  std::cout << std::endl;
}

/// @brief Retrieves the first name of the contact
/// @return The first name as a string
std::string Contact::getFirstName(void) { return (this->_firstName); }
/// @brief Retrieves the last name of the contact
/// @return The last name as a string
std::string Contact::getLastName(void) { return (this->_lastName); }
/// @brief Retrieves the nickname of the contact
/// @return The nickname as a string
std::string Contact::getNickName(void) { return (this->_nickName); }

/** @} */
