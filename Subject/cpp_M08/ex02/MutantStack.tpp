#include "MutantStack.hpp"

/*
template < typename T >
MutantStack<T>::MutantStack( void ) : std::stack<T>(){
	std::cout << "Default Constrcutor Called" << std::endl;
}

template < typename T >
MutantStack<T>::MutantStack( const MutantStack &ref ) : std::stack<T>(ref){
	std::cout << "Copy Constructor Called" << std::endl;
	*this = ref;
}

template < typename T >
MutantStack<T>::~MutantStack( void ){
	std::cout << "Destructor Called" << std::endl;
}

template < typename T >
MutantStack<T> &MutantStack<T>::operator=( const MutantStack &ref ){
	std::cout << "Copy Assignment Operator Called" << std::endl;
	std::stack<T>::operator=(ref);
	return (*this);
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin( void ){
	return ( this->c.begin() );
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end( void ){
	return ( this->c.end() );
}
*/
