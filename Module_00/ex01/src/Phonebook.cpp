/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:13:52 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 16:31:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

/// @brief Constructor
PhoneBook::PhoneBook(void) { this->_n= -1; }

/// @brief Destructor
PhoneBook::~PhoneBook(void) {}

/// @brief Add a Contact to the PhoneBook
void PhoneBook::add(void)
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	std::cout << "First Name\t: ";
	std::getline(std::cin, firstName, '\n');
	std::cout << "Last Name\t: ";
	std::getline(std::cin, lastName, '\n');
	std::cout << "Nickname\t: ";
	std::getline(std::cin, nickName, '\n');
	std::cout << "Phone Number\t: ";
	std::getline(std::cin, phoneNumber, '\n');
	std::cout << "Darkest Secret\t: ";
	std::getline(std::cin, darkestSecret, '\n');

	if (firstName.empty() || lastName.empty() || nickName.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << BRED << "A Contact cannot have empty fields" << NC << std::endl;
		return ;
	}
	if (!_isPrintable(firstName) || !_isPrintable(lastName)
		|| !_isPrintable(nickName) || !_isPrintable(phoneNumber)
		|| !_isPrintable(darkestSecret))
	{
		std::cout << BRED << "Gotcha!! A Contact cannot contain non printable characters" << NC << std::endl;
		return ;
	}

	this->_contacts[this->_n++ % MAX_CONTACTS] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	std::cout << std::endl << BGRN << "\tContact added successfully" << NC << std::endl;
}

bool PhoneBook::_isPrintable(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isprint(str[i]))
			return (false);
	return (true);
}

void PhoneBook::search(void)
{
	return;
}

/// @brief Print Menu
void PhoneBook::printMenu(void)
{
	std::cout << BGRN << HEADER << NC << std::endl;
	std::cout << "Available Actions yo:";
	std::cout << HYEL"\t" << ARROW << "ADD" << std::endl;
	std::cout << HYEL"\t" << ARROW << "SEARCH" << std::endl;
	std::cout << HYEL"\t" << ARROW << "ESCAPE!!" << std::endl;
	std::cout << NC << std::endl;
}

/// @brief Print Error
void PhoneBook::printErr(std::string msg)
{
	std::cout << BRED << "Error: " << BYEL << msg << NC << std::endl;
}

/// @brief Get Prompt
void PhoneBook::_prompt(std::string prompt)
{
	std::cout << ARROW << prompt << std::endl;
};

