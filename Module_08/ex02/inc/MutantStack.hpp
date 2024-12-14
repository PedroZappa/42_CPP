/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:28:39 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 12:43:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "../inc/Ansi.h"
#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T, std::deque<T> > {
  public:
	typedef typename std::stack<T, std::deque<T> > stackDeque;
	typedef typename std::deque<T>::iterator dequeIt;

	// Constructors
	MutantStack(void) {
	}
	MutantStack(const MutantStack &src) {
		*this = src;
	}
	MutantStack &operator=(const MutantStack &src) {
		stackDeque::operator=(src);
		return (*this);
	}
	~MutantStack(void) {
	}

	// Iterators
	dequeIt begin(void) {
		return (this->stackDeque::c.begin());
	}
	dequeIt end(void) {
		return (this->stackDeque::c.end());
	}

  private:
};

#endif
