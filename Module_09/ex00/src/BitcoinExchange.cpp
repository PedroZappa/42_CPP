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
#include <cctype>

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

	std::string input;
	std::getline(infile, input);
	if (input != "data,exchange_rate")
		throw std::runtime_error("Error: invalid file header");

	while (std::getline(infile, input)) {
		std::string date;
		std::string value;
		std::stringstream ss(input);

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

	std::string input;
	std::getline(infile, input);
	if (input != "date | value")
		throw std::runtime_error("Error: invalid file header");
	while (std::getline(infile, input)) {
		std::string date;
		std::string value;
		std::string rest;
		std::stringstream ss(input);

		if (!this->isInputValid(input)) {
			std::cerr << "Error: " NC "invalid input" << std::endl;
			continue;
		}
		std::getline(ss, date, '|'); // Extract date
		ss >> value;                 // Extract value
		ss >> rest;                  // Extract rest of input
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
			this->printVals(date, value);
	}

	infile.close();
}

void BitcoinExchange::printData(void) const {
	std::map<std::string, float>::const_iterator it;

	for (it = this->_db.begin(); it != this->_db.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

size_t BitcoinExchange::getDbSize(void) const {
	return (this->_db.size());
}

/** Checkers **/

bool BitcoinExchange::isInputValid(std::string &input) {
	this->removeSpace(input);
	if (input.empty() || (input.find_first_not_of('|') == std::string::npos) ||
		(input.find_first_not_of('|') != input.find_last_not_of('|')) ||
		(input.find_first_of('|') == input.length() - 1))
		return (false);
	return (true);
}

bool BitcoinExchange::isDateValid(const std::string &date) const {
	if ((std::count(date.begin(), date.end(), '-') != 2) || (date.length() != 10))
		return (false);

	for (size_t i = 0; i < date.length(); i++)
		if (!std::isdigit(date[i]) && (date[i] != '-'))
			return (false);

	std::tm *readDate = this->parseDate(date, "%Y-%m-%d");
	if (readDate == NULL)
		return (false);

	delete readDate;
	return (true);
}
