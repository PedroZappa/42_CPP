/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:53:52 by passunca          #+#    #+#             */
/*   Updated: 2024/12/14 16:57:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Ansi.h"
#include <algorithm>
#include <cctype>
#include <cstring> // std::memset
#include <ctime>
#include <fstream>  // std::ifstream
#include <iostream> // std::cerr
#include <limits>   // std::numeric_limits
#include <map>
#include <sstream> // std::stringstream
#include <stdexcept>
#include <string>

class BitcoinExchange {
  public:
	// Constructors
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	// Public Functions
	void readData(const std::string &file); // [X]:
	void processData(const std::string &file);
	void printData(void) const;
	size_t getDbSize(void) const;

  private:
	std::map<std::string, float> _db; // MAP CONTAINER

	// Checkers
	bool isInputValid(std::string &input);
	bool isDateValid(const std::string &date) const;
	bool isValueValid(const std::string &value) const;
	bool isPositiveVal(const std::string &value) const;
	bool isWithinRange(const std::string &range, const std::string &value) const;
	bool isSameDate(const std::tm *d1, const std::tm *d2) const;

	// Printers
	void printVals(const std::string &date, const std::string &value) const;

	// Private Helpers
	void removeSpace(std::string &str);
	void trimSpaces(std::string &str);
	std::tm *parseDate(const std::string &date, const std::string &format) const;
	float getNearestDate(std::string &date);
	long toLongDate(std::string &date);

	// Exceptions
	class InvalidInput: public std::exception {
	  public:
		const char *what() const throw();
	};

	class InvalidDate: public std::exception {
	  public:
		const char *what() const throw();
	};

	class InvalidValue: public std::exception {
	  public:
		const char *what() const throw();
	};

	class NegativeValue: public std::exception {
	  public:
		const char *what() const throw();
	};

	class OutOfRange: public std::exception {
	  public:
		const char *what() const throw();
	};
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
