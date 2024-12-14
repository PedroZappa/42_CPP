/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:48:12 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 16:56:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

/** Constructors and Destructors */

BitcoinExchange::BitcoinExchange(void) : _db() {
#ifdef DEBUG
	std::cout << BGRN "BitcoinExchange" NC " Default constructor called"
			  << std::endl;
#endif
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _db(other._db) {
#ifdef DEBUG
	std::cout << BGRN "BitcoinExchange" NC " Copy constructor called"
			  << std::endl;
#endif
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
#ifdef DEBUG
	std::cout << BGRN "BitcoinExchange" NC " Copy assignment operator called"
			  << std::endl;
#endif
	if (this == &other)
		return *this;
	this->_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
#ifdef DEBUG
	std::cout << BRED "BitcoinExchange" NC " Destructor called" << std::endl;
#endif
}

/** Public Member Functions */

void BitcoinExchange::readData(const std::string &file) {
#ifdef DEBUG
	std::cout << BGRN "BitcoinExchange" NC " readData called" << std::endl;
#endif
	std::ifstream infile(file.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file");

	std::string line;
	std::getline(infile, line);
	if (line != "data,exchange_rate")
		throw std::runtime_error("Error: invalid file header");

	while (std::getline(infile, line)) {
		std::string date;
		std::string price;
		std::stringstream ss(line);

		std::getline(ss, date, ','); // Extract date
		ss >> price;                 // Extract price
		this->_db.insert(            // Insert into map
			std::pair<std::string, float>(date, std::atof(price.c_str())));
	}
	infile.close();
}
