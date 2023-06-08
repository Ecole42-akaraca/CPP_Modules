#include "Span.hpp"

Span::Span( void ) : _n(0), _array(NULL), _filled(0){
	std::cout << "Default Constructor Called" << std::endl;
}

Span::Span( unsigned int N ) : _n(N), _array(new int[N]), _filled(0){
	std::cout << "Constructor Called" << std::endl;
}

Span::~Span( void ){
	std::cout << "Destructor Called" << std::endl;
	delete[] this->_array;
}

Span &Span::operator=( const Span &ref ){
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		delete[] this->_array;
		this->_array = new int[ref._n];
		this->_n = ref._n;
		this->_filled = ref._filled;
		for (unsigned int i = 0; i < this->_n; i++)
			this->_array[i] = ref._array[i];
	}
	return (*this);
}

int	&Span::operator[]( unsigned int i ) const{
	try
	{
		if (i >= this->_n)
			throw ( OutOfBoundsException() );
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	return ( this->_array[i] );
}

void Span::addNumber( unsigned int N ){
	try
	{
		if (this->_filled < this->getSize())
		{
			this->_array[_filled] = N;
			this->_filled++;
		}
		else
			throw( ArrayIsFull() );
	}
	catch ( std::exception &e)
	{
		std::cerr << e.what() << "\n"; 
	}
}

int	Span::shortestSpan( void ){
	if (this->_filled > 1)
	{
		std::sort(this->_array, this->_array + this->_filled);
		int	min = std::abs( this->_array[1] - this->_array[0] );
		for (unsigned int i = 2; i < this->_filled; i++)
		{
			int diff = std::abs( this->_array[i] - this->_array[i - 1] );
			if (diff < min)
				min = diff;
		}
		return (min);
	}
	return (0);
}

int Span::longestSpan( void ){
	if (this->_filled > 1)
	{
		std::sort(this->_array, this->_array + this->_filled);
		return (abs(this->_array[this->_filled - 1] - this->_array[0]));
	}
	return (0);
}

unsigned int	Span::getSize( void ){
	return (this->_n);
}

const char* Span::OutOfBoundsException::what() const throw(){
	return ( "Index is out of bounds!" );
}

const char* Span::ArrayIsFull::what() const throw(){
	return ( "Array is Full!" );
}

std::ostream &operator<<( std::ostream &os, Span &obj ){
	os << "[ ";
	for (unsigned int i = 0; i < obj.getSize(); i++)
	{
		os << obj[i] << " ";
	}
	os << "]";
	os << std::endl;
	return ( os );
}
