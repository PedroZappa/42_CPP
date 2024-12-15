/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:27:40 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 11:10:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include "Ansi.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

#define OPS "+-*/"
#define SIGNS "+-"

class RPN {
	public:
	RPN(void);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &other);
	~RPN(void);

	// Public Helpers
	void parseInput(std::string input);

private:
	std::stack<int> _stack;

	// Private Helpers
	void trimSpaces(std::string &str);
	bool isStringValid(std::string elem) const;
	bool calculate(std::string expr);
	bool doOp(const char &op);
	int ops(const int &operand1, const int &operand2, const char &op);
};

#endif
