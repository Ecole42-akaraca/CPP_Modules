#ifndef ARRAY_HPP
 #define ARRAY_HPP

#include <iostream>

template< typename T >
class Array{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array &ref );
		Array( const T* elements, unsigned int size ); // ekstra fonksiyon
		~Array( void );

		Array &operator=( const Array &ref );
		T &operator[]( unsigned int i ) const;

		unsigned int getSize( void );

		class OutOfBoundsException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

template< typename T >
std::ostream &operator<<( std::ostream &os, Array<T> &obj );

#include "Array.tpp" // .hpp dosyasına .tpp dosyasının include edilmesi gerekiyor.

//------------------------------------------[ .TPP dosyası oluşturmak yerine tüm kod bloğunu header'de yazarsak daha okunur olur. ]---------------------------------------------------------//

// template< typename T >
// class Array{
// 	private:
// 		T*				_array;
// 		unsigned int	_size;

// 	public:
// 		Array( void ) : _array(NULL), _size(0){ std::cout << "Default Constructor Called" << std::endl; }
// 		Array( unsigned int n ) : _array(new T[n]), _size(n){ std::cout << "Constructor Called" << std::endl; }
// 		Array( const Array &ref ) : _array(new T[ref._size]), _size(ref._size){
// 			std::cout << "Copy Constructor Called" << std::endl;
// 			for (unsigned int i = 0; i < this->_size; i++)
// 				this->_array[i] = ref._array[i];
// 		}
//		Array( const T* elements, unsigned int size) : _array(new T[size]), _size(size){
// 			std::cout << "Array[] Constructor Called" << std::endl;
// 			for (unsigned int i = 0; i < size; i++)
// 				_array[i] = elements[i];
//		}
// 		~Array( void ){ std::cout << "Destructor Called" << std::endl; delete[] _array; }

// 		Array &operator=( const Array &ref ){
// 			std::cout << "Copy Assignment Operator Called" << std::endl;
// 			if (this != &ref)
// 			{
// 				delete[] this->_array;
// 				this->_array = new T[ref._size];
// 				this->_size = ref._size;
// 				for (unsigned int i = 0; i < this->_size; i++)
// 					this->_array[i] = ref._array[i];
// 			}
// 			return (*this);
// 		}

// 		T &operator[]( unsigned int i ) const {
// 			if (i >= this->_size)
// 				throw ( OutOfBoundsException() );
// 			return (this->_array[i]);
// 		}

// 		unsigned int getSize( void ){ return (this->_size); }

// 		class OutOfBoundsException : public std::exception{
// 			public:
// 				virtual const char *what() const throw() { return ( "Index is out of bounds!" ); }
// 		};
// };

// template< typename T >
// std::ostream &operator<<( std::ostream &os, Array<T> &obj ){
// 	os << "[ ";
// 	for (unsigned int i = 0; i < obj.getSize(); i++)
// 	{
// 		os << obj[i] << " ";
// 	}
// 	os << "]";
// 	os << std::endl;
// 	return (os);
// }

#endif
