#include "Fixed.hpp"

Fixed::Fixed( void ){

	// std::cout << "Default constructor called" << std::endl;
	this->fixNumber = 0;
}

Fixed::Fixed( const int integer ){

	// std::cout << "Int constructor called" << std::endl;
	this->fixNumber = integer << fractionalBits;
}

Fixed::Fixed( const float floating ){

	// std::cout << "Float constructor called" << std::endl;
	this->fixNumber = roundf(floating * (1 << fractionalBits));
}

Fixed::Fixed( const Fixed &ref ){

	// std::cout << "Copy constructor called" << std::endl;
	this->fixNumber = ref.getRawBits();
	// *this = ref;
}

Fixed& Fixed::operator=( const Fixed &ref ){

	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		// this->fixNumber = ref.getRawBits();
		this->setRawBits(ref.getRawBits());
	}
	return (*this);
}

Fixed::~Fixed( void ){

	// std::cout << "Destructor called" << std::endl;
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

	return (static_cast<float>(this->getRawBits()) / (1 << fractionalBits));
}

int Fixed::toInt( void ) const{

	return (this->fixNumber >> fractionalBits);
}

/*_________________ARITHMETIC OPERATORS__________________*/
/**
Sol taraftaki nesne, bu operatörde değiştirilmediği için bir referans olarak geçirilmesine gerek yoktur ve yeni bir sabit noktalı sayı olarak döndürülmelidir.
*/
Fixed Fixed::operator+( const Fixed &ref ){ // soldaki nesne const olmamalı, sağdaki nesne const olabilir veya olmayabilir.

	Fixed tmp(this->toFloat() + ref.toFloat()); // referansı alınan nesnede değişiklik istenilmediğinden dolayı yeni bir nesne oluşturuluyor.
	return (tmp);
}

Fixed Fixed::operator-( const Fixed &ref ){

	Fixed tmp(this->toFloat() - ref.toFloat());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &ref)
{
	Fixed tmp(this->toFloat() * ref.toFloat());
	return (tmp);
}

Fixed Fixed::operator/( const Fixed &ref ){

	Fixed tmp(this->toFloat() / ref.toFloat());
	return (tmp);

}
/*_______________________________________________________*/

/*_____________INCREMENT/DECREMENT OPERATORS_____________*/
/**
Geçici nesnenin bir kopyasını oluşturduğumuz için, nesnenin eski değeri için bir referans döndürmek zorunda değiliz.
Bundan dolayı & işaretini kullanmaya gerek yok.
*/
Fixed	Fixed::operator++( int ){

	Fixed ref(*this); // nesne değerini daha sonrasında arttırmak istediğimizden dolayı nesnenin kopyasını oluşturup döndürüyoruz.

	++(*this); // void ++ operatörünü çağırıyor.
	return (ref);
}

/*
Operatör, nesne örneği üzerinde çağrıldığında, önce nesne örneğinin değeri artırılır ve ardından artırılmış değer döndürülür. Bu nedenle, operatörün çağrıldığı ifade içinde kullanılmak üzere bir referans döndürülmesi gerekir.
*/
Fixed	&Fixed::operator++( void ){

	this->fixNumber++;
	return (*this);
}

Fixed Fixed::operator--( int ){

	Fixed ref(*this);

	--(*this);
	return (ref);
}

Fixed	&Fixed::operator--( void ){

	this->fixNumber--;
	return (*this);
}
/*_______________________________________________________*/

/*_________________COMPARISON OPERATORS__________________*/
bool Fixed::operator!=( const Fixed &ref) const{

	return (this->fixNumber != ref.fixNumber);
}

bool Fixed::operator==( const Fixed &ref) const{

	return (this->fixNumber == ref.fixNumber);
}

bool Fixed::operator<=( const Fixed &ref) const{

	return (this->fixNumber <= ref.fixNumber);
}

bool Fixed::operator>=( const Fixed &ref) const{

	return (this->fixNumber >= ref.fixNumber);
}

bool Fixed::operator>( const Fixed &ref) const{

	return (this->fixNumber > ref.fixNumber);
}

bool Fixed::operator<( const Fixed &ref) const{

	return (this->fixNumber < ref.fixNumber);
}
/*_______________________________________________________*/

/*
	Fixed max = Fixed::max(a, Fixed(3.9f) );
	Fixed x(Fixed::max( Fixed(1.0f), Fixed(3.0f) ));
*/
const Fixed &Fixed::max( const Fixed &lref, const Fixed &rref ){

	if (lref.getRawBits() > rref.getRawBits())
		return (lref);
	return (rref);
}

/*
	Fixed l(3);
	Fixed k(5);
	Fixed& max_fixed = Fixed::max(l, k);

Yapı max içinde Fixed(4.f), şeklinde oluşturulursa const olarak atanıyor, bu yüzden bu fonk. uygun değil.
*/
Fixed &Fixed::max( Fixed &lref, Fixed &rref ){

	if (lref.getRawBits() > rref.getRawBits())
		return (lref);
	return (rref);
}

const Fixed &Fixed::min( const Fixed &lref, const Fixed &rref ){

	if (lref.getRawBits() < rref.getRawBits())
		return (lref);
	return (rref);
}

Fixed &Fixed::min( Fixed &lref, Fixed &rref ){

	if (lref.getRawBits() < rref.getRawBits())
		return (lref);
	return (rref);
}

std::ostream &operator<<( std::ostream & os, const Fixed & i){

	os << i.toFloat();
	return (os);
}
