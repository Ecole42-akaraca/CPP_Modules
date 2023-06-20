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
}

bool		PmergeMe::isListSorted(std::list<int>& list){
	if (list.empty() || list.size() == 1)
		return (true);
	
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator next = it;

	++next;
	while (next != list.end())
	{
		if (*next < *it)
			return (false);
		++it;
		++next;
	}
	return (true);
}

void		PmergeMe::printerList(std::string line){
	int l = 0;

	std::cout << line;
	for (std::list<int>::iterator i = _list.begin(); i != _list.end(); ++i, l++)
	{
		if (_list.size() > 10 && l == 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *i;
		if (std::next(i) != _list.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}
/*
bool		PmergeMe::isVectorSorted(std::vector<int>& vector){
	if (vector.empty() || vector.size() == 1)
		return (true);

    for (std::vector<int>::size_type i = 1; i < vector.size(); ++i) {
        if (vector[i] < vector[i-1]) {
            return false;
        }
    }
	return (true);
}

void		PmergeMe::printerVector(std::string line){
	int l = 0;

	std::cout << line;
	for (std::vector<int>::iterator i = _vector.begin(); i != _vector.end(); ++i, l++)
	{
		if (_vector.size() > 10 && l == 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *i;
		if (std::next(i) != _vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}*/

void		PmergeMe::mergeSorting(std::list<int>& list, std::list<int>& left, std::list<int>& right ){

	std::list<int>::iterator leftIt = left.begin();
	std::list<int>::iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end() )
	{
		if ( *leftIt <= *rightIt)
		{
			list.push_back(*leftIt);
			++leftIt;
		}
		else
		{
			list.push_back(*rightIt);
			++rightIt;
		}
	}

	list.insert(list.end(), leftIt, left.end());
	list.insert(list.end(), rightIt, right.end());
}

std::list<int>::iterator getPrev(std::list<int>::iterator it)
{
    return --it;
}

void		insertionSort( std::list<int>::iterator begin, std::list<int>::iterator end )
{
/*
	std::list<int>::iterator	it1, it2;

	for (it1 = begin; it1 != end; ++it1)
	{
		// int temp = *it1;
		std::list<int>::value_type	temp = *it1;
		it2 = it1;
		std::cout << *it2 << " - " << *(getPrev(it2)) << std::endl;
		while (it2 != begin && *(getPrev(it2)) > temp)
		{
			*it2 = *(getPrev(it2));
			std::advance(it2, -1);
		}
		*it2 = temp;
	}*/

    for (std::list<int>::iterator it1 = begin; it1 != end; ++it1)
    {
        std::list<int>::value_type temp = *it1;
        std::list<int>::iterator it2 = it1;
        while (it2 != begin && *getPrev(it2)  > temp)
        {
            *it2 = *getPrev(it2);
            --it2;
        }
        *it2 = temp;
    }
}


void		PmergeMe::mergeInsertSorting( std::list<int>& list ){

	if (list.size() <= 10)
	{
		insertionSort(list.begin(), list.end());
	}
	else
	{
		std::list<int> left, right;
		std::list<int>::iterator middle = list.begin();
		std::advance(middle, list.size() / 2); //std::distance(begin, end)

		for (std::list<int>::iterator it = list.begin(); it != middle; ++it) {
			left.push_back(*it);
		}

		for (std::list<int>::iterator it = middle; it != list.end(); ++it) {
			right.push_back(*it);
		}

		mergeInsertSorting(left);
		mergeInsertSorting(right);

		list.clear();
		mergeSorting(list, left, right);
	}
}

/*
	'merge-insert sort algorithm'

	merge sorting -> Argüman sayısı fazla olan yapıyı sıralmak için çok daha uygun
	insert sorting -> Argüman sayısı az olan yapıyı sıralamak için çok daha uygun

	Bizden subject ikisini birlikte kullanmamızı istediğinden dolayı:
		Belirli bir sayı üstünü merge sorting ile, belirli bir sayının altını ise insert sorting ile yapacağız.

*/
void			PmergeMe::sortListContainer( void ){

	PmergeMe::printerList("Before	(_list):	");
	clock_t start = clock();
	mergeInsertSorting(_list);
	clock_t end = clock();
	PmergeMe::printerList("After	(_list):	");
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list<int> : ";
	std::cout << PmergeMe::measureTime(start, end) << " us" << std::endl;
	std::cout << "List is " << GREEN << (PmergeMe::isListSorted(_list) ? "sorted" : "not sorted") << END << std::endl;
}

// void			PmergeMe::sortVectorContainer( void ){

// 	PmergeMe::printerVector("\nBefore	(_vector):	");
// 	PmergeMe::printerVector("After	(_vector):	");
// 	std::cout << "Vector is " << GREEN << (PmergeMe::isVectorSorted(_vector) ? "sorted" : "not sorted") << END << std::endl;
// }

double		PmergeMe::measureTime(clock_t start, clock_t end){
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double microseconds = duration * 1000000;
	return microseconds;
}
