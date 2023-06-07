#include "Fixed.hpp"

Fixed::Fixed( void ){

	this->fixNumber = 0; // Üye değişkenleri 0, NULL, vb. olarak başlatılmalıdır.
	std::cout << "Default constructor called" << std::endl;	
}

// Argüman olarak başka bir örneğe referans alır ve referansı kullanarak kendi örneğini başlatır.
// Mevcut değer kopyalanıp iletildiği için const olarak bildirilir (değer değiştirilmemelidir)
Fixed::Fixed(  const Fixed &ref ){

	std::cout << "Copy constructor called" << std::endl;   
	// this->fixNumber = ref.getRawBits(); // tek üye eşitleniyor.
	*this = ref; // copy constructor çalışıyor. // eşitleme işleminde adresler farklıdır. // tüm üyeler için geçerli
}

Fixed& Fixed::operator=( const Fixed &ref ){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref) // Kendine atamayı engellemek için kullanılıyor. // Makefile flaglarini kapatılması gerekiyor // Fixed a; a = a;
	{
		this->fixNumber = ref.getRawBits();
	}
	return (*(this));
}

Fixed::~Fixed( void ){

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixNumber);
}

void Fixed::setRawBits( int const raw ){

	this->fixNumber = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
