#include "Animal.hpp"

Animal::Animal( void ){

	std::cout <<GREEN "--Animal Default Constructor Called--" END<< std::endl;

	this->type = "Default";
}

Animal::Animal( const Animal &ref ){

	std::cout <<GREEN "--Animal Copy Constructor Called--" END<< std::endl;
	*this = ref;
}

Animal &Animal::operator=( const Animal &ref ){

	std::cout <<GREEN "--Animal Copy Assignment Operator Called--" END<< std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

Animal::~Animal( void ){

	std::cout <<GREEN "--Animal Destructor Called--" END<< std::endl;
}

std::string	Animal::getType( void ) const{

	return (this->type);
}

std::ostream &operator<<( std::ostream &os, const Animal &object){

	os << object.getType();
	return (os);
}
