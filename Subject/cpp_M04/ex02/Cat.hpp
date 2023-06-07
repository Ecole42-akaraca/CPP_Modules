#ifndef CAT_HPP
 #define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

private:
	Brain		*brain;

public:
	Cat( void );
	Cat( const Cat &ref );
	Cat &operator=( const Cat &ref );
	~Cat( void );

	void	makeSound( void ) const;
};

#endif