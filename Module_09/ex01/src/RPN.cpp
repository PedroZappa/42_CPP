/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:35:04 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 11:12:11 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <cstring>

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
		return;
	}
	if (!isStringValid(input)) {
		std::cerr << RED "Error:" NC " invalid input" << std::endl;
		return;
	}
	if (!calculate(input)) {
		std::cerr << RED "Error:" NC " could not calculate" << std::endl;
		return;
	}
	if (this->_stack.size() != 1) {
		std::cerr << RED "Error:" NC " invalid input" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
}

/* ************************************************************************** */
/*                               Private Helpers                              */
/* ************************************************************************** */

void RPN::trimSpaces(std::string &str) {
	if (str.empty())
		return;
	str.erase(str.find_last_not_of(' ') + 1);
	str.erase(0, str.find_first_not_of(' '));
}

bool RPN::isStringValid(std::string elem) const {
	for (size_t i = 0; (i < elem.length()); i++) {
		char c = elem[i];
		if (!std::isdigit(c) && !std::strchr(OPS, c) && !std::isspace(c))
			return (false);
	}
	return (true);
}

bool RPN::calculate(std::string expr) {
	size_t len = expr.length();
	size_t i = 0;

	while (i < len) // while the expression string is not empty
	{
		char cC = expr[i];     // current char
		char nC = expr[i + 1]; // next char
		bool hasSign = (nC && std::isdigit(nC) && std::strchr(SIGNS, cC));

		if (std::isdigit(cC) || hasSign) { // if the current char is a digit
			int n = (std::atoi(expr.substr(i, (len - 1)).c_str())); // convert
			this->_stack.push(n); // push to stack
		} else if ((nC && std::isspace(nC) && std::strchr(OPS, cC)) ||
				   (std::strchr(OPS, cC) && !nC)) { //
			if (!doOp(cC))      // Attempt to do the operation
				return (false); // return if the operation is not valid
		}
		if (hasSign) // skip sign
			++i;
		while (std::isdigit(expr[i])) // skip digits
			++i;
		while (std::isspace(expr[i])) // skip spaces
			++i;
		// if the current char is an operator
		if ((std::strchr(OPS, cC) && nC && !std::isspace(nC)) && !hasSign) {
			std::cerr << RED "Error:" NC " invalid input" << std::endl;
			return (false);
		} else if (std::strchr(OPS, cC) && !hasSign)
			++i;
	}
	return (true);
}

bool RPN::doOp(const char &op) {
	if (this->_stack.size() < 2) {
		std::cerr << RED "Error:" NC " not enough operands" << std::endl;
		return (false);
	}
	int operand1 = this->_stack.top(); // Get operand at the top of the stack
	this->_stack.pop();                // Pop operand at the top of the stack
	int operand2 = this->_stack.top(); // Get next operand
	this->_stack.pop();                // Pop next operand

	if ((operand1 == 0) && (op == '/')) // Check for division by zero
	{
		std::cerr << RED "Error:" NC " division by zero" << std::endl;
		return (false);
	}
	int result = ops(operand1, operand2, op); // Perform the operation
	this->_stack.push(result); // Push the result to the stack
	return (true);
}

int RPN::ops(const int &operand1, const int &operand2, const char &op) {
	switch (op) {
	case '+':
		return (operand1 + operand2);
	case '-':
		return (operand2 - operand1);
	case '*':
		return (operand1 * operand2);
	case '/':
		return (operand2 / operand1);
	}
	return (0);
}
