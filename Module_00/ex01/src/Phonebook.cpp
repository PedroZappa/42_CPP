/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:13:52 by passunca          #+#    #+#             */
/*   Updated: 2024/09/14 16:24:54 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

void PhoneBook::printHeader(void)
{
	std::cout << BGRN << HEADER << NC << std::endl;
	std::cout << "Available Actions yo:";
	std::cout << HYEL"\t" << ARROW << "ADD" << std::endl;
	std::cout << HYEL"\t" << ARROW << "SEARCH" << std::endl;
	std::cout << HYEL"\t" << ARROW << "ESCAPE!!" << std::endl;
	std::cout << NC << std::endl;
}

void PhoneBook::printErr(std::string msg)
{
	std::cout << BRED << "Error: " << BYEL << msg << NC << std::endl;
}
