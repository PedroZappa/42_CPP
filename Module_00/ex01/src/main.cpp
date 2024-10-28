/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:23:51 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 18:06:15 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

std::string toLower(std::string str);

int main(void) {
  PhoneBook phonebook = PhoneBook();
  std::string cmd;

  while (!std::cin.eof()) {
    phonebook.printMenu();
    std::getline(std::cin, cmd);
    cmd = toLower(cmd);
    if (cmd == "add")
      phonebook.add();
    else if (cmd == "search")
      phonebook.search();
    else if (cmd == "exit")
      break;
    else
      std::cout << BRED << "\tInvalid command" << NC << std::endl;
  }
  return (0);
}

// Turn cmd into lkowercase
std::string toLower(std::string str) {
  for (size_t i = 0; i < str.length(); i++)
    str[i] = std::tolower(str[i]);
  return (str);
}
