#ifndef FIXED_HPP_
# define FIXED_HPP_

#include <iostream>
#include <cmath>

/**
https://stackoverflow.com/questions/26172754/call-to-non-static-member-function-without-an-object-argument
https://en.cppreference.com/w/cpp/language/operators
https://learn.microsoft.com/tr-tr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
 **/
class Fixed{

private:
	int fixNumber;
	static const int fractionalBits = 8;

public:
	Fixed( void );
	Fixed( const int integer );
	Fixed( const float floating );
	Fixed( const Fixed &ref );
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed &operator=( const Fixed &ref );

/*_________________ARITHMETIC OPERATORS__________________*/
	Fixed operator+( const Fixed &ref );
	Fixed operator-( const Fixed &ref );
	Fixed operator*( const Fixed &ref );
	Fixed operator/( const Fixed &ref );

/*_____________INCREMENT/DECREMENT OPERATORS_____________*/
	Fixed operator++( int );
	Fixed &operator++( void );
	Fixed operator--( int );
	Fixed &operator--( void );

/*_________________COMPARISON OPERATORS__________________*/
	bool operator!=( const Fixed &ref ) const;
	bool operator==( const Fixed &ref ) const;
	bool operator<=( const Fixed &ref ) const;
	bool operator>=( const Fixed &ref ) const;
	bool operator>( const Fixed &ref ) const;
	bool operator<( const Fixed &ref ) const;
/*_______________________________________________________*/

/*
static anahtar sözcüğü, işlevin, sınıfın belirli bir örneği yerine sınıfın kendisiyle ilişkilendirildiği anlamına gelir.
Bu, önce sınıfın bir nesnesini yaratmadan işlevi çağırabileceğiniz anlamına gelir.
örn: std::cout << Fixed::max(a, b) << std::endl;

const anahtar sözcüğü, işlevin sınıf üyelerinden hiçbirini değiştirmediği anlamına gelir.

const olmayan bir Fixed'a bir başvuru döndürdüyse, bu Fixed nesnesini referans aracılığıyla değiştirebilirsiniz.
Bir const referansı döndürerek, referans aracılığıyla nesnenin yanlışlıkla değiştirilmesini önlersiniz.

Bu durumda static const kullanmak, kodu daha güvenli ve daha verimli hale getiren iyi bir programlama uygulamasıdır.
*/
	static const Fixed &max( const Fixed &lref, const Fixed &rref );
	static Fixed &max( Fixed &lref, Fixed &rref );
	static const Fixed &min( const Fixed &lref, const Fixed &rref );
	static Fixed &min( Fixed &lref, Fixed &rref );
};

std::ostream &operator<<( std::ostream & os, const Fixed & i );

#endif
