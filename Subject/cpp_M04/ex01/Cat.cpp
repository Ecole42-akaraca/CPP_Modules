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

Cat::~Cat( void ){
	
	std::cout <<GREEN "--Cat Destructor Called--" END<< std::endl;
	delete this->brain;
}

void	Cat::makeSound( void ) const{

	std::cout <<RED "MeoW!" END<< std::endl;
}

Brain	*Cat::getBrain( void ) const{
	return (this->brain);
}
