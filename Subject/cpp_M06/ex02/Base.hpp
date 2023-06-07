#ifndef BASE_HPP
 #define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base{
	public:
		virtual ~Base( void ) {
			std::cout << "Base Class Destructor Called" << std::endl;
		};
};

class A : public Base {
	public:
		// ~A( void ){ std::cout << "A Class Destructor Callled" << std::endl; };
		static void print(){
			std::cout << "Class Type is A" << std::endl;
		};
};

class B : public Base {
	public:
		// ~B( void ){ std::cout << "B Class Destructor Callled" << std::endl; };
		static void print(){
			std::cout << "Class Type is B" << std::endl;
		};
};

class C : public Base {
	public:
		// ~C( void ){ std::cout << "C Class Destructor Callled" << std::endl; };
		static void print(){
			std::cout << "Class Type is C" << std::endl;
		};
};

#endif
