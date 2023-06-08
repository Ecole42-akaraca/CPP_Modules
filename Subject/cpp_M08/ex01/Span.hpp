#ifndef SPAN_HPP
 #define SPAN_HPP

#include <iostream>
#include <math.h>

class Span{
private:
	unsigned int	_n;
	int*			_array;
	unsigned int	_filled;

public:
	Span( void );
	Span( unsigned int N );
	// Span( const Span &ref );
	~Span( void );

	Span &operator=( const Span &ref );
	int	&operator[]( unsigned int i ) const;

	void	addNumber( unsigned int N );
	int		shortestSpan( void );
	int		longestSpan( void );

	unsigned int	getSize( void );

	class OutOfBoundsException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class ArrayIsFull : public std::exception{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &os, Span &obj );

#endif
