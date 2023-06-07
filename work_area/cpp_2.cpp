#include <iostream>


class Account{
private:
	int _nbAccounts;
	int _totalAmount;

public:
	int getNbAccounts(void);
	int getTotalAmount(void);
};

int getNbAccounts(void){
	std::cout << Account::_nbAccounts << std::endl;
}

int main()
{
	getNbAccounts();
	return (0);
}