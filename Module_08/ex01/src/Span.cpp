/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:04:11 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:24:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Span.cpp
 * @brief Implementation of the Span class.
 */

#include "../inc/Span.hpp"

/**
 * @brief Construct a new Span object with a specified size.
 * @param N The maximum number of elements the Span can hold.
 */
Span::Span(unsigned int N) : _size(N) {
#ifdef DEBUG
	std::cout << BLU "Span " NC " constructor called" << std::endl;
#endif
	// this->_container.clear();
	this->_container.reserve(N);
}

/**
 * @brief Copy constructor for Span.
 * @param copy The Span object to copy from.
 */
Span::Span(Span const &copy) {
#ifdef DEBUG
	std::cout << "Span copy constructor called" << std::endl;
#endif
	*this = copy;
}

/**
 * @brief Destroy the Span object.
 */
Span::~Span(void) {
#ifdef DEBUG
	std::cout << RED "Span" NC " destructor called" << std::endl;
#endif
}

/**
 * @brief Assignment operator for Span.
 * 
 * @param src The Span object to assign from.
 * @return Span& A reference to the assigned Span object.
 */
Span &Span::operator=(const Span &src) {
#ifdef DEBUG
	std::cout << "Span assignment operator called" << std::endl;
#endif
	if (this == &src)
		return (*this);
	this->_size = src.getSize();
#ifdef DEBUG
	std::cout << "Assigning container of size " << this->_size << std::endl;
#endif
	for (unsigned int i = 0; i < this->_size; i++)
		this->_container[i] = src._container[i];
	return (*this);
}

/**
 * @brief Get the size of the Span.
 * @return unsigned int The maximum number of elements the Span can hold.
 */
unsigned int Span::getSize(void) const {
	return (this->_size);
}

/**
 * @brief Get the last element in the Span.
 * 
 * @return size_t The last element in the Span.
 * @throw EmptySpan if the Span is empty.
 */
size_t Span::getLast(void) const {
	if (this->_container.empty())
		throw EmptySpan();
	return (this->_container.back());
}

/**
 * @brief Get the capacity of the Span.
 * @return size_t The capacity of the Span.
 */
size_t Span::getCapacity(void) const {
	return (this->_container.capacity());
}

/**
 * @brief Calculate the shortest span between any two numbers in the Span.
 * @return size_t The shortest span.
 * @throw EmptySpan if the Span is empty or contains only one element.
 */
size_t Span::shortestSpan(void) const {
	std::vector<int> toSort(this->_container);
	size_t shortest = std::numeric_limits<size_t>::max();
	size_t diff;

	if ((toSort.empty()) || (toSort.size() == 1))
		throw EmptySpan();
	std::sort(toSort.begin(), toSort.end());

	std::vector<int>::const_iterator it;
	for (it = toSort.begin(); (it != (toSort.end() - 1)); it++) {
		diff = (abs(*it - *(it + 1)));
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

/**
 * @brief Calculate the longest span between any two numbers in the Span.
 * @return size_t The longest span.
 * @throw EmptySpan if the Span is empty or contains only one element.
 */
size_t Span::longestSpan(void) const {
	if (this->_container.size() <= 1)
		throw EmptySpan();
	std::vector<int>::const_iterator min =
		std::min_element(this->_container.begin(), this->_container.end());
	std::vector<int>::const_iterator max =
		std::max_element(this->_container.begin(), this->_container.end());
	return (*max - *min);
}

/**
 * @brief Print the elements of the Span.
 */
void Span::printContainer(void) const {
	for (std::vector<int>::const_iterator it = this->_container.begin();
		 it != this->_container.end();
		 ++it)
		std::cout << *it << " | ";
	std::cout << std::endl;
}

/**
 * @brief Add a number to the Span.
 * 
 * @param n The number to add.
 * @throw ContainerFull if the Span is already full.
 */
void Span::addNumber(int n) {
	if (this->_container.size() >= this->getSize())
		throw ContainerFull();
	this->_container.push_back(n);
}

/**
 * @brief Add a range of numbers to the Span.
 * @param begin Iterator to the beginning of the range.
 * @param end Iterator to the end of the range.
 * @throw ContainerFull if adding the range would exceed the Span's capacity.
 */
void Span::addRange(std::vector<int>::iterator begin,
					std::vector<int>::iterator end) {
	int range = std::abs(end - begin); // Calculate the number of elements to add
	if ((this->_container.size() + range) > this->getSize())
		throw ContainerFull();
	for (; begin != end; ++begin) { // Add all elements in the range
		this->_container.push_back(*begin);
	}
}

/**
 * @brief Exception thrown when attempting to add to a full Span.
 */
const char* Span::ContainerFull::what() const throw() {
    return (RED "Array is full" NC);
}

/**
 * @brief Exception thrown when attempting to perform operations on an empty Span.
 */
const char* Span::EmptySpan::what() const throw() {
    return (RED "Span is empty" NC);
}
