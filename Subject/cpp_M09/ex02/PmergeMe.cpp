#include "PmergeMe.hpp"

std::list<int>		PmergeMe::_list;
std::vector<int>	PmergeMe::_vector;
int					PmergeMe::_insertSortingLimit = 100;

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

/*
	start ve end herhangi bir özel birim belirtmez.
	1 saniye = 10^6 us
*/
double				PmergeMe::measureTime(clock_t start, clock_t end){
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC; // saniye cinsinden değerini elde etmiş oluruz.
	double microseconds = duration * 1000000; // us cinsinden elde etmek için çarpıyoruz.
	return microseconds;
}

/* ------------------------------------------------ List Methods ------------------------------------------------ */

bool				PmergeMe::isListSorted(std::list<int>& list){
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

void				PmergeMe::printerList(std::string line){
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
		if (PmergeMe::ListGetNext(i) != _list.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

std::list<int>::iterator PmergeMe::ListGetNext(std::list<int>::iterator it){
	return ++it;
}

std::list<int>::iterator PmergeMe::ListGetPrev(std::list<int>::iterator it){
	return --it;
}

void				PmergeMe::ListMergeSorting(std::list<int>& list, std::list<int>& left, std::list<int>& right ){

	std::list<int>::iterator leftIt = left.begin();
	std::list<int>::iterator rightIt = right.begin();

	// İki list'te karşılaştırılıyor, küçük olan değer pushlanıyor.
	while (leftIt != left.end() && rightIt != right.end()) {
		if (*leftIt <= *rightIt) {
			list.push_back(*leftIt);
			++leftIt;
		} else {
			list.push_back(*rightIt);
			++rightIt;
		}
	}

	// Pushlanmayan sayılar burada pushlanıyor.
	while (leftIt != left.end()) {
		list.push_back(*leftIt);
		++leftIt;
	}

	while (rightIt != right.end()) {
		list.push_back(*rightIt);
		++rightIt;
	}

	/*while (leftIt != left.end() && rightIt != right.end() )
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
	list.insert(list.end(), rightIt, right.end());*/
}

void				PmergeMe::ListInsertSorting( std::list<int>::iterator begin, std::list<int>::iterator end )
{
/*
	std::list<int>::iterator	it1, it2;

	for (it1 = begin; it1 != end; ++it1)
	{
		std::list<int>::value_type	temp = *it1;
		it2 = it1;
		std::cout << *it2 << " - " << *(getPrev(it2)) << std::endl;
		while (it2 != begin && *(getPrev(it2)) > temp)
		{
			*it2 = *(getPrev(it2));
			std::advance(it2, -1); // Bir adım geriye taşı
		}
		*it2 = temp;
	}*/

	for (std::list<int>::iterator it1 = begin; it1 != end; ++it1)
	{
		std::list<int>::value_type temp = *it1;
		std::list<int>::iterator it2 = it1;
		while (it2 != begin && *ListGetPrev(it2)  > temp)
		{
			*it2 = *ListGetPrev(it2);
			--it2; // it2'nin gösterdiği konumu bir önceki konuma hareket ettirir.
		}
		*it2 = temp; // elemanın doğru konumuna yerleştirilmesi için kullanılır.
	}
}

void				PmergeMe::ListMergeInsertSorting( std::list<int>& list ){

	if ((int)list.size() <= _insertSortingLimit)
	{
		ListInsertSorting(list.begin(), list.end());
	}
	else
	{

		std::list<int> left, right;
		int mid = list.size() / 2;
		std::list<int>::iterator it = list.begin();
		for (int i = 0; i < mid; i++)
		{
			left.push_back(*it);
			++it;
		}
		while (it != list.end())
		{
			right.push_back(*it);
			++it;
		}

		// std::list<int>::iterator middle = list.begin();
		// std::advance(middle, list.size() / 2);

		// for (std::list<int>::iterator it = list.begin(); it != middle; ++it) {
		// 	left.push_back(*it);
		// }

		// for (std::list<int>::iterator it = middle; it != list.end(); ++it) {
		// 	right.push_back(*it);
		// }

		ListMergeInsertSorting(left); // öncelikle bitmesi beklenen fonksiyon
		ListMergeInsertSorting(right);

		list.clear();
		ListMergeSorting(list, left, right); // son girilen kısım
	}
}

/*
	'merge-insert sort algorithm'

	merge sorting -> Argüman sayısı fazla olan yapıyı sıralamak için çok daha uygun
	insert sorting -> Argüman sayısı az olan yapıyı sıralamak için çok daha uygun

	Bizden subject ikisini birlikte kullanmamızı istediğinden dolayı:
		Belirli bir sayı üstünü merge sorting ile, belirli bir sayının altını ise insert sorting ile yapacağız.

*/
void				PmergeMe::sortListContainer( void ){

	PmergeMe::printerList("Before	(_list):	");
	clock_t start = clock();
	ListMergeInsertSorting(_list);
	_list.sort();
	clock_t end = clock();
	PmergeMe::printerList("After	(_list):	");
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list<int> : ";
	std::cout << PmergeMe::measureTime(start, end) << " us" << std::endl;
	std::cout << "List is " << (PmergeMe::isListSorted(_list) ? GREEN "sorted" : RED "not sorted") << END << std::endl;
}

/* ------------------------------------------------ Vector Methods ------------------------------------------------ */

bool				PmergeMe::isVectorSorted(std::vector<int>& vector){
	if (vector.empty() || vector.size() == 1)
		return (true);

	for (std::vector<int>::size_type i = 1; i < vector.size(); ++i) {
		if (vector[i] < vector[i-1]) {
			return false;
		}
	}
	return (true);
}

void				PmergeMe::printerVector(std::string line){
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
		std::vector<int>::iterator l = i;
		++l;
		if (l != _vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void				PmergeMe::VectorInsertSorting( std::vector<int>& vector, int left, int right ){

	for (int i = left + 1; i <= right; i++) {
		int key = vector[i];
		int j = i - 1;

		while (j >= left && vector[j] > key) {
			vector[j + 1] = vector[j];
			j--;
		}

		vector[j + 1] = key;
	}
}

void				PmergeMe::VectorMergeSorting( std::vector<int>& vector, int left, int middle, int right ){

	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = vector[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = vector[middle + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vector[k] = L[i];
			i++;
		} else {
			vector[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		vector[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		vector[k] = R[j];
		j++;
		k++;
	}
}

void				PmergeMe::VectorMergeInsertSorting( std::vector<int>& vector, int left, int right ){

	if (right - left <= _insertSortingLimit)
	{
		VectorInsertSorting(vector, left, right);
	}
	else
	{
		int middle = left + (right - left) / 2;

		VectorMergeInsertSorting(vector, left, middle);
		VectorMergeInsertSorting(vector, middle + 1, right);

		VectorMergeSorting(vector, left, middle, right);
	}
}

void				PmergeMe::sortVectorContainer( void ){

	PmergeMe::printerVector("\nBefore	(_vector):	");
	clock_t start = clock();
	VectorMergeInsertSorting(_vector, 0, _vector.size() - 1);
	// std::sort(_vector.begin(), _vector.end());
	clock_t end = clock();
	PmergeMe::printerVector("After	(_vector):	");
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<int> : ";
	std::cout << PmergeMe::measureTime(start, end) << " us" << std::endl;
	std::cout << "Vector is " << (PmergeMe::isVectorSorted(_vector) ? GREEN "sorted" : RED "not sorted") << END << std::endl;
}
