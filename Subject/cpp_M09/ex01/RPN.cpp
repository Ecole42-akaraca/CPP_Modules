#include "RPN.hpp"

std::string				RPN::_input = "";
std::string				RPN::_allowedChars = "0123456789 +-/*";
std::stack<std::string>	RPN::_arr;

void					RPN::setInput( std::string input ) { _input = input; }
std::string				RPN::getInput( void ) { return (_input); }
std::stack<std::string>	&RPN::getContainer( void ) { return (_arr); }

int						RPN::stringToInt( std::string str ){
	
	std::stringstream ss(str);
	int value = 0;
	ss >> value;
	return (value);
}

void					RPN::unwantedChars( void ){

	for (std::string::size_type i = 0; i < RPN::getInput().length(); ++i)
		if (RPN::_allowedChars.find(RPN::getInput()[i]) == std::string::npos)
			throw ( ContainsUnwantedChars() );
}

void					RPN::setContainer( void ){

	std::istringstream iss(RPN::getInput());
	std::string word;
	while (iss >> word) {
		if (word.size() > 1 || RPN::stringToInt(word) > 9)
			throw ( WrongInputs() );
		RPN::getContainer().push(word);
	}
}

void					RPN::checkArg( int argc, char **argv ){

	if (argc < 2)
		throw ( NotEnoughtInputs() );
	if (argc > 2)
		throw ( TooManyInputs() );
	RPN::setInput(argv[1]);
	RPN::unwantedChars();
	RPN::setContainer();
}

void					RPN::printRPN( void ){

/*	std::stack<std::string>::container_type::iterator it = RPN::getContainer().begin();
	std::stack<std::string>::container_type::iterator ite = RPN::getContainer().end();

	std::cout << BLUE "Array[ ";

	if (it != ite)
	{
		while (it != ite){
			std::cout << *it;
			if (std::next(it) != ite)
				std::cout << ", ";
			++it;
		}
	}
	else
	{
		std::cout << "EMPTY";
	}
	std::cout << " ]\n" END << std::endl;*/
}
