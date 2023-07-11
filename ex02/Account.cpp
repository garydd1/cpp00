#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int initial_deposit)
: _accountIndex(_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount+=initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout <<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

void Account::_displayTimestamp() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);

    std::cout << buffer;
}
// void Account::_displayTimestamp( void )
// {
//     std::time_t now = std::time(nullptr);
//     std::tm* current_time = std::localtime(&now);

//     std::cout << "[" << (current_time->tm_year + 1900) << "-"
//               << (current_time->tm_mon + 1) << "-" << current_time->tm_mday
//               << " " << current_time->tm_hour << ":" << current_time->tm_min
//               << ":" << current_time->tm_sec << "] ";
// }

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{	
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout <<"accounts:"<<Account::getNbAccounts() <<";total:"<<Account::getTotalAmount()<<";deposits:"<<Account::getNbDeposits()<<";withrdrawals:"<<Account::getNbWithdrawals() <<std::endl;
}


void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<"index:"<<_accountIndex<<";amount:" <<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void Account::makeDeposit (int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit<<";amount:"<<_amount+deposit<<";nb_deposits:"<<_nbDeposits+1<<std::endl;
	_amount+=deposit;
	_nbDeposits++;
	_totalAmount+=deposit;
	_totalNbDeposits++;

}

bool Account::makeWithdrawal (int withdrawal)
{
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout <<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
		return (false);
	}
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:"<<withdrawal<<";amount:"<<_amount-withdrawal<<";nb_withdrawals:"<<_nbWithdrawals+1<<std::endl;
	_amount-=withdrawal;
	_nbWithdrawals++;
	_totalAmount-=withdrawal;
	_totalNbWithdrawals++;
	return (true);
}