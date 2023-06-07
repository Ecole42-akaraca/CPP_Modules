#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal(){
	std::cout <<GREEN "--Cat Default Constructor Called--" END<< std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

WrongCat::WrongCat( const WrongCat &ref ): WrongAnimal( ref ){
	std::cout <<GREEN "--Cat Copy Constructor Called--" END<< std::endl;
	*this = ref;
}

WrongCat &WrongCat::operator=( const WrongCat &ref ){
	std::cout <<GREEN "--Cat Copy Assignment Constructor Called--" END<< std::endl;
	if(this != &ref ){
		this->type = ref.type;
		this->brain = ref.brain;
	}
	return (*this);
}

WrongCat::~WrongCat( void ){
	std::cout <<GREEN "--Cat Destructor Called--" END<< std::endl;
	delete this->brain;
}

void	WrongCat::makeSound( void ) const{

	std::cout << "...Meow!..." << std::endl;
}

Brain	*WrongCat::getBrain( void ) const{
	return (this->brain);
}
