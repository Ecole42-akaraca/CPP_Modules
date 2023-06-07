#ifndef CAT_HPP
 #define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat( void );
	Cat( const Cat &ref );
	Cat &operator=( const Cat &ref );
	~Cat( void );

	/*
		Cat sınıfı içinde oluşturuduğumuz makeSound fonksiyonu sonucunda override işlemini yapmış oluyoruz.
	*/
	void	makeSound( void ) const; //override
};

#endif