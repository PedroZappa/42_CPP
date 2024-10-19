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

#include "../inc/Account.hpp"
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
 * @return _nbAccounts
 */
int Account::getNbAccounts()
{
	return (t::_nbAccounts);
}
/**
 * @brief Get _totalAmount
 * @return _totalAmount
 */
int Account::getTotalAmount()
{
	return (t::_totalAmount);
}
/**
 * @brief Get _totalNbDeposits
 * @return _totalNbDeposits
 */
int Account::getNbDeposits()
{
	return (t::_totalNbDeposits);
}
/**
 * @brief Get _totalNbWithdrawals
 * @return _totalNbWithdrawals
 */
int Account::getNbWithdrawals()
{
	return (t::_totalNbWithdrawals);
}

/**
 * @brief Get Accounts Information
 */
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << t::getNbAccounts() << ";";
	std::cout << "total:" << t::getTotalAmount() << ";";
	std::cout << "deposits:" << t::getNbDeposits() << ";";
	std::cout << "withdrawals:" << t::getNbWithdrawals() << std::endl;
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

	// Write Deposit log to std::cout
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << (this->_amount - deposit) << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/**
 * @brief Make a Withdrawal
 * @param withdrawal
 * @return SUCCESS(true)
 * @return FAILURE(false)
 */
bool Account::makeWithdrawal(int withdrawal)
{
	bool success = false;

	if (withdrawal <= this->_amount) // Perform withdrawal
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		t::_totalNbWithdrawals++;
		t::_totalAmount -= withdrawal;
		success = true;
	}
	// Write Withdrawal log to std::cout
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	if (!success)
	{
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "p_amount:" << (this->_amount + withdrawal) << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

/**
 * @brief Get Account's Amount
 * @return Account's Amount
 * @note 'const' guarantees no modifications to object's state
 */
int Account::checkAmount(void) const
{
	return (this->_amount);
}

/**
 * @brief Get Account's Status
 * @note 'const' guarantees no modifications to object's state
 */
void Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
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
