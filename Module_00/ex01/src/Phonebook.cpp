/**
 * @defgroup PhoneBookModule PhoneBook Management Module
 * @{
 *
 * This module provides functionalities for managing a phonebook, including adding, searching, and displaying contacts. It ensures that all contact information is valid and formatted correctly before storage.
 *
 * @version 1.0
 */
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

/// @brief Constructs a PhoneBook object initializing the contact count to zero
PhoneBook::PhoneBook(void) { this->_n = 0; }

/// @brief Destructor for the PhoneBook object
PhoneBook::~PhoneBook(void) {}

/// @brief Adds a new contact to the phonebook after validating input
void PhoneBook::add(void) {
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

  if (firstName.size() < 1 || lastName.size() < 1 || nickName.size() < 1 ||
      phoneNumber.size() < 1 || darkestSecret.size() < 1) {
    std::cout << BRED << "\tA Contact cannot have empty fields" << NC
              << std::endl;
    return;
  }
  if (!_isPrintable(firstName) || !_isPrintable(lastName) ||
      !_isPrintable(nickName) || !_isPrintable(phoneNumber) ||
      !_isPrintable(darkestSecret)) {
    std::cout << BRED
              << "\tGotcha!! A Contact cannot contain non printable characters"
              << NC << std::endl;
    return;
  }

  this->_contacts[this->_n++ % MAX_CONTACTS] =
      Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
  std::cout << std::endl
            << BGRN << "\tContact added successfully" << NC << std::endl;
}

/// @brief Searches for a contact in the phonebook and displays the contact details
void PhoneBook::search(void) {
  int id, max;

  // Get largest supported index
  max = this->_n % MAX_CONTACTS;
  this->_printPhoneBook();
  std::cout << "SELECT ID : ";
  std::cin >> id;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail()) {
    std::cout << "\n\tInvalid Input!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } else if ((id < 0) || (id > max))
    std::cout << "\n"
              << BRED << id << " : Is not a valid ID!" << NC << std::endl;
  else
    this->_contacts[id].printContact();
}

/// @brief Prints the menu options for the phonebook application
void PhoneBook::printMenu(void) {
  std::cout << HEADER << BGRN << NC << std::endl;
  std::cout << "Available Actions yo:" << std::endl;
  std::cout << ARROW << HYEL << "Add" << NC << " to me..." << std::endl;
  std::cout << ARROW << HYEL << "Search" << NC << " me..." << std::endl;
  std::cout << ARROW << HYEL << "Exit" << NC << " me!!" << std::endl;
  std::cout << NC << std::endl;
  prompt("Enter a command : ");
}

/// @brief Prints an error message to the console
/// @param msg The error message to be displayed
void PhoneBook::printErr(std::string msg) {
  std::cout << BRED << "Error: " << BYEL << msg << NC << std::endl;
}

/// @brief Prompts the user with a message
/// @param prompt The message to prompt the user with
void PhoneBook::prompt(std::string prompt) { std::cout << ARROW << prompt; };

/// @brief Formats a string to fit within a specified width
/// @param str The string to be formatted
/// @return The formatted string
std::string PhoneBook::formatString(std::string str) {
  if (str.length() > 10)
    return (str.substr(0, 9) + ".");
  return (str);
}

/// @brief Checks if a string contains only printable characters
/// @param str The string to be checked
/// @return True if the string is printable, false otherwise
bool PhoneBook::_isPrintable(std::string str) {
  for (size_t i = 0; i < str.length(); i++)
    if (!std::isprint(str[i]))
      return (false);
  return (true);
}

/// @brief Prints the list of contacts in the phonebook
void PhoneBook::_printPhoneBook(void) {
  std::string field;

  std::cout << std::endl;
  std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
  for (int i = 0; i <= (MAX_CONTACTS - 1); i++) {
    std::cout << "|" << std::setw(10) << i << "|";
    field = this->_contacts[i].getFirstName();
    std::cout << std::setw(10) << PhoneBook::formatString(field) << "|";
    field = this->_contacts[i].getLastName();
    std::cout << std::setw(10) << PhoneBook::formatString(field) << "|";
    field = this->_contacts[i].getNickName();
    std::cout << std::setw(10) << PhoneBook::formatString(field) << "|"
              << std::endl;
  }
}

/** @} */

