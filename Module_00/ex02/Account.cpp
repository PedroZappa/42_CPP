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

/*	Initializes Account's class static private members */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Account class Constructor
 * @param initial_deposit
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
 *	@brief Account class Destructor
 */
Account::~Account(void)
{
	// Write Account's destruction log to std::cout
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/* Account Class Public Methods */

/**
 * @brief Get _nbAccounts
 */
int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}
/**
 * @brief Get _totalAmount
 */
int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}
/**
 * @brief Get _totalNbDeposits
 */
int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}
/**
 * @brief Get _totalNbWithdrawals
 */
int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

/**
 * @brief Get Accounts Information
 */
void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/**
 * @brief Make a Deposit
 * @param deposit
 */
void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;         // Update account balance
	this->_nbDeposits++;              // Increment number of deposits
	Account::_totalNbDeposits++;      // Increment global number of deposits
	Account::_totalAmount += deposit; // Update total amount across all accounts

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << (this->_amount - deposit) << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/* Account Class Private Methods */

/**
 * @brief Print Timestamps
 */
static void _displayTimestamp(void)
{
	std::time_t rawtime;
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
