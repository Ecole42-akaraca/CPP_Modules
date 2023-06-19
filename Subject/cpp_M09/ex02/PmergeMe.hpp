#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <vector>
# include <algorithm>
# include <sstream>
# include "Color.hpp"

class PmergeMe{

private:
	static std::list<int>	_list;
	static std::vector<int>	_vector;

public:
	static std::string	intToString( int num );
	static void			checkArg( int argc, char **argv );
	static void			setContainers( int argc, char **argv );
	static void			sortListContainer( void );
	static void			sortVectorContainer( void );

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
