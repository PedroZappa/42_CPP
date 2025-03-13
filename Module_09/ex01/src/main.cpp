/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:07:06 by passunca          #+#    #+#             */
/*   Updated: 2024/12/15 11:45:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

/**
 * @brief Main function to execute the RPN calculator.
 * 
 * This function checks for the correct number of command-line arguments,
 * initializes an RPN object, and parses the input expression.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int Returns EXIT_SUCCESS on successful execution, otherwise EXIT_FAILURE.
 */
int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED "Usage: " NC "./RPN <operand1> <operand2> <operator>"
				  << std::endl;
		std::cerr << YEL "Example: " NC "./RPN \"21 21 +\"" << std::endl;
		return (EXIT_FAILURE);
	}

	RPN rpn;
	rpn.parseInput(argv[1]);

	return (EXIT_SUCCESS);
}
