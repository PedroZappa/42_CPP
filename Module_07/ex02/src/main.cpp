/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:04:29 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 13:32:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#define N 10

int main(void) {
	// Create Array
	Array<int> nbrs(N);
	int *copy = new int[N];
	srand(time(NULL));

	// Test Exception
	try
	{
		std::cout << nbrs[N] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Fill Array
	try {
		for (int i = 0; i < N; i++) {
			nbrs[i] = rand() % 100;
			copy[i] = nbrs[i];
		}
		// Print Array
		sepPrinter(50, '=', GRN, 1);
		std::cout << YEL "Array of Ints: " NC;
		for (int i = 0; i < N; i++) {
			std::cout << BMAG << nbrs[i] << NC << " ";
		}
		std::cout << std::endl;
		sepPrinter(50, '=', GRN, 1);

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Free Array
	delete[] copy;
	return (0);
}
