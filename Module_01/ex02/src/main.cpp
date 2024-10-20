/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:55:28 by passunca          #+#    #+#             */
/*   Updated: 2024/10/20 11:44:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <cstdlib>

/** 
* @brief Demystification of References & Pointers 
* (More ways to do Address Manipulation flavor)
* */
int main(void)
{
	// Unmodifiable string; stores the actual string data;
	// Cannot be reassigned (because const)
	// Has it's own memory location
	// 'stringREF' can NOT be NULL
	std::string const string = "HI THIS IS BRAIN"; 
	// Pointer to unmodifiable string; stores address of string data
	// Has its own memory location
	// The pointer itself can be reassigned to a different std::string;
	// 'stringPRT' can be NULL
	std::string const *stringPTR = &string;
	// Reference to unmodifiable
	// References cannot be reassigned
	// Does  NOT occupy additional memory beyond 'string'
	// Is an alias of 'string'
	// 'stringREF' can NOT be NULL
	std::string const &stringREF = string; 

	headerPrinter("Zedro's Memory Inspector", WIDTH);
	std::cout << " Address of " << BLU << "string:\t" \
	<< YEL << &string << NC << "\n" \
	<< " Address of " << BLU << "stringPTR:\t" \
	<< YEL << stringPTR << NC << "\n" \
	<< " Address of " << BLU << "stringREF:\t" \
	<< YEL << &stringREF << NC << "\n";

	sepPrinter(WIDTH);
	std::cout << " Value of " << BLU << "string:\t" \
	<< YEL << string << NC << "\n" \
	<< "Value of " << BLU << "stringPTR\t" \
	<< YEL << stringPTR << NC << "\n" \
	<< "Value of " << BLU << "stringREF\t" \
	<< YEL << stringREF << NC << "\n";

	sepPrinter(WIDTH);
	std::cout << BLU << "string" << NC << ", " << BLU "stringPTR " << NC \
	<< "and " << BLU << "stringREF\n" << NC << "all point to the same address\n"; 
	sepPrinter(WIDTH);

	return (EXIT_SUCCESS);
}
