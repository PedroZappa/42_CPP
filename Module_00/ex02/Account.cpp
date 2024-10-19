/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:45:31 by passunca          #+#    #+#             */
/*   Updated: 2024/10/17 10:00:30 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>    // std::time
#include <iomanip>  // std::setfill std::setw
#include <iostream> // std::cout std::endl

/**
 *	Initializes Account's class static private members
 */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 *	Account class Constructor
 */
Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_totalAmount += initial_deposit;

	// Write Account's creation log to std::cout
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

/**
 *	Account class Destructor
 */
Account::~Account(void)
{
	// Write Account's destruction log to std::cout
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/**
 * Account clkass Helper Methods
 */
static void _displayTimestamp(void)
{
	std::time_t	rawtime;
	std::tm *timestamp;

	rawtime = std::time(0);
	timestamp = std::localtime(&rawtime);

	std::cout << "[" << timestamp->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_sec << "] ";
}
