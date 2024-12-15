/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:07:06 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 11:17:44 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <operand1> <operand2> <operator>" << std::endl;
		std::cerr << "Example: ./RPN \"21 21 +\"" << std::endl;
		return (EXIT_FAILURE);
	}

	RPN rpn;
	rpn.parseInput(argv[1]);
	
	return (EXIT_SUCCESS);
}
