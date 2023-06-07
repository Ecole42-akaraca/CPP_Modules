#ifndef ITER_HPP // önişlemci yönergesi ile birden fazla kez tanımlanmasını önleme
 #define ITER_HPP

#include <iostream>

//"void	print( T const &element )" şeklinde olursa, print fonk. çağırırken print<int>, print<double>, print<Awesome> ... şeklinde kullanılmalıdır.
template< typename T >
void	print( T &element ){
	std::cout << element << std::endl;
}

// arr'in uzunluğunu bulamadığım için len'in fazla girilme durumunu kontrol edemiyorum. Bu yüzden seg. fault hatası verebiliyor.
template< typename T >
void	iter( T* arr, int len, void (*func)(T&) ){
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

//---------------------------------------------------------------------------------------------------------------------------------------------//

// begin ve end ile nasıl kullanabiliriz. Burada da arrayin uzunluğunu bulamıyoruz, dışarıdan almak zorundayız.
// template< typename T >
// void	iter( T* arr, int len, void (*func)(T&) ){
// 	T* begin = arr;
// 	T* end = arr + len;

// 	for (T* iter = begin; iter != end; ++iter)
// 		func(*iter);
// }

//---------------------------------------------------------------------------------------------------------------------------------------------//

// class Awesome{
// 	private:
// 		int	_n;

// 	public:
// 		Awesome( void ): _n(42) { return; }
// 		int	get( void ) const { return (this->_n); }
// };

// std::ostream &operator<<( std::ostream &os, const Awesome &obj ) { os << obj.get(); return (os); };

// template< typename T >
// void print( T const &x ) { std::cout << x << std::endl; return; }

#endif
