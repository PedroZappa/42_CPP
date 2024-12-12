/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:53:36 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 13:31:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Ansi.h"
#include <cstdlib> // rand()
#include <iostream>

template <typename T> class Array {
  public:
	Array(void) : _arr(NULL), _len(0) {
#ifdef DEBUG
		std::cout << "Array default constructor called" << std::endl;
#endif
		_arr = new T[this->_len]();
	}

	Array(unsigned int n) : _len(n) {
#ifdef DEBUG
		std::cout << "Array constructor called" << std::endl;
#endif
		_arr = new T[n]();
	}

	Array(const Array &copy) : _arr(NULL), _len(copy._len) {
#ifdef DEBUG
		std::cout << "Array copy constructor called" << std::endl;
#endif
		this->_arr = new T[copy.size()];
		for (unsigned int i = 0; i < this->_len; i++) {
			this->_arr[i] = copy._arr[i];
		}
		*this = copy;
	}

	~Array(void) {
#ifdef DEBUG
		std::cout << "Array destructor called" << std::endl;
#endif
		if (this->_arr)
			delete[] this->_arr;
	}

	// Functz
	unsigned int size(void) const {
		return this->_len;
	}

	// operator Overload
	Array &operator=(const Array &copy) {
		if (this == &copy) {
			return *this;
		}
		if (this->_arr)
			delete[] this->_arr;
		this->_arr = new T[copy.size()];
		for (unsigned int i = 0; i < this->_len; i++) {
			this->_arr[i] = copy._arr[i];
		}
		this->_len = copy.size();
		return (*this);
	}

	T &operator[](unsigned int index) {
		if (index >= this->_len) {
			throw std::exception();
		}
		return this->_arr[index];
	}

	class OutOfBoundsException : public std::exception {
		virtual const char *what() const throw() {
			return "Index out of bounds";
		}
	};

  private:
	T *_arr;
	unsigned int _len;
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);
