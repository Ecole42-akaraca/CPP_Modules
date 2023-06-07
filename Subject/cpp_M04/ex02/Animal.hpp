#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

class Animal{

protected:
	std::string type;

public:
	Animal( void ); // default constructor
	Animal( const Animal &ref ); // copy constructor.
	Animal	&operator=( const Animal &ref ); // copy assignment operator overload.
	// ~Animal( void ); // destructor.
	virtual ~Animal( void ); // virtual destructor.
	// virtual ~Animal( void ) = 0; // pure virtual destructor.

	virtual void	makeSound( void ) const = 0; //pure virtual method
	std::string		getType( void ) const;

};

std::ostream &operator<<( std::ostream & os, const Animal &object );

#endif
