#include "Span.hpp"

Span::Span( void ) : _n(0){
	std::cout << "Default Constructor Called" << std::endl;
}

Span::Span( unsigned int N ) : _n(N){
	std::cout << "Constructor Called" << std::endl;
}

Span::Span( const Span &ref ){
	*this = ref;
}

Span::~Span( void ){
	std::cout << "Destructor Called" << std::endl;
}

Span &Span::operator=( const Span &ref ){
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		this->_list = ref._list;
		this->_n = ref._n;
	}
	return (*this);
}

void Span::addNumber( unsigned int N ){

	try
	{
		if (this->_list.size() >= this->_n)
			throw ( ArrayIsFull() );
		this->_list.push_back(N);
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << "\n";
	}
}

int	Span::shortestSpan( void ){
	try
	{
		if (this->_list.size() < 2)
			throw ( std::out_of_range("List arguments is to low!") );
		int min, diff = (*std::max_element(this->_list.begin(), this->_list.end()) - *std::min_element(this->_list.begin(), this->_list.end()));
		for ( std::list<int>::const_iterator i = this->getList()->begin(); i != this->getList()->end(); ++i )
		{
			if (std::next(i) != this->getList()->end())
			{
				diff = abs(*std::next(i) - *i);
				std::cout << "next: " << *std::next(i) << " before: " << *i << "\n";
			}
			if (diff < min)
				min = diff;
		}
		return (min);
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}

int Span::longestSpan( void ){
	try
	{
		if (this->_list.size() < 2)
			throw ( std::out_of_range("List arguments is to low!") );
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << "\n";
	}
	return (*std::max_element(this->_list.begin(), this->_list.end()) - *std::min_element(this->_list.begin(), this->_list.end()));
}

const std::list<int>* Span::getList( void ) const{
	return (&this->_list);
}

const char* Span::OutOfBoundsException::what() const throw(){
	return ( "Index is out of bounds!" );
}

const char* Span::ArrayIsFull::what() const throw(){
	return ( "Array is Full!" );
}

std::ostream &operator<<( std::ostream &os, const Span &obj ){

	os << "[ ";
	for ( std::list<int>::const_iterator i = obj.getList()->begin(); i != obj.getList()->end(); ++i )
	{
		os << *i;
		if (std::next(i) != obj.getList()->end())
			os << " ";
	}
	os << " ]";
	return (os);
}
