#include "RPN.hpp"

/*
	---> C++ STL / Standard Template Library <---
	--->  Reverse Polish Notation / Ters Lehçe Notasyonu / RPN <---
	Subject Çeviri:
		Bu kısıtlamalara sahip bir program oluşturmalısınız:
			-> Programın adı RPN'dir.
			-> Programınız argüman olarak ters çevrilmiş bir Polish matematiksel ifadesini almalıdır.
			-> Bu işlemde kullanılan sayılar her zaman 10'dan küçük olacaktır
			-> Programınız bu ifadeyi işlemeli ve standart çıktıda doğru sonucu vermelidir.
			-> Programın yürütülmesi sırasında bir hata oluşursa, standart çıktıda bir hata mesajı görüntülenmelidir.
			-> Programınız şu belirteçlerle işlemleri gerçekleştirebilmelidir: "+ - / *"

		!!! Bu alıştırmayı doğrulamak için kodunuzda en az bir kapsayıcı(container) kullanmalısınız.

		??? Parantezleri veya ondalık sayıları yönetmenize gerek yoktur.

		İşte standart kullanıma bir örnek:
---------------------------------------------------------------------------------------------------------------
			$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
			42
			$> ./RPN "7 7 * 7 -"
			42
			$> ./RPN "(1 + 1)"
			Error
			$>
---------------------------------------------------------------------------------------------------------------

		!!! Uyarı: Bir önceki alıştırmada kullandığınız kap(lar) burada yasaklanmıştır. Bu alıştırmayı doğrulamak için kullandığınız kap(lar) bu modülün geri kalanında kullanılamayacaktır.


Not:
	Polish mathematical expression (Polonya'lilarin eskiden kullandigi bir hesaplama yöntemi)
	std::stack kullandim cunku girdigimiz degerler sirasiyla hesaplaniyor ayni ust uste koyulmus tabaklar gibi(stack)

	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	Burada bizden 8 ile 9'u carp(*) sonucu hafizada tut.
	72 ile 9'u cikar(-) sonucu hafizada tut.
	.
	.
	.

	Parantezleri veya ondalık sayıları yönetmenize gerek yoktur.
	./RPN "(1 + 1)"
	Error

	bu ( falan \ [ gibi seyleri bosver ugrasma diyor
	en son da iste sonucu yazdir diyor.

--> "3 4 5 + 2 *" RPN ifadesini adım adım değerlendirelim:
	İlk olarak, 3'ü yığına koyarız: [3]
	Sonra, 4'ü yığına koyarız: [3, 4]
	Daha sonra, 5'i yığına koyarız: [3, 4, 5]
	"+" operatörüyle karşılaştığımızda, en üstteki iki elemanı alırız (4 ve 5) ve toplarız: [3, 9]
	Şimdi, 2'yi yığına koyarız: [3, 9, 2]
	"*" operatörüyle karşılaştığımızda, en üstteki iki elemanı alırız (9 ve 2) ve çarparız: [3, 18]
	Sonuç olarak, "3 4 5 + 2 *" ifadesi değerlendirildiğinde, yığında sadece bir eleman olan 18 kalır. Yani, sonuç 18'dir.


Eva Rules:

*/
int main(int argc, char **argv){

	try
	{
		RPN::checkArg(argc, argv);
		RPN::printRPN();
	}
	catch ( std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
