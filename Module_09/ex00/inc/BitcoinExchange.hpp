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

#include <algorithm>
#include <ctime>
#include <map>
#include <stdexcept>
#include <string>
#include <fstream> // std::ifstream
#include <sstream> // std::stringstream

class BitcoinExchange {
  public:
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
	bool isValidInput(const std::string &input) const;
	bool isValidDate(const std::string &date) const;
	bool isValidVal(const std::string &value) const;
	bool isPositiveVal(const std::string &value) const;
	bool isWithinRange(const std::string &range, const std::string &value) const;
	bool isSameDate(const std::tm &date1, const std::tm &date2) const;

	// Printers
	void printVals(const std::string &date, const std::string &value) const;

	// Operations
	void removeSpace(std::string &str);
	void trimSpaces(std::string &str);
	std::tm parseDate(const std::string &date, const std::string &format) const;
	float getNearestDate(const std::tm &date) const;
	long toLongDate(const std::string &date) const;
};

/** @brief UI Helper Functions */
void headerPrinter(const std::string &headerText,
				   int inWidth,
				   char sep,
				   const char *sepColor);
void sepPrinter(int inWidth, char sepChar, const char *color, int nLines);

#endif
