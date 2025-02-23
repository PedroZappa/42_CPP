/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:28:39 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:45:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "../inc/Ansi.h"
#include <deque>
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
	// Iterators
	typedef typename std::stack<T>::container_type::iterator it;
	typedef typename std::stack<T>::container_type::const_iterator const_it;
	typedef typename std::stack<T>::container_type::reverse_iterator rev_it;
	typedef
		typename std::stack<T>::container_type::const_reverse_iterator const_rev_it;
	// Begin and End getters
	it begin() {
		return (this->c.begin());
	}
	it end() {
		return (this->c.end());
	}
	const_it begin() const {
		return (this->c.begin());
	}
	const_it end() const {
		return (this->c.end());
	}
	rev_it rbegin() {
		return (this->c.rbegin());
	}
	rev_it rend() {
		return (this->c.rend());
	}
	const_rev_it rbegin() const {
		return (this->c.rbegin());
	}
	const_rev_it rend() const {
		return (this->c.rend());
	}

  private:
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
