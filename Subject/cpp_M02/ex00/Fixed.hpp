#ifndef FIXED_HPP_
# define FIXED_HPP_

#include <iostream>

class Fixed{

private:
	int fixNumber;
	static const int fractionalBits = 8;

public:
	Fixed( void ); // default constructor that initializes the fixed-point number value to 0.
	Fixed( const Fixed &ref ); // copy constructor.
	Fixed &operator=( const Fixed &ref ); // copy assignment operator overload.
	~Fixed(); // destructor.

	int getRawBits( void ) const; // that returns the raw value of the fixed-point value.
	void setRawBits( int const raw ); // that sets the raw value of the fixed-point number.
};

#endif
