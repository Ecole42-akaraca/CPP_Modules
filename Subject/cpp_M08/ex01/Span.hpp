#ifndef SPAN_HPP
 #define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include "Color.hpp"

class Span{
private:
	unsigned int	_n;
	std::list<int>	_list; // list yapısında new ile yer açmaya gerek yok.

public:
	Span( void );
	Span( unsigned int N );
	Span( const Span &ref );
	~Span( void );

	Span	&operator=( const Span &ref );

	void	addNumber( unsigned int N );
	void	addNumber( std::list<int>::const_iterator begin, std::list<int>::const_iterator end );
	int		shortestSpan( void );
	int		longestSpan( void );

	const std::list<int>*	getList( void ) const;
	int						getSize( void );
	int						getMax( void );
	int						getMin( void );

	class OutOfBoundsException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class ArrayIsFull : public std::exception{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &os, const Span &obj );

#endif
