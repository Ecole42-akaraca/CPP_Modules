#include "Ice.hpp"

Ice::Ice() : AMateria( "ice" ){
	std::cout << "Ice Default Constructor Called" << std::endl;
	// this->type = "ice";
}

Ice::Ice( const Ice &ref ) : AMateria( "ice" ){
	std::cout << "Ice Copy Constructor Called" << std::endl;
	*this = ref;
}

Ice &Ice::operator=( const Ice &ref ){
	std::cout << "Ice Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

Ice::~Ice(){
	std::cout << "Ice Destructor Called" << std::endl;
}

AMateria	*Ice::clone( void ) const{
	return (new Ice(*this));
}

void		Ice::use( ICharacter &ref ){
	std::cout << "* shoots an ice bolt at " << ref.getName() << " *" << std::endl;
}
