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

/// @brief Constructor
Contact::Contact(void) {}

/// @brief Destructor
Contact::~Contact(void) {}

/// @brief Contact initializer
Contact::Contact(std::string fN, std::string lN,
	std::string nN, std::string pN, std::string dS)
{
	this->_firstName = fN;
	this->_lastName = lN;
	this->_nickName = nN;
	this->_phoneNumber = pN;
	this->_darkestSecret = dS;
}

std::string Contact::getFirstName(void) { return (this->_firstName); }
std::string Contact::getLastName(void) { return (this->_lastName); }
std::string Contact::getNickName(void) { return (this->_nickName); }
