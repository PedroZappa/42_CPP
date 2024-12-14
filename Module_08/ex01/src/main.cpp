/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:02:24 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:21:30 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

#define WIDTH 50

int main(void) {
	headerPrinter("SPAN", 50, '-', GRN);
	// Test 1: Normal usage with a small span of size 5
	Span sp(5);
	// Add numbers within the container's size limit
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << BHGRN << "Test 1: Normal usage" << NC << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	sepPrinter(WIDTH, '-', GRN, 1);

	// Test 2: Empty Span
	Span emptySpan(3);
	try {
		std::cout << BHYEL << "Test 2: Empty Span" << NC << std::endl;
		std::cout << "Shortest Span: " << emptySpan.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << BHRED << "Exception caught: " << e.what() << NC << std::endl;
	}
	sepPrinter(WIDTH, '-', GRN, 1);

	// Test 3: Span with only one element
	Span oneElementSpan(1);
	try {
		oneElementSpan.addNumber(10);
		std::cout << BHYEL << "Test 3: Span with one element" << NC << std::endl;
		std::cout << "Shortest Span: " << oneElementSpan.shortestSpan()
				  << std::endl;
	} catch (const std::exception &e) {
		std::cout << BHRED << "Exception caught: " << e.what() << NC << std::endl;
	}
	std::cout << std::endl;
	sepPrinter(WIDTH, '-', GRN, 1);

	// Test 4: Testing addRange() with valid range
	std::vector<int> rangeVec;
	rangeVec.push_back(100);
	rangeVec.push_back(220);
	rangeVec.push_back(300);

	Span rangeSpan(10);
	std::cout << "Container size after addRange: " << rangeSpan.getSize()
			  << std::endl;
	rangeSpan.addRange(rangeVec.begin(), rangeVec.end());
	std::cout << BHGRN << "Test 7: addRange() Method" << NC << std::endl;
	std::cout << "Range Span Shortest Span: " << rangeSpan.shortestSpan()
			  << std::endl;
	std::cout << "Range Span Longest Span: " << rangeSpan.longestSpan()
			  << std::endl;
	std::cout << std::endl;
	sepPrinter(WIDTH, '-', GRN, 1);

	// Test 5: Testing with 10,000 numbers
	Span largeSpan(10000);
	std::cout << BHGRN << "Test 5: Large span with 10,000 numbers" << NC
			  << std::endl;

	// Add 10,000 numbers to the span (e.g., from 1 to 10000)
	for (int i = 1; i <= 10000; i++) {
		largeSpan.addNumber(i);
	}

	std::cout << "Shortest Span in large span: " << largeSpan.shortestSpan()
			  << std::endl;
	std::cout << "Longest Span in large span: " << largeSpan.longestSpan()
			  << std::endl;
	std::cout << std::endl;
	sepPrinter(WIDTH, '-', GRN, 1);

	// Test 6: Testing with 100,000 numbers, each larger than the previous by 666
	Span largeSpan666(100000);
	std::cout << BHGRN
			  << "Test 6: Large span with 100,000 numbers, each larger by 666"
			  << NC << std::endl;

	// Add 100,000 numbers to the span, each 666 larger than the previous one
	for (int i = 0; i < 100000; i++) {
		largeSpan666.addNumber(
			666 * (i + 1)); // The first number is 666, second is 1332, and so on
	}

	std::cout << "Shortest Span in large span (Test 6): "
			  << largeSpan666.shortestSpan() << std::endl;
	std::cout << "Longest Span in large span (Test 6): "
			  << largeSpan666.longestSpan() << std::endl;
	std::cout << std::endl;
	sepPrinter(WIDTH, '-', GRN, 1);
	//
	// Test 7: Testing ContainerFull exception when exceeding the span size
	Span spanForOverflow(5); // Create a Span with a size limit of 5
	std::cout << BHYEL << "Test 7: Testing ContainerFull exception" << NC
			  << std::endl;

	try {
		// Adding 6 numbers to a Span that can hold only 5
		spanForOverflow.addNumber(10);
		spanForOverflow.addNumber(20);
		spanForOverflow.addNumber(30);
		spanForOverflow.addNumber(40);
		spanForOverflow.addNumber(50);
		spanForOverflow.addNumber(
			60); // This will exceed the capacity and trigger the exception
	} catch (const Span::ContainerFull &e) {
		std::cout << BHRED << "Exception caught: " << e.what() << NC << std::endl;
	}

	std::cout << std::endl;
	sepPrinter(WIDTH, '-', GRN, 1);

	return (0);
}
