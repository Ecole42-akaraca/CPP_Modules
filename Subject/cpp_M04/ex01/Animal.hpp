#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

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

protected:
	std::string type;

public:
	Animal( void ); // default constructor
	Animal( const Animal &ref ); // copy constructor.
	Animal	&operator=( const Animal &ref ); // copy assignment operator overload.
	/*
C++ programlama dilinde, bir sınıfın herhangi bir nesnesi oluşturulduğunda, sınıfın yapıcı (constructor) ve yıkıcı (destructor) fonksiyonları çağrılır.
Yapıcı fonksiyon, nesne oluşturulduğunda bellekteki yerini ayırır ve gerekli başlangıç değerlerini atar.
Yıkıcı fonksiyon ise nesne ömrü sona erdiğinde, bellekten ayrılması gereken kaynakları serbest bırakır.

Ancak, bir sınıfın sanal fonksiyonları varsa, sınıfın nesneleri türetilmiş sınıflar tarafından kullanılabilir.
Eğer türetilmiş sınıflarda sınıfın yıkıcı fonksiyonu sanal olarak tanımlanmazsa, türetilmiş sınıfların nesneleri bellekten silinirken, sadece türetilmiş sınıfların yıkıcı fonksiyonları çağrılır ve üst sınıfın yıkıcı fonksiyonu atlanır.
Bu durumda, üst sınıfın yıkıcı fonksiyonunda bellekten silinmesi gereken dinamik bellek alanları (heap) serbest bırakılmaz ve bellek sızıntısı (memory leak) oluşabilir.

Bu sorunu çözmek için, üst sınıfta sanal bir yıkıcı fonksiyon tanımlamak gerekiyor. Sanal yıkıcı fonksiyon, alt sınıfların yıkıcı fonksiyonlarının da çağrılmasını sağlar.
Böylece, alt sınıfların nesneleri bellekten silinirken, önce alt sınıfların yıkıcı fonksiyonları çağrılır, ardından üst sınıfın sanal yıkıcı fonksiyonu çağrılır ve böylece tüm bellek kaynakları serbest bırakılır.
Sanal yıkıcı fonksiyon tanımlamak için, üst sınıfın yıkıcı fonksiyonunu sanal olarak tanımlamak yeterlidir.
Bu, C++ dilindeki sanal fonksiyonlar konseptinin bir parçasıdır ve sanal fonksiyonlar için "virtual" anahtar kelimesi kullanılır. 



~Base() ifadesi bir yıkıcı (destructor) fonksiyonunu tanımlar ve bu fonksiyon, bir sınıfın nesnesi bellekten silinirken çağrılır.
virtual ~Base() ifadesi ise, ~Base() fonksiyonunu sanal olarak tanımlar.

Sanal fonksiyonlar, bir sınıf hiyerarşisinde türetilmiş sınıfların kullanımı için tasarlanmıştır.
Türetilmiş sınıfların bir üst sınıfın işlevlerini değiştirmesi veya geçersiz kılması gerektiğinde kullanılırlar.
Eğer bir üst sınıfın bir fonksiyonu sanal olarak tanımlanmazsa, türetilmiş sınıfların o fonksiyonu(kendi fonk.) kullanması mümkün olmaz.

Bir yıkıcı fonksiyonu sanal olarak tanımlamak, bir sınıf hiyerarşisindeki tüm türetilmiş sınıfların, kendi yıkıcı fonksiyonlarının yanı sıra üst sınıfın yıkıcı fonksiyonunun da çağrılmasını sağlar.
Bu şekilde, bellek sızıntısı gibi sorunlar önlenir ve tüm bellek kaynakları serbest bırakılır.

Özetle, ~Base() ifadesi yıkıcı fonksiyonu tanımlarken, virtual ~Base() ifadesi yıkıcı fonksiyonunun sanal olarak tanımlanmasını sağlar ve sınıf hiyerarşisindeki türetilmiş sınıfların yıkıcı fonksiyonlarının çağrılmasını garanti eder.


Kısaca: "delete "base class"" işleminde çocuktan itibaren destruct etmeye başlıyor.

Virtual olur ise çıktısı:
	Base constructor is called.
	Derived constructor is called.
	Derived destructor is called.
	Base destructor is called.

Virtual olmaz ise çıktısı:
	Base constructor is called.
	Derived constructor is called.
	Base destructor is called.

Derived -> türetilmiş

base class için delete kullandığımızda virtual yapıya sahip olmaz ise leak oluşturur.
Bunun nedeni heap'te new ile yer açtığımızdan dolayı delete işlemi ile freelenmesi gerekiyor.
Program kapanırken kendiliğinden temizlenmiyor.
!!!base class'a tip olarak atanmış bir türetilmiş sınıfı delete ile temizlerken, türetilmiş sınıftaki destrcutor yapısını çağırmak için base class'daki destructor virtual olmalıdır.

	*/
	// ~Animal( void ); // destructor.
	virtual ~Animal( void ); // virtual destructor.
	// virtual ~Animal( void ) = 0; // pure virtual destructor. // Temel(base) nesnenin doğrudan oluşturulmasını tamamen engellemek için kullanılır ???

	virtual void	makeSound( void ) const; 
	std::string		getType( void ) const;

	/*
		Saf bir sanal işlevin bildirimi bu biçimdedir ve sınıfta uygulanamaz, ancak miras alınan alt sınıfta uygulanır.
		"= 0;" olarak tanımlandığındığı zaman bir sanal sınıf, soyut sınıf(abstract class) olmaktadır.
		Bundan dolayı base class'tan türetilen her sınıfta bu soyut sınıftan bulunması gerekmektedir.
		Bu durum haricinde base class tipinde yeni bir nesne oluşturulamaz ve kendi tipine atanamaz.
		örn: "Animal A = new Animal();"  ve "Animal A;" şeklinde kullanılamaz.

		Bu yapı sayesinde türetilmiş olan sınıflarda mecburi olarak istediğimiz metotları belirleyebiliyoruz.
		Türetilmiş sınıflardan türetilen yeni sınıflarda olmak(tanımlanmış) zorunda değil(aşırı yüklenmiş), çünkü bir önceki sınıfında metot bulunmaktadır.
		"Animal -> Cat -> Hairless" şeklindeki bir kalıtımda Hariless sınıfında "Brain	&getBrain( void ) const;" bulundurulmak zorunda değil.
		Eğerki Hairless sınıfınada eklenirse(tanımlanırsa), method kullanıldığında kendi sınıfındaki methodu çağıracaktır.
		
		// virtual Brain	&getBrain( void ) const = 0; // "soyut sanal bir fonksiyon" veya "pure method" olarak adlandırılır.
	*/

};

std::ostream &operator<<( std::ostream & os, const Animal &object );

#endif
