/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:55:01 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:10:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include "Ansi.h"
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <limits>

class Span {
  public:
	Span(unsigned int N);
	Span(Span const &src);
	~Span(void);

	Span &operator=(const Span &src);

	// Getters
	unsigned int getSize(void) const;
	size_t getLast(void) const;
	size_t getCapacity(void) const;
	size_t shortestSpan(void) const;
	size_t longestSpan(void) const;

	// Printers
	void printContainer(void) const;

	// Operations
	void addNumber(int n);
	void addRange(std::vector<int>::iterator begin,
				  std::vector<int>::iterator end);

	// Exceptions Classes
	class ContainerFull : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return (RED "Array is full" NC);
		};
	};
	class EmptySpan : public std::exception {
	  public:
		virtual const char *what() const throw() {
			return (RED "Span is empty" NC);
		};
	};

  private:
	unsigned int _size;
	std::vector<int> _container;
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
