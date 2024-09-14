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

int main()
{
	std::string	input;
	PhoneBook	phonebook = PhoneBook();

	while (true)
	{
		phonebook.printMenu();
		std::getline(std::cin, input, '\n');
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
		else if (std::cin.eof())
			break ;
		else
			std::cout << BRED << "Invalid command" << NC << std::endl;
	}

	return (0);
}
