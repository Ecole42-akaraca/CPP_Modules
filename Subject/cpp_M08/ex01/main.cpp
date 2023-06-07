#include "Span.hpp"

/*
	---> C++ Templated containers, iterators, algorithms / Şablonlu konteynerlar, yineliyiciler, algoritmalar <---
	---> Span / Görünüm - Aralık (bellek aralığını temsil eden) <---
	Subject Çeviri:
		En fazla N tamsayı depolayabilen bir "Span sınıfı" geliştirin.
		N, işaretsiz(unsigned) bir int değişkendir ve yapıcıya iletilen tek parametre olacaktır.

		Bu sınıfın, Span'a tek bir sayı eklemek için addNumber() adlı bir üye işlevi olacaktır.
		Doldurmak için kullanılacaktır.
		Halihazırda depolanan N öğe varsa, yeni bir çğre eklemeye yönelik herhangi bir girişim bir istisna(exception) atmalıdır.

		Ardından, iki üye işlevi uygulayın:
			-> shortestSpan(); longestSpan();

		Depolanan tüm sayılar arasındaki en kısa aralığı veya en uzun aralığı (veya tercihen mesafeyi) döndürecektir.
		Depolanan numara yoksa veya yalnızca bir tane varsa, aralık bulunamaz, böylece bir istisna fırlatılır.

		Elbette kendi testlerinizi yazacaksınız ve bunlar aşağıdaki testlerden çok daha kapsamlı olacak.
		Span'ınızı en az 100000 sayı ile test edin. Daha fazlası daha da iyi olacaktır.
	
		Main.cpp:
---------------------------------------------------------------------------------------------------------------
			int main( void ){
				Span sp = Span(5);

				sp.addNumber(6);
				sp.addNumber(3);
				sp.addNumber(17);
				sp.addNumber(9);
				sp.addNumber(11);

				std::cout << sp.shortestSpan() << std::endl;
				std::cout << sp.longestSpan() << std::endl;

				return (0);
			}
---------------------------------------------------------------------------------------------------------------

		Output:
---------------------------------------------------------------------------------------------------------------
			$> ./ex01
				2
				14
			$>
---------------------------------------------------------------------------------------------------------------

		Son olarak, Span'ınızı bir dizi yineleyici kullanarak doldurmak harika olurdu.
		addNumber()'a binlerce arama yapmak çok sinir bozucu.
		Span'ınıza tek bir çağrıda çok sayıda numara eklemek için bir üye işlevi uygulayın.

		!!! Hiçbir fikriniz yoksa, Containers'ları inceleyin.
		!!! Bazı üye işlevleri, Containers'lara bir dizi öğe eklemek için bir dizi yineleyici alır.
Not:


*/
int main( void ){
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}
