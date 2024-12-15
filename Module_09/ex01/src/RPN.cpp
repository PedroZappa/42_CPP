/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:35:04 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 10:10:58 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

/* ************************************************************************** */
/*                                Constructors                                */
/* ************************************************************************** */

RPN::RPN(void) : _stack() {
}

RPN::RPN(const RPN &copy) : _stack(copy._stack) {
}

RPN &RPN::operator=(const RPN &other) {
	if (this == &other)
		return *this;
	this->_stack = other._stack;
	return *this;
}

RPN::~RPN(void) {
}

/* ************************************************************************** */
/*                               Public Helpers                               */
/* ************************************************************************** */

void RPN::parseInput(std::string input) {
    trimSpaces(input);
    if (input.empty()) {
        std::cerr << RED "Error:" NC " empty input" << std::endl;
        return ;
    }
    if (!isStringValid(input)) {
        std::cerr << RED "Error:" NC " invalid input" << std::endl;
        return ;
    }
    if (!calculate(input)) {
        std::cerr << RED "Error:" NC " could not calculate" << std::endl;
        return ;
    }
    if (this->_stack.size() != 1) {
        std::cerr << RED "Error:" NC " invalid input" << std::endl;
        return ;
    }
    std::cout << _stack.top() << std::endl;
}

/* ************************************************************************** */
/*                               Private Helpers                              */
/* ************************************************************************** */

void RPN::trimSpaces(std::string &str) {
	if (str.empty())
		return ;
	str.erase(str.find_last_not_of(' ') + 1);
	str.erase(0, str.find_first_not_of(' '));
}
