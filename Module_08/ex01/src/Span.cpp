/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:04:11 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:17:15 by passunca         ###   ########.fr       */
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
	for (std::vector<int>::const_iterator it = toSort.begin();
		 (it != (toSort.end() - 1));
		 it++)
		diff = (abs(*it - *(it + 1)));
	if (diff < shortest)
		shortest = diff;
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

void Span::addRange(std::vector<int>::iterator begin,
					std::vector<int>::iterator end) {
	int range = std::abs(end - begin); // Calculate the number of elements to add
	if (this->_container.size() + range > this->getSize())
		throw ContainerFull();
	for (; begin != end; ++begin) { // Add all elements in the range
		this->_container.push_back(*begin);
	}
}
