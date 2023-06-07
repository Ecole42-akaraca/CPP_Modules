#include "Whatever.hpp"

/*
	---> C++ templates / şablonlar <---
	---> Start with a few functions / Birkaç işlevle başlayın <---
	Subject Çeviri:

	Aşağıdaki işlev/fonksiyon şablonlarını uygulayın:		

		swap: Verilen iki bağımsız değişkenin değerlerini değiştirir. Hiçbir şey döndürmez.

		min: Bağımsız değişkenlerinde iletilen iki değeri karşılaştırır ve en küçük olanı döndürür.
				İkisi eşitse, ikinciyi döndürür.

		max: Bağımsız değişkenlerinde iletilen iki değeri karşılaştırır ve en büyüğünü döndürür.
				İkisi eşitse, ikinciyi döndürür.

	Bu işlevler herhangi bir argüman türü ile çağrılabilir.
	Tek gereksinim, iki bağımsız değişkenin aynı türde olması ve tüm karşılaştırma operatörlerini desteklemesidir.

	!!! Başlık/Header/.hpp dosyalarında şablonlar tanımlanmalıdır.

	Aşağıdaki kodu çalıştırın:
-----------------------------------------------------------------------------------------------------------------------
		int main( void ) {

				int a = 2;
				int b = 3;

				::swap( a, b );
				std::cout << "a = " << a << ", b = " << b << std::endl;
				std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
				std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

				std::string c = "chaine1";
				std::string d = "chaine2";

				::swap(c, d);
				std::cout << "c = " << c << ", d = " << d << std::endl;
				std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
				std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

				return 0
		}
-----------------------------------------------------------------------------------------------------------------------
		Çıktı şu şekilde olmalıdır:
-----------------------------------------------------------------------------------------------------------------------
			a = 3, b = 2
			min(a, b) = 2
			max(a, b) = 3
			c = chaine2, d = chaine1
			min(c, d) = chaine1
			max(c, d) = chaine2
-----------------------------------------------------------------------------------------------------------------------

Not:

	Templates / Şablonlar nedir?
		Aynı yapıya sahip farklı türler veya değerlerle kullanılabilecek fonksiyonlar veya sınıflar oluşturmaya yarayan bir programlama özelliğidir.
		Şablonlar, kod tekrarını azaltarak, tip güvenliği sağlayarak ve programcılara esneklik sağlayarak C++'ın güçlü bir özelliğidir.

		Fonksiyon şablonları, bir işlemi farklı türlerle uygulamak için kullanılabilir.
		Bu, benzer işlemleri farklı türlerle gerçekleştirmemizi sağlar ve böylece kodun tekrarını önler.
		Örneğin, "min" ve "max" işlemlerini gerçekleştiren bir fonksiyon, hem int hem de double türlerindeki değişkenlerle kullanılabilir.

	template<typename T> nedir?
		'template<typename T>' ifadesi, bir fonksiyon veya sınıf şablonunun başlangıcında yer alır ve bu tanımın bir şablon olduğunu belirtir.
		'typename T' ise şablon parametresi olarak kullanılacak olan türdür.
		'typename' anahtar kelimesi, şablon parametresinin bir tür olduğunu belirtir.

		Böylece, template<typename T> ifadesi, bir fonksiyon veya sınıf şablonunun başlangıcında yer alarak, belirtilen şablonun bir parametre alacağını ve bu parametrenin türünün T olduğunu belirtir.
		Şablon parametresi, kod içinde kullanılabilen tür ismidir ve tanımlanmadan önce, kodda yerine geçen türler olarak kullanılacaktır.

		Örneğin, aşağıdaki kod örneğinde, T şablon parametresidir:
-----------------------------------------------------------------------------------------------------------------------
			template<typename T>
			T add(T a, T b) {
				return a + b;
			}
-----------------------------------------------------------------------------------------------------------------------
		Bu fonksiyon şablonu, farklı türlerle çalışabilen toplama işlemi gerçekleştirir.
		Bu fonksiyonu çağırmak için, türü belirtmek gereklidir:
-----------------------------------------------------------------------------------------------------------------------
			int result1 = add<int>(3, 4);       // result1 = 7
			double result2 = add<double>(1.2, 3.4); // result2 = 4.6
-----------------------------------------------------------------------------------------------------------------------
		'add<int>' ifadesi, add fonksiyonunu tamsayılar için çağırdığımızı belirtirken, 'add<double>' ifadesi, add fonksiyonunu ondalık sayılar için çağırdığımızı belirtir.

	Şablonlar için :: kullanımı bir şey ifade ediyor mu?
		:: operatörü, isim alanı çözümlemesinde kullanılırken, şablonlarla birlikte kullanıldığında :: operatörü, özel bir anlam ifade etmez.
		Şablonlar, tip bağımsız kod oluşturmak için kullanılan mekanizmalar olduğu için, :: operatörü bu bağlamda bir anlam ifade etmez.

	-> Elimizde olan değişkenler için method kullanmak istiyorur, bunlar min, max vb. Bu değişkenlerin her tipi için özel method oluşturmak yerine şablon oluşturuyoruz.
		Oluşturduğumuz bu şablonları diğer değişken tipleri; int, double, float vb. için kod kalabalığı olmadan kullanabiliyoruz.
*/
int main(){

	// Awesome x(2), y(4);

	// swap(x,y);
	// std::cout << x << " " << y << std::endl;
	// std::cout << max(x,y) << std::endl;
	// std::cout << min(x,y) << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << ::min(5.3, 2.5) << std::endl;
	std::cout << ::min<int>(a, b) << std::endl;
	std::cout << ::min<int>(3, 3) << std::endl;
	std::cout << ::max<double>(5.000100100, 3.4) << std::endl;
	std::cout << ::min<double>(5, 3.4) << std::endl;
	std::cout << ::max<float>(5.000100100, 3.4) << std::endl;

	return (0);
}
