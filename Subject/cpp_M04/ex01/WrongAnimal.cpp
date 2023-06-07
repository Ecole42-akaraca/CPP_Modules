#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ){
	std::cout <<GREEN "--Animal Default Constructor Called--" END<< std::endl;
	this->type = "Default";
}

WrongAnimal::WrongAnimal( const WrongAnimal &ref ){
	std::cout <<GREEN "--Animal Copy Constructor Called--" END<< std::endl;
	*this = ref;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &ref ){
	std::cout <<GREEN "--Animal Copy Assignment Operator Called--" END<< std::endl;
	if (this != &ref )
	{
		this->type = ref.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void ){
	std::cout <<GREEN "--Animal Destructor Called--" END<< std::endl;
}

void WrongAnimal::makeSound( void ) const{
	std::cout << "...(No Sound)..." << std::endl;
}

std::string WrongAnimal::getType( void ) const{
	
	return( this->type );
}

std::ostream &operator<<( std::ostream &os, const WrongAnimal &object ){

	os << object.getType();
	return (os);
}
