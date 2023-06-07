#ifndef DOG_HPP
 #define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

public:
	Dog( void );
	Dog( const Dog &ref );
	Dog &operator=( const Dog &ref );
	~Dog( void );

	/*
		Dog sınıfı içinde oluşturuduğumuz makeSound fonksiyonu sonucunda override işlemini yapmış oluyoruz.
	*/
	void	makeSound( void ) const; //override
};

#endif