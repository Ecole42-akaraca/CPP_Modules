#include "Dog.hpp"

Dog::Dog( void ): Animal(){

	std::cout <<GREEN "--Dog Default Constructor Called--" END<< std::endl;
	this->type = "Dog";
}

Dog::Dog( const Dog &ref ): Animal( ref ) {

	std::cout <<GREEN "--Dog Copy Constructor Called--" END<< std::endl;
	*this = ref;
}

Dog &Dog::operator=( const Dog &ref ){

	std::cout <<GREEN "--Dog Copy Assignment Constructor Called--" END<< std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

Dog::~Dog( void ){
	
	std::cout <<GREEN "--Dog Destructor Called--" END<< std::endl;
}

void	Dog::makeSound( void ) const{

	std::cout <<RED "Woof Woof!" END<< std::endl;
}
