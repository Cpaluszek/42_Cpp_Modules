/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:07:05 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/12 13:34:38 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// Static
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposit" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void Account::_displayTimestamp() {
	time_t rawTime = time(NULL);
	struct tm *pLocal = localtime(&rawTime);
	std::cout << '[' << pLocal->tm_year + 1900 << pLocal->tm_mon << pLocal->tm_mday <<
			  '_' << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << ']';
}

// Members
Account::Account(int initial_deposit) :
		_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount" << _amount << ";created" << std::endl;
}

Account::~Account() {
	_totalAmount -= this->_amount;
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	p_amount = _amount;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
		<< ";deposit:" << deposit << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
	  	<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;
	_displayTimestamp();
	if (_amount < withdrawal) {
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
	  		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return (true);
}

int Account::checkAmount() const {
	return this->_amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
  		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
  		<< std::endl;
}


