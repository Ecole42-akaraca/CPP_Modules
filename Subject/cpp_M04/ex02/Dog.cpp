#include "Dog.hpp"

Dog::Dog( void ): Animal(){

	std::cout <<GREEN "--Dog Default Constructor Called--" END<< std::endl;
	this->type = "Dog";
	this->brain = new Brain();
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
		// if(this->brain != nullptr) {
		// 	delete this->brain;
		// }
		this->brain = new Brain(*ref.brain);
	}
	return (*this);
}

Dog::~Dog( void ){
	
	std::cout <<GREEN "--Dog Destructor Called--" END<< std::endl;
	delete this->brain;
}

void	Dog::makeSound( void ) const{

	std::cout <<RED "Dog is barking" END<< std::endl;
}
