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

int main()
{
	std::string	input;
	PhoneBook	phonebook = PhoneBook();

	while (true)
	{
		phonebook.printMenu();
		std::getline(std::cin, input, '\n');
		input = toLower(input);
		if (input == "add")
			phonebook.add();
		else if (input == "search")
			phonebook.search();
		else if (input == "exit")
			break ;
		else if (std::cin.eof())
			break ;
		else
			std::cout << BRED << "Invalid command" << NC << std::endl;
	}

	return (0);
}

// Turn input into lkowercase
std::string toLower(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	return (str);
}
