/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:13:49 by passunca          #+#    #+#             */
/*   Updated: 2024/12/12 11:06:39 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Whatever.hpp"

int main(void) {
	// Integer
	int x = 7;
	int y = 0;
	::swap(x, y);
	std::cout << "x = " YEL << x << NC "\ny = " YEL << y << NC << std::endl;
	std::cout << "min( x, y ) = " BLU << ::min(x, y) << NC << std::endl;
	std::cout << "max( x, y ) = " GRN << ::max(x, y) << NC << std::endl;

	// String
	std::string yo = "Yo!";
	std::string zedro = "Zedro";
	std::cout << "yo = " YEL << yo << NC "\nzedro = " YEL << zedro << NC
			  << std::endl;
	std::cout << "min( yo, zedro ) = " BLU << ::min(yo, zedro) << NC << std::endl;
	std::cout << "max( yo, zedro ) = " GRN << ::max(yo, zedro) << NC << std::endl;

	// Custom t_data
	t_data data1 = {7, "Yo!"};
	t_data data2 = {5, "Hello"};

	std::cout << "data1 = " YEL << data1 << NC << std::endl;
	std::cout << "data2 = " YEL << data2 << NC << std::endl;

	::swap(data1, data2);
	std::cout << "After swap:" << std::endl;
	std::cout << "data1 = " YEL << data1 << NC << std::endl;
	std::cout << "data2 = " YEL << data2 << NC << std::endl;

	std::cout << "min(data1, data2) = " BLU << ::min(data1, data2) << NC
			  << std::endl;
	std::cout << "max(data1, data2) = " GRN << ::max(data1, data2) << NC
			  << std::endl;
	return 0;
}
