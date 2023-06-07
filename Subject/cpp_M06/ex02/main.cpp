#include "Base.hpp"

/*
	---> C++ casts <---
	---> Identify real type / Gerçek türü tanımlayın <---
	Subject Çeviri:
	
	Yasaklanmış fonksiyonlar: "std::typeinfo" 
		"#include <typeinfo>" yasaklı kütüphanedir.

	Yalnızca "genel bir sanal yok ediciye"(public virtual destructor) sahip bir temel sınıf(base class) uygulayın.	
	Base'den herkese açık olarak miras alan üç boş A, B ve C sınıfı oluşturun.

	Bu dört sınıfın "Ortodoks Kanonik Formunda" tasarlanması gerekmez.

	Aşağıdaki işlevleri uygulayın / Implement the following functions:

		-> Base *generate(void);
			: Rastgele, A, B veya C örneklerini oluşturur ve örneği "bir temel işaretçi"(base pointer) olarak döndürür.
			: Rastgele seçim uygulaması için istediğiniz herhangi bir şeyi kullanmaktan çekinmeyin.

		-> void identify(Base *p);
			: "p" ile işaret edilen nesnenin gerçek tipini yazdırır: "A", "B", "C"

		-> void identify(Base &p);
			: "p" ile işaret edilen nesnenin gerçek tipini yazdırır: "A", "B", "C".
			: Bu işlev içinde bir işaretçi(pointer) kullanmak yasaktır.

	"typeinfo" başlığının dahil edilmesi yasaktır. ?????
	
	Her şeyin beklendiği gibi çalıştığını test etmek için program yazınız.

Not:
	std::typeinfo nedir?
		Bir nesnenin türüne dair bilgi sağlar ve typeid operatörü ile kullanılır.
		std::typeinfo sınıfı aynı zamanda sanal işlev tablolarında (vtable) da kullanılır.
		Sanal işlevler, nesne yönelimli programlamada çoklu kalıtım ve dinamik bağlama özelliklerini sağlayan bir yapıdır.
		Her sanal işlev için bir sanal işlev tablosu oluşturulur ve bu tablo, sınıfın türü hakkında bilgi içerir.
		Sanal işlev tabloları, bellekte özel bir alanda saklanır ve tür bilgisi gibi diğer meta veriler de sanal işlev tabloları aracılığıyla elde edilebilir.

		std::typeinfo sınıfı, RTTI (runtime type information) mekanizmasının temel yapı taşıdır ve özellikle dinamik tür dönüşümlerinde ve istisna mekanizmasında kullanılır.

	Kullanım örneği:
---------------------------------------------------------------------------------------------------------------
		#include <iostream>
		#include <typeinfo>

		int main() {
		int x = 42;
		const std::type_info& type = typeid(x);  // type_info nesnesi oluşturuluyor
		std::cout << "x'in türü: " << type.name() << std::endl;  // tür bilgisi yazdırılıyor
		return 0;
		}
---------------------------------------------------------------------------------------------------------------
		Çıktı:
			x'in türü: i

	Bu projede dynamic_cast ve try-cath bloğunun kullanılması gerekmektedir.

*/
Base*	generate(){
	try
	{
		srand(time(NULL));

		int random = rand() % 3;
		if (random == 0)
			return new A();
		else if (random == 1)
			return new B();
		else
			return new C();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
		return (NULL);
	}
}

void	identify( Base *p ){

	if (dynamic_cast<A*>(p))
		A::print();
	else if (dynamic_cast<B*>(p))
		B::print();
	else if (dynamic_cast<C*>(p))
		C::print();
	else
		std::cout << "unkown type" << std::endl;

	// if ( typeid(*p) == typeid(A) )
	// 	std::cout << "A" << std::endl;
}

void	identify( Base &p ){

	try
	{
		dynamic_cast<A&>(p).print();
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p).print();
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p).print();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	// A dp1 = dynamic_cast<A&>(p);
	// // // dp1.print();

	// if ( typeid(p) == typeid(A) )
	// 	std::cout << "A" << std::endl;
}

int main()
{
	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);

	Base a;
	Base *b = NULL;
	identify(a);
	identify(b);
	delete ptr;
	return (0);
}
