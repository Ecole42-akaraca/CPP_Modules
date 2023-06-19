#include "PmergeMe.hpp"

std::list<int>		PmergeMe::_list;
std::vector<int>	PmergeMe::_vector;

std::string			PmergeMe::intToString( int num ){

	std::stringstream ss;
	ss << num;
	return (ss.str());
}

/*
std::istringstream iss;

iss.str(argv[i]);
iss >> value;  // (max integer'a / min integer'a) kadar destekliyor

argLenght > PmergeMe::intToString(value).size(); // gelen argüman '111a' şeklinde gelen argümanı kontrol etmek için uzunluğundan yararlanıyoruz.
*/
void				PmergeMe::checkArg( int argc, char **argv ){

	std::istringstream	iss;
	int					value;
	size_t				argLenght;

	if (argc < 1)
		throw ( NotEnoughtInputs() );
	for (int i = 0; i < argc; i++)
	{
		iss.clear();
		iss.str(argv[i]);
		argLenght = std::string(argv[i]).size();
		if (iss >> value)
		{
			if (value < 0 || (argLenght > PmergeMe::intToString(value).size()))
			{
				iss.clear();
				throw ( WrongInputs() );
			}
			continue;
		}
		else
		{
			iss.clear();
			throw ( WrongInputs() );
		}
	}
}

void				PmergeMe::setContainers( int argc, char **argv ){

	int	value;

	for (int i = 0; i < argc; i++)
	{
		value = std::atoi(argv[i]);
		_list.push_back(value);
		_vector.push_back(value);
	}

	std::cout << "Before: ";
	for (int i = 0; i < argc; i++)
	{
		if (argc > 10 && i == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << argv[i];
		if (i + 1 != argc)
			std::cout << " ";
	}
	std::cout << std::endl;

	/*std::cout << "_list: ";
	for ( std::list<int>::iterator i = _list.begin(); i != _list.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << "_vector: ";
	for ( std::vector<int>::iterator i = _vector.begin(); i != _vector.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;*/

}

void			PmergeMe::sortListContainer( void ){
	
}
