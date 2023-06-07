#ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class WrongAnimal{

protected:
	std::string	type;

public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal &ref );
	WrongAnimal &operator=( const WrongAnimal &ref );
	virtual ~WrongAnimal( void );

	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;
};

std::ostream	&operator<<( std::ostream & os, const WrongAnimal & object );

#endif
