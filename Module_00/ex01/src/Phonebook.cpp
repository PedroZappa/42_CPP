/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:13:52 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 19:14:07 by passunca         ###   ########.fr       */
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
	
	// Get user input
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

	// Validate user input
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

	// Add Contact
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
	int	idx, max;

	(void)idx;
	(void)max;
	// Get largest supported index
	max = (this->_n > (MAX_CONTACTS - 1)) ? (MAX_CONTACTS - 1) : --this->_n;
	this->_printPhoneBook();
}

void PhoneBook::_printPhoneBook(void)
{
	std::string field;

	std::cout << "|\tIndex|\tFirst Name|\tLast Name|\tNickname|" << std::endl;
	for (int i = 0; i <= (MAX_CONTACTS - 1); i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		field = this->_contacts[i].getFirstName();
		std::cout << std::setw(10) << PhoneBook::formatString(field) << "|";
		field = this->_contacts[i].getLastName();
		std::cout << std::setw(10) << PhoneBook::formatString(field) << "|";
		field = this->_contacts[i].getNickName();
		std::cout << std::setw(10) << PhoneBook::formatString(field) << "|" << std::endl;
	}
}

/// @brief Print Menu
void PhoneBook::printMenu(void)
{
	std::cout << BGRN << HEADER << NC << std::endl;
	std::cout << "Available Actions yo:" << std::endl;
	std::cout << HYEL << ARROW << "ADD to me..." << std::endl;
	std::cout << HYEL << ARROW << "SEARCH me..." << std::endl;
	std::cout << HYEL << ARROW << "ESCAPE ME!!" << std::endl;
	std::cout << NC << std::endl;
	prompt("Enter a command : ");
}

/// @brief Print Error
void PhoneBook::printErr(std::string msg)
{
	std::cout << BRED << "Error: " << BYEL << msg << NC << std::endl;
}

/// @brief Get Prompt
void PhoneBook::prompt(std::string prompt)
{
	std::cout << ARROW << prompt;
};

/// @brief Format String
std::string PhoneBook::formatString(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(9) << std::right << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << str;
	return (str);
}
