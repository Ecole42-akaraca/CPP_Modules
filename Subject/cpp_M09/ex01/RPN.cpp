#include "RPN.hpp"

std::string					RPN::_input = "";
std::string					RPN::_allowedChars = "0123456789 +-/*";
std::stack<int>				RPN::_arr;

void						RPN::setInput( std::string input ) { _input = input; }
std::string					RPN::getInput( void ) { return (_input); }
std::stack<int>&			RPN::getContainer( void ) { return (_arr); }

int							RPN::stringToInt( std::string str ){

	std::stringstream ss(str);
	int value = 0;
	ss >> value;
	return (value);
}

void						RPN::unwantedChars( void ){

	for (std::string::size_type i = 0; i < RPN::getInput().length(); ++i)
		if (RPN::_allowedChars.find(RPN::getInput()[i]) == std::string::npos)
			throw ( ContainsUnwantedChars() );
}

void						RPN::checkArg( int argc, char **argv ){

	if (argc < 2)
		throw ( NotEnoughtInputs() );
	if (argc > 2)
		throw ( TooManyInputs() );
	RPN::setInput(argv[1]);
	RPN::unwantedChars();
}

/*
	Operatör görene kadar sayıları stack'e pushluyor, operatör görünce stack'ten 2 sayı alıyor.
	En üstten alınan sayı num2, bir sonraki sayı ise num1 olarak ifade ediliyor.
	Operator işlemi sırasında bu sayılar kullanılacağı için pop() edilip stack'ten kaldırılıyor.
	Elde edilen sonuç tekrardan stack'e push()'lanıyor.
*/
void						RPN::printRPN( void ){

	std::istringstream iss(RPN::getInput());
	std::string token;

	while (iss >> token) {
		if (token.size() > 1 || RPN::stringToInt(token) > 9)
			throw ( WrongInputs() );
		if (isdigit(token[0])) {
			RPN::getContainer().push(RPN::stringToInt(token));
		} else {

			int num2 = RPN::getContainer().top(); RPN::getContainer().pop();
			int num1 = RPN::getContainer().top(); RPN::getContainer().pop();
			std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;

			if (token == "+") {
				RPN::getContainer().push(num1 + num2);
			} else if (token == "-") {
				RPN::getContainer().push(num1 - num2);
			} else if (token == "*") {
				RPN::getContainer().push(num1 * num2);
			} else if (token == "/") {
				RPN::getContainer().push(num1 / num2);
			}
		}
	}
	std::cout <<  RPN::getContainer().top() << std::endl;
}
