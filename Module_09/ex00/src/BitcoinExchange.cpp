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
	std::cout << BYEL "BitcoinExchange" NC " readData called" << std::endl;
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
		std::string value;
		std::stringstream ss(line);

		std::getline(ss, date, ','); // Extract date
		ss >> value;                 // Extract value
		this->_db.insert(            // Insert into map
			std::pair<std::string, float>(date, std::atof(value.c_str())));
	}
	infile.close();
}

void BitcoinExchange::processData(const std::string &file) {
#ifdef DEBUG
	std::cout << BYEL "BitcoinExchange" NC " processData called" << std::endl;
#endif
	std::ifstream infile(file.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file");

	std::string line;
	std::getline(infile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid file header");
	while (std::getline(infile, line)) {
		std::string date;
		std::string value;
		std::string rest;
		std::stringstream ss(line);

		if (!this->isInputValid(line)) {
			std::cerr << "Error: " NC "invalid input" << std::endl;
			continue;
		}
		std::getline(ss, date, '|'); // Extract date
		ss >> value;                 // Extract value
		ss >> rest;                  // Extract rest of line
		this->removeSpace(rest);
		if (!rest.empty()) {
			std::cerr << RED "Error: " NC "invalid input" << std::endl;
			continue;
		}
		this->trimSpaces(date);
		this->trimSpaces(value);
		if (!this->isDateValid(date)) 
			std::cerr << "Error: " NC "invalid date" << std::endl;
		else if (!this->isValueValid(value))
			std::cerr << "Error: " NC "invalid value" << std::endl;
		else if (!this->isPositiveVal(value))
			std::cerr << "Error: " NC "invalid value" << std::endl;
		else if (!this->isWithinRange(date, value))
			std::cerr << "Error: " NC "invalid value" << std::endl;
		else
			this->printVals(date,value);
		
		this->printVals(date, value);
	}

	infile.close();
}

/** Checkers **/

bool BitcoinExchange::isInputValid(const std::string &input) const {
	// TODO:
}
