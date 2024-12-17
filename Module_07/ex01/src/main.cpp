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

// Custom Data Type For testing
int i;
std::string str;

bool t_data::operator<(const s_data &other) const {
	return (i < other.i) || (i == other.i && str < other.str);
}

bool t_data::operator>(const s_data &other) const {
	return (i > other.i) || (i == other.i && str > other.str);
}

s_data &t_data::operator=(const s_data &other) {
	if (this != &other) {
		i = other.i;
		str = other.str;
	}
	return *this;
}

// Inline to avoid ODR violations
std::ostream &operator<<(std::ostream &os, const t_data &data) {
	os << "{i: " << data.i << ", str: " << data.str << "}";
	return os;
}

int main(void) {
	// Test Chars
	char charArr[] = {'z', 'e', 'd', 'r', 'o'};
	size_t charArrLen = (sizeof(charArr) / sizeof(char));
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Chars: ";
	iter(charArr, charArrLen, printElement<char>);
	std::cout << std::endl;

	// Test Ints
	int intArr[] = {1, 2, 3, 4, 5};
	size_t intArrLen = (sizeof(intArr) / sizeof(int));
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Ints: ";
	iter(intArr, intArrLen, printElement<int>);
	std::cout << std::endl;

	// Test Strings
	std::string strArr[] = {"One", "Two", "Three", "Four", "Five"};
	size_t strArrLen = (sizeof(strArr) / sizeof(std::string));
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Strings: ";
	iter(strArr, strArrLen, printElement<std::string>);
	std::cout << std::endl;

	// Test Double
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrLen = (sizeof(doubleArr) / sizeof(double));
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Doubles: ";
	iter(doubleArr, doubleArrLen, printElement<double>);
	std::cout << std::endl;

	// Test Custom Data
	t_data dataArr[] = {
		{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};
	size_t dataArrLen = (sizeof(dataArr) / sizeof(t_data));
	sepPrinter(50, '=', GRN, 1);
	std::cout << "Print Array of Custom Data: ";
	iter(dataArr, dataArrLen, printElement<t_data>);
	std::cout << std::endl;

	return 0;
}
