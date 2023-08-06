/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:19:24 by ysrondy           #+#    #+#             */
/*   Updated: 2023/08/06 16:19:33 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hh"
#include "iostream"
#include "iomanip"
#include <ctime>
#include <chrono>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(NULL);

    // Convert the time to a local time string
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", std::localtime(&currentTime));

    std::cout << std::string(buffer);
}

Account::Account(int initial_deposit)
{
	static int i = 0;
	_accountIndex = i;
	_amount = initial_deposit;
	_totalAmount = initial_deposit + _totalAmount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	i++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	this->_amount = _amount + deposit;
	this->_nbDeposits = _nbDeposits + 1;
	_totalAmount = _totalAmount + deposit;
	_totalNbDeposits = _totalNbDeposits + 1;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposit:" << deposit << ";" << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << " index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	this->_amount = _amount - withdrawal;
	this->_nbWithdrawals = _nbWithdrawals + 1;
	_totalAmount = _totalAmount - withdrawal;
	_totalNbWithdrawals = _totalNbWithdrawals + 1;
	std::cout << " index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "withdrawal:" << withdrawal << ";" << "amount:" << _amount << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";" << "deposits:" << _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}
