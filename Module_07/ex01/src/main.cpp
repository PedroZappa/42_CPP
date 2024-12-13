/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:32:31 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 11:46:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main(void) {
	// Test Chars
	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrLen = sizeof(charArr) / sizeof(char);
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Chars: ";
	iter(charArr, (charArr + charArrLen), printElement<char>);
	std::cout << std::endl;

	// Test Ints
	int intArr[] = {1, 2, 3, 4, 5};
	size_t intArrLen = sizeof(intArr) / sizeof(int);
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Ints: ";
	iter(intArr, (intArr + intArrLen), printElement<int>);
	std::cout << std::endl;

	// Test Strings
	std::string strArr[] = {"One", "Two", "Three", "Four", "Five"};
	size_t strArrLen = sizeof(strArr) / sizeof(std::string);
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Strings: ";
	iter(strArr, (strArr + strArrLen), printElement<std::string>);
	std::cout << std::endl;

	// Test Double
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrLen = sizeof(doubleArr) / sizeof(double);
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Doubles: ";
	iter(doubleArr, (doubleArr + doubleArrLen), printElement<double>);
	std::cout << std::endl;

	// Test Custom Data
	t_data dataArr[] = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};
	size_t dataArrLen = sizeof(dataArr) / sizeof(t_data);
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Custom Data: ";
	iter(dataArr, (dataArr + dataArrLen), printElement<t_data>);
	std::cout << std::endl;

	return 0;
}
