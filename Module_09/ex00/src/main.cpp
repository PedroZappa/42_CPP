/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:13:34 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 19:16:22 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./BitcoinExchange <file>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;
	try {
		exchange.readData("data.csv");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	try {
		exchange.processData(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
