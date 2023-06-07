#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include "Color.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <cctype>
#include <limits>

enum e_type{
	NONE, CHAR, INT, FLOAT, DOBULE, LITERALS
};

/*
	Bu class'ın subject'te "static class" olması istenmektedir.
	Static class örnek - nedir:
	C++ dilinde, bir sınıfın statik (static) bir sınıf olarak kabul edilmesi için aşağıdaki koşulların sağlanması gerekmektedir:
		-> Sınıfın tüm üyeleri (veri üyeleri ve işlev üyeleri) static olmalıdır: Bir sınıfın statik sınıf olarak kullanılabilmesi için, tüm üyeleri (veri üyeleri ve işlev üyeleri) static olarak tanımlanmalıdır.
		Static üyeler, sınıfın tüm nesneleri arasında paylaşılır ve nesne oluşturulmasına gerek kalmadan sınıf adıyla erişilebilir.
		
		-> Sınıfın hiçbir nesnesi oluşturulmamalıdır:
			Bir sınıfın statik sınıf olarak kullanılabilmesi için, hiçbir nesnesi oluşturulmamış olmalıdır.
			Statik sınıfın sadece static üyelerine erişim sağlanabilir ve nesne oluşturulması gereksizdir.
		
		-> Sınıfın inner (iç) sınıfı olmamalıdır:
			Bir sınıfın statik sınıf olarak kullanılabilmesi için, iç içe (nested) sınıf (inner class) içermemelidir. Statik sınıflar, iç içe sınıfların statik üyelerine erişebilir, ancak iç içe sınıflar statik sınıfın üyelerine erişemez.
------------------------------------------------------------------------------------------------------------------------------------------
	class MyClass {
	public:
		// Statik veri üyesi
		static int myStaticVariable;

		// Statik fonksiyon (sınıf düzeyinde fonksiyon)
		static void myStaticFunction() {
			// Fonksiyon kodu
		}

		// Diğer üye fonksiyonlar ve veri üyeleri
		// ...
	};

	// Statik veri üyesinin tanımlanması (bellek alanı ayrılması)
	int MyClass::myStaticVariable = 0; // C++ dilinde, static değişkenlere sınıf adı ve scope operatörü (::) kullanarak erişilebilir.
------------------------------------------------------------------------------------------------------------------------------------------
	C++ dilinde static class ifadesi doğrudan kullanılamaz(static class diye bir class tanımlaması yoktur), çünkü static sadece üye değişkenler ve üye fonksiyonlar için kullanılabilir, sınıfın kendisi için değil.
	MyClass adlı sınıf bir static class (statik sınıf) olarak kabul edilir.
	Çünkü MyClass sınıfında sadece static veri üyeleri (myStaticVariable) ve static üye fonksiyonlar (myStaticFunction) bulunmaktadır.
	Ayrıca, myStaticVariable adlı statik veri üyesi bellek alanı ayrılarak tanımlanmıştır, bu da statik sınıfların genel bir özelliğidir.
	Dolayısıyla, MyClass sınıfı bir static class (statik sınıf) olarak kabul edilir.

	Statik olmayan değişken ve method/fonksiyon tanımladığımız zaman bu sınıf, statik bir sınıf olmaktan çıkar.

	Subject bizden "Orthodox Canonical Form" kurallarına uymamızı istemektedir lakin statik bir class'da sınıfa ait hiçbir nesnenin oluşturulması istenilmemektedir.


	C++'da static değişkenler nasıl tanımlanır:
	(1) Sınıf içinde static veri üyesi olarak tanımlanabilir:
		-> Sınıf içinde, static anahtar kelimesi ile birlikte veri üyesi tanımlanabilir.
			Bu durumda, veri üyesi tüm sınıf nesneleri arasında paylaşılır ve sınıf adı ile erişilebilir.
------------------------------------------------------------------------------------------------------------------------------------------
	class MyClass {
	public:
		static int myStaticVar; // Static veri üyesi
		// ...
	};

	// Sınıf dışında static veri üyesi için bellek ayrımı yapılmalıdır
	int MyClass::myStaticVar = 0; // C++ dilinde, static değişkenlere sınıf adı ve scope operatörü (::) kullanarak erişilebilir.
------------------------------------------------------------------------------------------------------------------------------------------

	(2) Sınıf içinde static yerel (local) değişken olarak tanımlanabilir:
		-> Sınıf içinde, static anahtar kelimesi ile birlikte bir işlevin içinde yerel (local) değişken tanımlanabilir.
			Bu durumda, değişken sadece ilgili işlevde kullanılabilir ve sadece bir kez bellekte ayrılır.
------------------------------------------------------------------------------------------------------------------------------------------
	class MyClass {
	public:
		static void myStaticFunction() {
			static int myStaticVar; // Static yerel değişken
			// ...
		}
	};
------------------------------------------------------------------------------------------------------------------------------------------

	(3) Sınıf içinde static sabit (constant) veri üyesi olarak tanımlanabilir:
		-> Sınıf içinde, static anahtar kelimesi ile birlikte const anahtar kelimesi kullanılarak sabit (constant) veri üyesi tanımlanabilir.
			Bu durumda, sabit veri üyesi tüm sınıf nesneleri arasında paylaşılır ve sınıf adı ile erişilebilir.
------------------------------------------------------------------------------------------------------------------------------------------
	class MyClass {
	public:
		static const int myStaticConstVar = 42; // Static sabit veri üyesi
		// ...
	};
------------------------------------------------------------------------------------------------------------------------------------------

	!!!	Statik üye değişkenlerin tanımlamaları genellikle bir kaynak dosyasında (kod dosyası) yapılır.
		Tanımlamalar, ilgili sınıfın başlık dosyasına (kütüphane) yerleştirilirse, her dosya bu kütüphaneyi dahil ettiğinde aynı değişkenlerin birden fazla tanımı oluşabilir ve bu da hatalara yol açabilir.

		Bazı durumlarda statik üye değişkenlerin başlık dosyasında (kütüphane) doğrudan tanımlanması gerekebilir, özellikle derleme sürecinde her kaynak dosya için ayrı bir bellek ayrımı yapılmasını istemiyorsanız(C++11 inline kullanımı).

*/
class ScalarConverter{
	private:
		static std::string	_string;
		static e_type		_type;
		static int			_index;
		static int			_sign;
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;

	public:
		/* Getters & Setters */
			static std::string	getString( void );
			static char			getChar( void );
			static int			getInt( void );
			static float		getFloat( void );
			static double		getDouble( void );
			static int			getType( void );
			static void			setString( std::string string );
			static void			setType( void );

		/* Other */
			static bool			isChar();
			static bool			isInt();
			static bool			isFloat();
			static bool			isDouble();
			static bool			isLiterals();
		
			static void			printChar();
			static void			printInt();
			static void			printFloat();
			static void			printDouble();

		/* Main Member Functions */
			static void			ScalarConvertingString( std::string argv );

		/* Exceptions */
		class InvalidType : public std::exception{
			public:
				virtual const char *what(void) const throw(){
					return ( RED "Input is of invalid type!" END );
				}
		};
};

#endif
