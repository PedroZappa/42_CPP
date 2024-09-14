/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:30:52 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 17:43:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

/// @brief Constructor
Contact::Contact(void) {}

/// @brief Destructor
Contact::~Contact(void) {}

/// @brief Copy Constructor
Contact::Contact(std::string& fN, std::string& lN,
	std::string& nN, std::string& pN, std::string& dS)
{
	this->_firstName = fN;
	this->_lastName = lN;
	this->_nickName = nN;
	this->_phoneNumber = pN;
	this->_darkestSecret = dS;
}
