#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::AMateria( const AMateria &ref ){
	
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = ref;
}

AMateria::AMateria( std::string const &type ){

	std::cout << "AMateria Constructor Called" << std::endl;
	this->type = type;
}

AMateria &AMateria::operator=( const AMateria &ref ){

	std::cout << "AMateria Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

AMateria::~AMateria(){
	std::cout << "AMateria Destructor Called" << std::endl;
}

std::string const &AMateria::getType() const{
	return (this->type);
}

// AMateria	*AMateria::clone() const{
// 	return ((AMateria*)this);
// }

void	AMateria::use( ICharacter &target ){

	if (this->type.compare("ice"))
	{
		std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	}
	else if (this->type.compare("cure"))
	{
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	}
}
