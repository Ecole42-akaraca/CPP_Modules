#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include "iostream"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

class Animal{

/*
	Temel sınıftan türetilen sınıflarında erişmesini istediğimiz değişkenleri protected olarak tanımlıyoruz.
	Bunun nedeni, sınıflara ait olmayan ortamda(fonksiyonlarda) bu değişkenlere erişilmesini istemiyoruz.
	Bu yüzden, dış ortamda type değişkenini getirmek için getType() fonksiyonu oluşturuyoruz. 
*/
protected:
	std::string type;

public:
	Animal( void ); // default constructor
	Animal( const Animal &ref ); // copy constructor.
	Animal	&operator=( const Animal &ref ); // copy assignment operator overload.
	virtual ~Animal( void ); // destructor.

	/*
		Constructor ve destructor haricinde public olan fonksiyonlar const tipinde olmalıdır.
		Sınıfın değişkenlerini korumak için bu şekilde kullanılmalıdır.

		makeSound() fonksiyonun virtual olmasının nedeni,
			Animal sınfından türetilmiş olan sınıflarda da aynı tür fonksiyon bulunduğundan dolayıdır.
			Eğerki virtual olarak kullanılmaz ise, oluşturulan türetilmiş sınıf, temel sınıfa kopyalandığı(tip dönüşümü yapıldığı) zaman,
			temel sınıfın fonksiyonlarını kullanmaktadır.

		Bu yapıyı virtual yapmak, polymorphism(çok şekillilik) örneğidir.

	Tablo gösterimi:

		Animal Tablosu:
			-------------------------
			| .type					|
			| .Virtual makeSound	|	-> makeSound sanallaştırılınca derleyici tablo içerisine bir pointer yerleştiriyor.
			| .						|
			| .						|
			| *vprt					|	-> Oluşturulan pointer *vptr olarak tanımlanıyor yani sanal fonksiyon tablosu oluşturduğu anlamına geliyor.
			-------------------------
								^
								|
		Cat Tablosu:			|
			-------------------------
			| .makeSound			|
			| .						|
			| .						|
			| .						|
			-------------------------

		Animal sınıfındaki makeSound ramde "A" olarak tutulsun, Cat sınıfındaki ise "B" olarak tutulsun.

		*vptr Tablosu:
			-------------------------
			| A <- Animal			|
			| B <- Cat 				|
			| .						|
			| .						|
			-------------------------
		Derleyici bu vptr sayesinde hangi sınıftan hangi methodun çağırılacağını karar vermek için bu işlemi gerçekleştiriyor.
		https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
	*/
	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;

};

std::ostream &operator<<( std::ostream & os, const Animal &object );

#endif
