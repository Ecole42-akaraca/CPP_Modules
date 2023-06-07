#include "Cat.hpp"

Cat::Cat( void ): Animal(){

	std::cout <<GREEN "--Cat Default Constructor Called--" END<< std::endl;
	this->type = "Cat";
	this->brain = new Brain();
} 

Cat::Cat( const Cat &ref ): Animal( ref ){

	std::cout <<GREEN "--Cat Copy Constructor Called--" END<< std::endl;
	*this = ref;
}

Cat &Cat::operator=( const Cat &ref ){

	std::cout <<GREEN "--Cat Copy Assignment Constructor Called--" END<< std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
		// if(this->brain != nullptr){
		// 	delete this->brain;
		// }
		this->brain = new Brain(*ref.brain);
	}
	return (*this);
}

Cat::~Cat( void ){
	
	std::cout <<GREEN "--Cat Destructor Called--" END<< std::endl;
	delete this->brain;
}

void	Cat::makeSound( void ) const{

	std::cout <<RED "Cats Say: MEOW!" END<< std::endl;
}
