/*
	.tpp dosyaları nedir?
		.tpp dosyaları, C++ dilinde header dosyalarındaki sınıf şablonlarının veya işlev şablonlarının tanımlarını içeren dosyalardır.
		Header dosyalarındaki şablon bildirimleri sadece tanımların yinelenmesiyle birlikte kullanılabilir ve bu nedenle .tpp dosyaları, tanımları sağlamak için kullanılır.

	.tpp dosyaları, genellikle .hpp dosyalarına #include edilir.
	Böylece, şablon kodları, tüm tanımların bulunduğu .tpp dosyalarından yüklenir ve ayrı olarak derlenir.
	Bu, derleme zamanını ve bağımlılıkları azaltır ve kodu daha düzenli hale getirir.
	Örneğin, bir sınıf şablonu olan "MyClass" için header dosyası "myclass.hpp" olabilir ve bu dosya "myclass.tpp" dosyasını da #include edebilir.
	MyClass'ın tanımları myclass.tpp dosyasında bulunur ve myclass.hpp dosyası, sadece şablon bildirimlerini içerir.
	Bu, MyClass'ı kullanmak isteyen diğer kodlar için daha net ve anlaşılır bir yapı sağlar.

	Örnek:
		Örneğin, example.hpp adında bir başlık dosyası ve bu başlık dosyasına ait example.tpp adında bir şablon dosyası olabilir.
		Bu dosyaların içerikleri şu şekilde olabilir:
			example.hpp:
-----------------------------------------------------------------------------------------------------------------------
				#ifndef EXAMPLE_HPP
				#define EXAMPLE_HPP

				#include <iostream>

				template<typename T>
				class Example {
				public:
					Example();
					Example(unsigned int size);
					Example(const Example& other);
					Example& operator=(const Example& other);
					~Example();
					T& operator[](unsigned int index);
					const T& operator[](unsigned int index) const;
					unsigned int size() const;
				private:
					unsigned int m_size;
					T* m_data;
				};

				#include "example.tpp"

				#endif // EXAMPLE_HPP
-----------------------------------------------------------------------------------------------------------------------

			example.tpp:
-----------------------------------------------------------------------------------------------------------------------
				template<typename T>
				Example<T>::Example() : m_size(0), m_data(nullptr) {}

				template<typename T>
				Example<T>::Example(unsigned int size) : m_size(size), m_data(new T[size]) {}

				template<typename T>
				Example<T>::Example(const Example& other) : m_size(other.m_size), m_data(new T[other.m_size]) {
					for (unsigned int i = 0; i < m_size; i++) {
						m_data[i] = other.m_data[i];
					}
				}

				template<typename T>
				Example<T>& Example<T>::operator=(const Example& other) {
					if (this != &other) {
						delete[] m_data;
						m_size = other.m_size;
						m_data = new T[m_size];
						for (unsigned int i = 0; i < m_size; i++) {
							m_data[i] = other.m_data[i];
						}
					}
					return *this;
				}

				template<typename T>
				Example<T>::~Example() {
					delete[] m_data;
				}

				template<typename T>
				T& Example<T>::operator[](unsigned int index) {
					if (index >= m_size) {
						throw std::out_of_range("Index out of range.");
					}
					return m_data[index];
				}

				template<typename T>
				const T& Example<T>::operator[](unsigned int index) const {
					if (index >= m_size) {
						throw std::out_of_range("Index out of range.");
					}
					return m_data[index];
				}

				template<typename T>
				unsigned int Example<T>::size() const {
					return m_size;
				}
-----------------------------------------------------------------------------------------------------------------------

*/
#ifndef ARRAY_TPP
  #define ARRAY_TPP

#include "Array.hpp"

template< typename T >
Array<T>::Array( void ) : _array(NULL), _size(0){
	std::cout << "Default Constructor Called" << std::endl;
}

template< typename T >
Array<T>::Array( unsigned int n ) : _array(new T[n]), _size(n){
	std::cout << "Constructor Called" << std::endl;
}

template< typename T >
Array<T>::Array( const Array &ref ) : _array(new T[ref._size]), _size(ref._size){
	std::cout << "Copy Constructor Called" << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = ref._array[i];
}

template< typename T >
Array<T>::Array( const T* elements, unsigned int size) : _array(new T[size]), _size(size){
	std::cout << "Array[] Constructor Called" << std::endl;
	for (unsigned int i = 0; i < size; i++)
		_array[i] = elements[i];
}

template< typename T >
Array<T>::~Array( void ){
	std::cout << "Destructor Called" << std::endl;
	delete[] _array;
}

template< typename T >
Array<T> &Array<T>::operator=( const Array &ref ){
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		delete[] this->_array;
		this->_array = new T[ref._size];
		this->_size = ref._size;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = ref._array[i];
	}
	return (*this);
}

template< typename T >
T &Array<T>::operator[]( unsigned int i ) const{
	if (i >= this->_size)
		throw ( OutOfBoundsException() );
	return (this->_array[i]);
}

template< typename T >
unsigned int Array<T>::getSize( void ){
	return (this->_size);
}

template< typename T >
const char *Array<T>::OutOfBoundsException::what() const throw(){
	return ( "Index is out of bounds!" );
}

template< typename T >
std::ostream &operator<<( std::ostream &os, Array<T> &obj ){
	os << "[ ";
	for (unsigned int i = 0; i < obj.getSize(); i++)
	{
		// if (obj[i]) // const char * ise bu kısım açık olmalı
			os << obj[i] << " ";
	}
	os << "]";
	os << std::endl;
	return ( os );
}

#endif
