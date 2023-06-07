#include "PhoneBook.hpp"

void	print( char *str, bool endl ){

	std::cout << str;
	if (endl == true)
		std::cout << std::endl;
}

int	main( void )
{
	PhoneBook	pBook;
	std::string	input;
	int			i;

	i = 0;
	while (1){
		print((char *)(YELLOW "#Useable Commands: ADD, SEARCH, EXIT" END), true);
		print((char *)(BLUE "Enter Command: " END), false);
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
		{
			if (pBook.cmdAdd(i) == 1)
				return (1);
			i++;
			if (i == 8)
				i = 0;
		}
		else if (input.compare("SEARCH") == 0)
		{
			if (pBook.cmdSearch() == 1)
				return (1);
		}
		else if (std::cin.eof() || input.compare("EXIT") == 0)
		{
			print((char *)(GREEN "\nProgram is shutdown!" END), true);
			return (1);
		}
		else
			print((char *)(RED "!!!Wrong input!" END), true);
	}
	return (0);
}
