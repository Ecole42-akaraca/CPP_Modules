#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <stack>
# include "Color.hpp"

template< typename T >
void easyfind( T &container, int value ){ // int value değeri olduğundan dolayı, double bir arama işlemi gerçekleştiremiyoruz.

	if (std::find(container.begin(), container.end(), value) != container.end())
		std::cout << GREEN "Value: " << value << " --> ✓ Found" END << std::endl;
	else
		std::cout << RED "Value: " << value << " --> X Not Found!" END << std::endl;
}

template < typename T >
void	printer( T& container ){

	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

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
	std::cout << " ]\n" END << std::endl;
}

/*
//---------------------------------------------- Vector'e özel printer ------------------------------------------------------------------//
template< typename T >
void printer( const std::vector<T>& container ){
	std::cout << BLUE "Array[ ";
	if (!container.empty())
	{
		for (int i = 0; container[i] != '\0'; i++)
		{
			std::cout << container[i];
			if (container[i + 1] != '\0')
				std::cout << ", ";
		}
	}
	else
	{
		std::cout << "EMPTY";
	}
	std::cout << " ]\n" END << std::endl;
}
*/

//----------------------------------------------std::vector<std::string> için çıktı alma methodu------------------------------------------------------------------//
// void printer( const std::vector<std::string>& container){
// 	std::cout << BLUE "Array[ ";
//     if (!container.empty()) {
//         std::vector<std::string>::const_iterator it = container.begin();
//         std::cout << *it;
//         ++it;
//         while (it != container.end()) {
//             std::cout << ", " << *it;
//             ++it;
//         }
//     }
// 	else
// 	{
// 		std::cout << "EMPTY";
// 	}
// 	std::cout << " ]\n" END << std::endl;	
// }

//----------------------------------------------Farklı bir tarz------------------------------------------------------------------//
// template< typename T >
// typename T::iterator easyfind( T &container, int value ){
// 	typename T::iterator it = container.begin();
// 	typename T::iterator ite = container.end();
// 	while (it != ite)
// 	{
// 		if (*it == value)
// 			return ( it );
// 		++it;
// 	}
// 	return ite;
// }

// Kullanımı için:
	// int main(){
	// 	std::vector<int> vec;
	// 	vec.push_back(10);
	// 	vec.push_back(20);
	// 	vec.push_back(30);
	// 	std::vector<int>::iterator result = easyfind(vec, 30);
	// 	if (result == vec.end())
	// 	{
	// 		std::cout << "Value not found in vector." << std::endl;
	// 	}
	// 	else
	// 	{
	// 		std::cout << "Value found in vector." << std::endl;
	// 	}
	// 	std::list<int> lst;
	// 	lst.push_back(100);
	// 	lst.push_back(200);
	// 	lst.push_back(300);
	// 	std::list<int>::iterator res = easyfind(lst, 400);
	// 	if (res == lst.end())
	// 	{
	// 		std::cout << "Value not found in list." << std::endl;
	// 	}
	// 	else
	// 	{
	// 		std::cout << "Value found in list." << std::endl;
	// 	}
	// }

//----------------------------------------------İtertor nasıl çalışıyor begin ve end olayı------------------------------------------------------------------//
//template< typename T >
// void easyfind( T &container, int value ){
// 	int find = 0;
// 	typename T::iterator it = container.begin();
// 	typename T::iterator ite = container.end();
// 	while (it != ite)
// 	{
// 		if (*it == value)
// 		{
// 			std::cout << "buldu" << std::endl;
// 			find = 1;
// 		}
// 		std::cout << "değer: " << *it << std::endl;
// 		++it;
// 	}
// 	if (find == 0 && it == ite)
// 	{
// 		std::cout << "bulamadi" << std::endl;
// 		if (!*ite)
// 			std::cout << "NULL" << *ite << std::endl;
// 	}
// 	std::cout << "------" << std::endl;
// }

#endif
