#ifndef WHATEVER_HPP
 #define WHATEVER_HPP

#include <iostream>

template<typename T> // Şablonda birden fazla tür alınabilir ve kullanılabilir, yeni eklenecek türün nasıl kullandıldığına göre değişir.
// typename hem classlar hem de diğer türler için kullanılabilir.

void swap( T& a, T& b ){
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>

T min( T a, T b ){
	return ( (a < b) ? a : b );
}

template<typename T>

T max( T a, T b ){
	return ( (a > b) ? a : b );
}

// class Awesome{
// 	private:
// 		int	_n;

// 	public:
// 		Awesome( void ) : _n(0) {}
// 		Awesome( int n ) : _n(n) {}
// 		Awesome& operator=( Awesome &a ) { _n = a._n; return (*this); }
		
// 		bool operator==( Awesome const &rhs ) const { return (this->_n == rhs._n); }
// 		bool operator!=( Awesome const &rhs ) const { return (this->_n != rhs._n); }
// 		bool operator>( Awesome const &rhs ) const { return (this->_n > rhs._n); }
// 		bool operator<( Awesome const &rhs ) const { return (this->_n < rhs._n); }
// 		bool operator>=( Awesome const &rhs ) const { return (this->_n >= rhs._n); }
// 		bool operator<=( Awesome const &rhs ) const { return (this->_n <= rhs._n); }

// 		int	get_n( void ) const { return (_n); }

// };

// std::ostream &operator<<( std::ostream &os, const Awesome &obj ){ os << obj.get_n(); return (os); };

#endif
