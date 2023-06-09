#include "Span.hpp"

Span::Span( void ) : _n(0){
	std::cout << "Default Constructor Called" << std::endl;
}

Span::Span( unsigned int N ) : _n(N){
	std::cout << "Constructor Called" << std::endl;
}

Span::Span( const Span &ref ){
	std::cout << "Copy Constructor Called" << std::endl;
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
		std::cerr << e.what() << std::endl;
	}
}

void Span::addNumber( std::list<int>::const_iterator begin, std::list<int>::const_iterator end ){

	try
	{
		if (std::distance(begin, end) > this->_n - this->getSize())
			throw ( std::runtime_error(RED "Other list size is to low!" END ) );
		this->_list.insert(this->_list.end(), begin, end);
	}
	catch ( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	Span::shortestSpan( void ){

	try
	{
		if (this->_list.size() < 2)
			throw ( std::runtime_error(RED "List arguments is to low!" END) );
		int min, diff = min = this->getMax() - this->getMin();
		for ( std::list<int>::const_iterator i = this->getList()->begin(); i != this->getList()->end(); ++i )
		{
			for ( std::list<int>::const_iterator l = this->getList()->begin(); l != this->getList()->end(); ++l )
			{
				if (l != i)
					diff = abs(*l - *i);
				if (diff < min)
					min = diff;
			}
		}
		return (min);
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

int Span::longestSpan( void ){

	try
	{
		if (this->_list.size() < 2)
			throw ( std::runtime_error(RED "List arguments is to low!" END) );
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << std::endl;;
	}
	return (this->getMax() - this->getMin());
}

const std::list<int>* Span::getList( void ) const{
	return (&this->_list);
}

int	Span::getSize( void ){
	return (this->_list.size());
}

int	Span::getMax( void ){
	return (*std::max_element(this->_list.begin(), this->_list.end()));
}

int	Span::getMin( void ){
	return (*std::min_element(this->_list.begin(), this->_list.end()));
}

const char* Span::OutOfBoundsException::what() const throw(){
	return ( RED "Index is out of bounds!" END );
}

const char* Span::ArrayIsFull::what() const throw(){
	return ( RED "Array is Full!" END );
}

std::ostream &operator<<( std::ostream &os, const Span &obj ){

	os << BLUE "[ ";
	for ( std::list<int>::const_iterator i = obj.getList()->begin(); i != obj.getList()->end(); ++i )
	{
		os << *i;
		if (std::next(i) != obj.getList()->end())
			os << ", ";
	}
	os << " ]" END;
	return (os);
}
