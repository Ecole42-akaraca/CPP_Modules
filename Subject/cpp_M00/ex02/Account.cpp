#include <iostream>
#include "Account.hpp"
#include <ctime>

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

void	Account::_displayTimestamp( void ){
	char buffer[16];
	time_t start;

	//time(&start) -> value 1673345382 seconds since the Epoch
		//https://en.cppreference.com/w/cpp/chrono/c/time
	std::time(&start);

	// struct tm {
	// 	int	tm_sec;		/* seconds after the minute [0-60] */
	// 	int	tm_min;		/* minutes after the hour [0-59] */
	// 	int	tm_hour;	/* hours since midnight [0-23] */
	// 	int	tm_mday;	/* day of the month [1-31] */
	// 	int	tm_mon;		/* months since January [0-11] */
	// 	int	tm_year;	/* years since 1900 */
	// 	int	tm_wday;	/* days since Sunday [0-6] */
	// 	int	tm_yday;	/* days since January 1 [0-365] */
	// 	int	tm_isdst;	/* Daylight Savings Time flag */
	// 	long	tm_gmtoff;	/* offset from UTC in seconds */
	// 	char	*tm_zone;	/* timezone abbreviation */
	// };
	//localtime(&start) -> value 0x7ffd20405830
		//https://en.cppreference.com/w/cpp/chrono/c/localtime

	//strftime parameters
		// str	-	pointer to the first element of the char array for output
		// count	-	maximum number of bytes to write
		// format	-	pointer to a null-terminated multibyte character string specifying the format of conversion
		// time	-	pointer to the date and time information to be converted
			//https://en.cppreference.com/w/cpp/chrono/c/strftime

	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&start));
	std::cout << '[' << buffer << ']';
}

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts( void ){
	return (_nbAccounts++);
}

int Account::getTotalAmount( void ){
	return (_totalAmount);
}

int Account::getNbDeposits( void ){
	return (_totalNbDeposits++);
}

int Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals++);
}

Account::Account( int inital_deposit ){
	_accountIndex = getNbAccounts();
	_amount = inital_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << END << ";";
	std::cout << "amount:" << BLUE << _amount << END << ";created" << std::endl;
	_totalAmount += inital_deposit;
	//std::cout << "Account" << std::endl;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << " accounts:" << BLUE << _nbAccounts << END << ";";
	std::cout << "total:" << BLUE << _totalAmount << END << ";";
	std::cout << "deposits:" << BLUE << _totalNbDeposits << END << ";";
	std::cout << "withdrawals:" << BLUE << _totalNbWithdrawals << END << std::endl;
	//std::cout << "displayAccountsInfos" << std::endl;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << END << ";";
	std::cout << "amount:" << BLUE << _amount << END << ";";
	std::cout << "deposits:" << BLUE << _nbDeposits << END << ";";
	std::cout << "withdrawals:" << BLUE << _nbWithdrawals << END << std::endl;
	//std::cout << "displayStatus" << std::endl;
}

void	Account::makeDeposit( int deposit ){

	_displayTimestamp();
	getNbDeposits();
	std::cout << " index:" << BLUE << _accountIndex << END << ";";
	std::cout << "p_amount:" << BLUE << _amount << END << ";";
	std::cout << "deposit:" << BLUE << deposit << END << ";";
	std::cout << "amount:" << BLUE << _amount + deposit << END << ";";
	std::cout << "nb_deposits:" << BLUE << ++_nbDeposits << END << std::endl;
	_totalAmount += deposit;
	_amount += deposit;
	//std::cout << "makeDeposit" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << END << ";";
	std::cout << "p_amount:" << BLUE << _amount << END << ";";
	if (withdrawal <= _amount && withdrawal > 0)
	{
		getNbWithdrawals();
		std::cout << "withdrawal:" << BLUE << withdrawal << END << ";";
		std::cout << "amount:" << BLUE << _amount - withdrawal << END << ";";
		std::cout << "nb_withdrawals:" << BLUE << ++_nbWithdrawals << END << std::endl;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		//std::cout << "makeWithdrawal" << std::endl;
		return (1);
	}
	std::cout << "withdrawal:refused" << std::endl;
	//std::cout << "makeWithdrawal" << std::endl;
	return (0);
}

int	Account::checkAmount( void ) const{
	std::cout << "checkAmount" << std::endl;
	return (0);
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex << END << ";";
	std::cout << "amount:" << BLUE << _amount << END << ";";
	std::cout << "closed" << std::endl;
	//std::cout << "~Account" << std::endl;
}

