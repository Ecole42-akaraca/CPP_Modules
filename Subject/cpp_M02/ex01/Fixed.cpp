#include "Fixed.hpp"

Fixed::Fixed( void ){

	std::cout << "Default constructor called" << std::endl;	
	this->fixNumber = 0;
}

Fixed::Fixed( const int integer ){

	std::cout << "Int constructor called" << std::endl;	
	// this->fixNumber = integer << fractionalBits;
	this->setRawBits( integer << fractionalBits );
}

Fixed::Fixed( const float floating ){

	std::cout << "Float constructor called" << std::endl;	
	this->fixNumber = roundf(floating * (1 << fractionalBits));
	// this->setRawBits( roundf(floating * (1 << fractionalBits)) );
}

Fixed::Fixed(  const Fixed &ref ){

	std::cout << "Copy constructor called" << std::endl;
	// this->setRawBits( ref.getRawBits() );
	// this->fixNumber = ref.getRawBits(); // tek üye eşitleniyor.
	*this = ref; // copy constructor çalışıyor. // eşitleme işleminde adresler farklıdır. // tüm üyeler için geçerli
}

Fixed& Fixed::operator=( const Fixed &ref ){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref) // Kendine atamayı engellemek için kullanılıyor. // Makefile flaglarini kapatılması gerekiyor // Fixed a; a = a;
	{
		//*this = ref; // bunu kullanamayız recursive fonk. durumuna giriyor ve sonsuz döngüye giriyor.
		this->fixNumber = ref.getRawBits();
		// this->setRawBits(ref.getRawBits());
		// printf("%p\n", &ref);
		// printf("%p\n", this);
	}
	return (*this);
}

Fixed::~Fixed( void ){

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{

	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixNumber);
}

void Fixed::setRawBits( int const raw ){

	// std::cout << "setRawBits member function called" << std::endl;
	this->fixNumber = raw;
}

float Fixed::toFloat( void ) const{

	// std::cout << "\ngelen değer: " << this->getRawBits() << std::endl; // 42.42f'in yuvarlanmamış değeri: 42.421875'dir, lakin cout'un standartı gereği otomatik olarak 6lık(genişlik- width) sayıya yuvarlıyor bu yüzden bu değer 42.4219'dur.
	// printf("\n->%f\n", (float)((float)this->getRawBits()/ 256.0)); // burada diğer bir örnek verilmiştir.
	return (static_cast<float>(this->getRawBits()) / (1 << fractionalBits)); // tip dönüşütürme var int -> float
}

int Fixed::toInt( void ) const{

	// return (this->getRawBits() >> fractionalBits);
	return (this->fixNumber >> fractionalBits);
}

std::ostream &operator<<( std::ostream & os, const Fixed & i){

	os << i.toFloat();
	return (os);
}
