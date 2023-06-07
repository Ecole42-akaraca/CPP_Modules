#include "./PhoneBook.hpp"

int PhoneBook::_maxUser;

int	getLine( char *message, std::string *str ){

	std::cout << message;
	while (1){
		getline(std::cin >> std::ws, *str);
		if (std::cin.eof())
		{
			print((char *)(GREEN "\nProgram is shutdown!" END), true);
			return (1);
		}
		break;
	}
	return (0);
}

int	PhoneBook::cmdAdd( int i ){

	if (i > 7)
		i = 0;
	std::cout << "i değeri: " << i << std::endl;
	_users[i]._index = i;
	if (getLine((char *)"Enter First Name: ", &(_users[i]._firstName)) == 1)
		return (1);
	if (getLine((char *)"Enter Last Name: ", &(_users[i]._lastName)) == 1)
		return (1);
	if (getLine((char *)"Enter Nick Name: ", &(_users[i]._nickName)) == 1)
		return (1);
	if (getLine((char *)"Enter Phone Number: ", &(_users[i]._phoneNumber)) == 1)
		return (1);
	if (getLine((char *)"Enter Person Darkest Secret: ", &(_users[i]._darkSecret)) == 1)
		return (1);
	if (_maxUser < 8)
		PhoneBook::_maxUser++;
	return (0);
}

void	printPhoneBook( std::string str ){
	int size = str.size();
	int i;
	if (size > 10)
	{
		i = 0;
		while (i < 9)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << ".|";
	}
	else
	{
		i = 10 - size;
		while (i-- > 0)
			std::cout << " ";
		std::cout << str << "|";
	}
}

void	displayPersonInformation( Contact user ){
	std::cout << "Index: " << user._index << std::endl;
	std::cout << "First Name: " << user._firstName << std::endl;
	std::cout << "Last Name: " << user._lastName << std::endl;
	std::cout << "Nick Name: " << user._nickName << std::endl;
	std::cout << "Phone Number: " << user._phoneNumber << std::endl;
	std::cout << "Dark Secret: " << user._darkSecret << std::endl;
}

int	PhoneBook::cmdSearch( void ){

	int			i;
	int			l;
	std::string	buffer;

	i = 0;
	if (_maxUser != 0)
	{
		print((char *)("|     Index|First Name| Last Name| Nick Name|"), true);
		while (i < this->_maxUser){

			std::cout << "|         " << i << "|";
			printPhoneBook(_users[i]._firstName);
			printPhoneBook(_users[i]._lastName);
			printPhoneBook(_users[i]._nickName);
			std::cout << std::endl;
			i++;
		}
		getLine((char *)("Enter the index of the person you want to view: "), &buffer);
		if (std::cin.eof())
		{
			print((char *)(GREEN "\nProgram is shutdown!" END), true);
			return (1);
		}
		l = std::atoi(buffer.c_str());
		if (buffer.length() == 1 && ((buffer.compare("0") == 0 && l == 0) || (l > 0 && l < _maxUser)))
			displayPersonInformation(_users[l]);
		else
			print((char *)(RED "!!!Wrong Index Number" END), true);
	}
	else
		print((char *)(RED "!!!No User is Registered" END), true);
	return (0);
}
