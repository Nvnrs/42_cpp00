#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
// void	Account::displayAccountsInfos( void )
// {

// }

void	printVal(std::string key, int val, bool semicolon)
{
	std::cout << key;
	if (val >= 0)
		std::cout << ":" << val;
	semicolon ? std::cout << ";" : std::cout << std::endl;
}


Account::Account( int initial_deposit )
{
	this->_accountIndex = 0;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount+= initial_deposit;
	this->_displayTimestamp();
	printVal("index", this->_accountIndex, true);
	printVal("amount", this->_amount, true);
	printVal("created", -1, false);
}
Account::~Account( void )
{
	this->_displayTimestamp();
	printVal("index", this->_accountIndex, true);
	printVal("amount", this->_amount, true);
	printVal("closed", -1, false);
}

void Account::makeDeposit( int deposit )
{
	const int	amountBeforeDeposit = this->_amount;
	const int	nb_deposit = 1;
	this->_nbDeposits+= nb_deposit;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	Account::_displayTimestamp();
	printVal("index", this->_accountIndex, true);
	printVal("p_amount", amountBeforeDeposit, true);
	printVal("deposit", deposit, true);
	printVal("amount", this->_amount, true);
	printVal("nb_deposits", nb_deposit, false);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	printVal("accounts", _nbAccounts, true);
	printVal("total", _totalAmount, true);
	printVal("deposits", _totalNbDeposits, true);
	printVal("withdrawals", _totalNbWithdrawals, false);
	return;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}


void	Account::_displayTimestamp( void )
{
   	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "["
		<< (now->tm_year + 1900)
         << (now->tm_mon + 1)
         <<  now->tm_mday
         <<  '_'
         <<  now->tm_hour
         <<  now->tm_min
         <<  now->tm_sec
         << "] ";
	// std::cout << "[19920104_091532] ";
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	printVal("index", this->_accountIndex, true);
	printVal("amount", this->_amount, true);
	printVal("deposits", this->_nbDeposits, true);
	printVal("withdrawals", this->_nbWithdrawals, false);
}


bool Account::makeWithdrawal( int withdrawal )
{
	const int	amountBeforeWithdrawal = this->_amount;
	const int	nbWithdrawal = 1;
	
	Account::_displayTimestamp();
	printVal("index", this->_accountIndex, true);
	printVal("p_amount", amountBeforeWithdrawal, true);
	if ((this->_amount - withdrawal) < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals+= nbWithdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	printVal("withdrawal", withdrawal, true);
	printVal("amount", this->_amount, true);
	printVal("nb_withdrawals", nbWithdrawal, false);
	return (true);
}

