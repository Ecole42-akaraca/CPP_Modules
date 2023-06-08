#include "Span.hpp"

/*
	---> C++ Templated containers, iterators, algorithms / Şablonlu konteynerlar, yineliyiciler, algoritmalar <---
	---> Span / Görünüm - Aralık (bellek aralığını temsil eden) <---
	Subject Çeviri:
		En fazla N tamsayı depolayabilen bir "Span sınıfı" geliştirin.
		N, işaretsiz(unsigned) bir int değişkendir ve yapıcıya iletilen tek parametre olacaktır.

		Bu sınıfın, Span'a tek bir sayı eklemek için addNumber() adlı bir üye işlevi olacaktır.
		Doldurmak için kullanılacaktır.
		Halihazırda depolanan N öğe varsa, yeni bir öğe eklemeye yönelik herhangi bir girişim bir istisna(exception) atmalıdır.

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
	N değişkeni, span classının alabileceği değerlerin dizi boyutunu belirliyor.
	shortestSpan() methodu, girilen değerlerin arasındaki en kısa/küçük değeri döndürüyor. (örn: 11 - 9 = 2)
	longestSpan() methodu, girilen değerlerin arasındaki en uzun/büyük değeri döndürüyor. (örn: 17 - 3 = 14)
	addNumber( <element> ) methodu, girilen değerlerin oluşturulan dizinin ilk boş yerine yerleştiriliyor, eğer yerleştirilemiyorsa istisna fırlatıyor.

Eva Rules:
As usual, there has to be the main function that contains enough tests to prove the program work as expected.
If there isn't, do not grade tihs exercise.
If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

	>	Her zaman olduğu gibi, programın beklendiği gibi çalıştığını kanıtlamak için yeterli testi içeren ana işlev olmalıdır.
	Eğer yoksa egzersizi derecelendirmeyin.
	Arayüz(interface) olmayan herhangi bir sınıf, geleneksel kanonik sınıf formunda değilse, bu alıştırmaya not vermeyin.

Class and member functions / Sınıf ve üye işlemleri:
There is a class that complies with the constraints of the subject.
Its member function use STL alogrithms to find their result as much as possible.
Finding the shortest span can't be done only by subtracting the two lowest numbers (take a close look at the subject example).

	>	Konunun kısıtlamalarına uyan bir sınıf var.
	Üye işlevi, sonuçlarını mümkün olduğunca bulmak için STL alogritmalarını kullanır.
	En kısa aralığı bulmak, yalnızca en düşük iki sayıyı çıkararak yapılamaz (konu örneğine yakından bakın).

Improved addNumber funtion / Geliştirilmiş addNumber methodu:
There's a way to add numbers that's more practical than calling the addNumber() function repeatedly.

	>	Sayıları eklemenin addNumber() işlevini tekrar tekrar çağırmaktan daha pratik bir yolu vardır.
*/
int main( void ){
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(9);

	// std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << sp << std::endl;

	return (0);
}
