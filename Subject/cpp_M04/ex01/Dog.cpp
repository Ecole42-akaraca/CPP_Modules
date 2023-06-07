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
		this->type = ref.type; //shallow copy for string member //shallow copy örneği olmasına rağmen deep copy olarak işlem yapmaktadır.
		// std::cout << "type address" << &this->type << '\n';
		// std::cout << "ref type address" << &ref.type << '\n';
		// this->brain = ref.brain; //shallow copy for brain class
		// if(this->brain != nullptr) {
		// 	delete this->brain; //delete existing brain if any
		// }
		this->brain = new Brain(*ref.brain);  //deep copy for Brain pointer member
		// std::cout << "brain address" << this->brain << '\n';
		// std::cout << "ref brain address" << ref.brain << '\n';
	}
	return (*this);
}

Dog::~Dog( void ){
	
	std::cout <<GREEN "--Dog Destructor Called--" END<< std::endl;
	delete this->brain;
}

void	Dog::makeSound( void ) const{

	std::cout <<RED "Woof Woof!" END<< std::endl;
}

Brain	*Dog::getBrain( void ) const{
	return (this->brain);
}