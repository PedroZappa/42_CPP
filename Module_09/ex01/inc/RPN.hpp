/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:27:40 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 09:59:37 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include "Ansi.h"
#include <iostream>
#include <cstring>
#include <stack>

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
	bool calculate(std::string elem);
	bool doOp(char &op);
};

#endif
