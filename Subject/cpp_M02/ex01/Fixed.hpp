#ifndef FIXED_HPP_
# define FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed{

private:
	int fixNumber;
	static const int fractionalBits = 8;

public:
	Fixed( void );
	Fixed( const int integer);
	Fixed( const float floating );
	Fixed( const Fixed &ref );
	Fixed &operator=( const Fixed &ref );
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<( std::ostream & os, const Fixed & i );

#endif
