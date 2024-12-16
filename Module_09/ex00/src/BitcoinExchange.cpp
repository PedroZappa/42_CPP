/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:48:12 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 20:38:38 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

/* ************************************************************************** */
/*                        Constructors and Destructors                        */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                          Public Member Functions                           */
/* ************************************************************************** */

void BitcoinExchange::readData(const std::string &file) {
#ifdef DEBUG
	std::cout << BYEL "BitcoinExchange" NC " readData called" << std::endl;
#endif
	std::ifstream infile(file.c_str());
	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file");

	std::string input;
	std::getline(infile, input);
	if (input != "date,exchange_rate")
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
			std::cerr << RED "Error: " NC "empty input" << std::endl;
			continue;
		}
		this->trimSpaces(date);
		this->trimSpaces(value);
		if (!this->isDateValid(date))
			std::cerr << "Error: " NC "bad input => " << input << std::endl;
		else if (!this->isValueValid(value))
			std::cerr << "Error: " NC "invalid value" << std::endl;
		else if (!this->isPositiveVal(value))
			std::cerr << "Error: " NC "not a positive number" << std::endl;
		else if (!this->isWithinRange(value))
			std::cerr << "Error: " NC "value out of range" << std::endl;
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

/* ************************************************************************** */
/*                                  Checkers                                  */
/* ************************************************************************** */

bool BitcoinExchange::isInputValid(std::string &input) {
	this->removeSpace(input);
	if (input.empty() || (input.find_first_not_of('|') == std::string::npos) ||
		(input.find_first_of('|') != input.find_last_of('|')) ||
		(input.find_first_of('|') == 0) ||
		(input.find_first_of('|') == (input.length() - 1)))
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

bool BitcoinExchange::isValueValid(const std::string &value) const {
	// Ensure Value is not empty
	if (value.empty())
		return (false);

	// Check for Sign
	bool sign = ((value[0] == '-') || (value[0] == '+'));
	if (sign && value.size() == 1) // Only a sign, no digits
		return (false);

	// Ensure Value Rules
	size_t startIdx = (sign ? 1 : 0);
	if (!std::isdigit(value[startIdx]) && value[startIdx] != '.')
		return (false);
	if (value.find_first_not_of("0123456789.", startIdx) != std::string::npos)
		return (false);

	// Ensure Decimal Point rules
	if (value.find_first_of('.') != value.find_last_of('.'))
		return (false);

	return (true);
}

bool BitcoinExchange::isPositiveVal(const std::string &value) const {
	double val = std::atof(value.c_str());
	return (val >= 0);
}

bool BitcoinExchange::isWithinRange(const std::string &value) const {
	long val = std::atol(value.c_str());
	return (val <= 1000);
}

bool BitcoinExchange::isSameDate(const std::tm *d1, const std::tm *d2) const {
	if ((d1->tm_year == d2->tm_year) || (d1->tm_mon == d2->tm_mon) ||
		(d1->tm_mday == d2->tm_mday))
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                  Printers                                  */
/* ************************************************************************** */

void BitcoinExchange::printVals(std::string &date, const std::string &value) {
	std::map<std::string, float>::const_iterator it = this->_db.find(date);
	std::cout << date << " => " << value << " = ";
	if (it != this->_db.end()) {
		std::cout << (std::atof(value.c_str()) * it->second) << std::endl;
	} else {
		std::cout << (std::atof(value.c_str()) * this->getNearestDate(date))
				  << std::endl;
	}
}

/* ************************************************************************** */
/*                              Private Helpers                               */
/* ************************************************************************** */

void BitcoinExchange::removeSpace(std::string &str) {
	if (str.empty())
		return;
	for (size_t i = 0; i < str.length(); i++) {
		if (std::isspace(str[i])) {
			str.erase(str.begin() + i);
			--i;
		}
	}
}

void BitcoinExchange::trimSpaces(std::string &str) {
	if (str.empty())
		return;
	str.erase(str.find_last_not_of(' ') + 1); // remove trailing spaces
	str.erase(0, str.find_first_not_of(' ')); // remove leading spaces
}

std::tm *BitcoinExchange::parseDate(const std::string &date,
									const std::string &format) const {
	std::tm *readDate = new std::tm();
	std::memset(readDate, 0, sizeof(std::tm));

	// Set Date string according to format
	if (!strptime(date.c_str(), format.c_str(), readDate)) {
		delete readDate;
		return (NULL);
	}

	struct std::tm time = *readDate;
	mktime(&time); // Normalize date
	if (!this->isSameDate(&time, readDate)) {
		delete readDate;
		return (NULL);
	}

	return (readDate);
}

float BitcoinExchange::getNearestDate(std::string &date) {
	std::map<std::string, float>::const_iterator it;
	long long minRange = std::numeric_limits<long long>::max();
	long long longD = this->toLongDate(date); // Convert to long
	long long dateDiff;
	float result = -1; // Default value (-1 == invalid)

	for (it = this->_db.begin(); it != this->_db.end(); it++) {
		// Compute absolute difference
		dateDiff = (std::abs(this->toLongDate(it->first) - longD));
		if ((dateDiff < minRange) && (dateDiff != 0)) {
			minRange = dateDiff; // Update closest date 
			result = it->second;
		}
	}
	return (result);
}

long BitcoinExchange::toLongDate(std::string date) {
	for (size_t i = 0; i < date.length(); i++) {
		if (date[i] == '-') {
			date.erase(date.begin() + i);
			--i;
		}
	}
	long longD = std::atol(date.c_str());
	return (longD);
}

/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char *BitcoinExchange::InvalidInput::what(void) const throw() {
	return (RED "Invalid Input" NC);
}

const char *BitcoinExchange::InvalidDate::what(void) const throw() {
	return (RED "Invalid Date" NC);
}

const char *BitcoinExchange::InvalidValue::what(void) const throw() {
	return (RED "Invalid Value" NC);
}

const char *BitcoinExchange::NegativeValue::what(void) const throw() {
	return (RED "Negative Value" NC);
}

const char *BitcoinExchange::OutOfRange::what(void) const throw() {
	return (RED "Out of Range" NC);
}
