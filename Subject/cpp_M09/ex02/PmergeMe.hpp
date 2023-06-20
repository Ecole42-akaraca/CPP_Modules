#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <vector>
# include <algorithm>
# include <sstream>
# include "Color.hpp"
# include <sys/time.h>
#include <iomanip>
#include <ctime>

class PmergeMe{

private:
	static std::list<int>	_list;
	static std::vector<int>	_vector;

public:
	static std::string	intToString( int num );
	static void			checkArg( int argc, char **argv );
	static void			setContainers( int argc, char **argv );
	static void			sortListContainer( void );
	static void			mergeInsertSorting( std::list<int>& list );
	static void			mergeSorting(std::list<int>& list, std::list<int>& left, std::list<int>& right );
	static bool			isListSorted(std::list<int>& list);
	static void			printerList( std::string line );
	// static bool			isVectorSorted(std::vector<int>& vector);
	// static void			printerVector(std::string line);
	// static void			sortVectorContainer( void );
	static double		measureTime(clock_t start, clock_t end);

	class NotEnoughtInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: not enought inputs!	###" END );
			}
	};

	class WrongInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: wrong inputs!	###" END );			
			}
	};

};

#endif
