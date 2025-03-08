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

#include "../inc/Span.hpp"

/** Parameterized Constructor **/
Span::Span(unsigned int N) : _size(N) {
#ifdef DEBUG
	std::cout << BLU "Span " NC " constructor called" << std::endl;
#endif
	// this->_container.clear();
	this->_container.reserve(N);
}

/** Copy Constructor **/
Span::Span(Span const &copy) {
#ifdef DEBUG
	std::cout << "Span copy constructor called" << std::endl;
#endif
	*this = copy;
}

/** Destructor **/
Span::~Span(void) {
#ifdef DEBUG
	std::cout << RED "Span" NC " destructor called" << std::endl;
#endif
}

/** Assignment Operator **/
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

//** Getters **/
unsigned int Span::getSize(void) const {
	return (this->_size);
}

size_t Span::getLast(void) const {
	if (this->_container.empty())
		throw EmptySpan();
	return (this->_container.back());
}

size_t Span::getCapacity(void) const {
	return (this->_container.capacity());
}

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

size_t Span::longestSpan(void) const {
	if (this->_container.size() <= 1)
		throw EmptySpan();
	std::vector<int>::const_iterator min =
		std::min_element(this->_container.begin(), this->_container.end());
	std::vector<int>::const_iterator max =
		std::max_element(this->_container.begin(), this->_container.end());
	return (*max - *min);
}

//** Printers **/
void Span::printContainer(void) const {
	for (std::vector<int>::const_iterator it = this->_container.begin();
		 it != this->_container.end();
		 ++it)
		std::cout << *it << " | ";
	std::cout << std::endl;
}

//** Operations **/
void Span::addNumber(int n) {
	if (this->_container.size() >= this->getSize())
		throw ContainerFull();
	this->_container.push_back(n);
}

/**
 * @brief Adds a range of numbers to the Span container.
 *
 * Inserts the numbers from the given iterator range [begin, end) into the container.
 * Before adding the numbers, it checks if doing so would exceed the container's
 * maximum capacity (returned by getSize()). If the capacity would be exceeded,
 * a ContainerFull exception is thrown.
 *
 * @param begin Iterator pointing to the start of the range to add.
 * @param end Iterator pointing one past the end of the range.
 *
 * @throws ContainerFull If the total number of elements after the addition exceeds the allowed size.
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
 * @brief Returns the error message for a full container.
 *
 * This method provides a color-coded string indicating that the container has reached its maximum capacity.
 *
 * @return const char* A pointer to the error message "Array is full" with red formatting.
 */
const char* Span::ContainerFull::what() const throw() {
    return (RED "Array is full" NC);
}

/**
 * @brief Returns a formatted error message for an empty span.
 *
 * This method overrides the standard exception's `what()` function to provide a
 * color-coded error message indicating that the span is empty.
 *
 * @return const char* A constant C-string with the error message.
 */
const char* Span::EmptySpan::what() const throw() {
    return (RED "Span is empty" NC);
}
