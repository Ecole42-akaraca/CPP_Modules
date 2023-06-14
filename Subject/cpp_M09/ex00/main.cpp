#include "BitcoinExchange.hpp"

/*
	---> C++ STL / Standard Template Library <---
	--->  Bitcoin Exchange / Bitcoin borsa <---
	Subject Çeviri:
		Belirli bir tarihte belirli miktarda bitcoin değerini veren bir program oluşturmalısınız.

		Bu program, zaman içinde bitcoin fiyatını temsil edecek csv formatında bir veritabanı kullanmalıdır. Bu veri tabanı bu konu ile birlikte sağlanmaktadır.

		Program, değerlendirmek üzere farklı fiyatları/tarihleri ​​saklayan ikinci bir veri tabanını girdi olarak alacaktır.

		Programınız şu kurallara uymalıdır:
			-> Programın adı btc'dir.
			-> Programınız argüman olarak bir dosya almalıdır.
			-> Bu dosyadaki her satır şu biçimi kullanmalıdır: "tarih | değer". (date | value)
			-> Geçerli bir tarih her zaman şu biçimde olacaktır: Yıl-Ay-Gün.
			-> Geçerli bir değer, kayan nokta veya 0 ile 1000 arasında pozitif bir tamsayı olmalıdır.

		!!! Bu alıştırmayı doğrulamak için kodunuzda en az bir kapsayıcı kullanmalısınız. Olası hataları uygun bir hata mesajı ile ele almalısınız.

		İşte bir input.txt dosyası örneği:
---------------------------------------------------------------------------------------------------------------
			$> head input.txt
			date | value
			2011-01-03 | 3
			2011-01-03 | 2
			2011-01-03 | 1
			2011-01-03 | 1.2
			2011-01-09 | 1
			2012-01-11 | -1
			2001-42-42
			2012-01-11 | 1
			2012-01-11 | 2147483648
			$>
---------------------------------------------------------------------------------------------------------------

		Programınız girdi dosyanızdaki değeri ve ilişkili tarihi kullanacaktır.

		Programınız, standart çıktıda, veri tabanınızda belirtilen tarihe göre değerin döviz kuru ile çarpılması sonucunu göstermelidir.

		Aşağıda programın kullanımına bir örnek verilmiştir:
---------------------------------------------------------------------------------------------------------------
			$> ./btc
			Error: could not open file.
			$> ./btc input.txt
			2011-01-03 => 3 = 0.9
			2011-01-03 => 2 = 0.6
			2011-01-03 => 1 = 0.3
			2011-01-03 => 1.2 = 0.36
			2011-01-09 => 1 = 0.32
			Error: not a positive number.
			Error: bad input => 2001-42-42
			2012-01-11 => 1 = 7.1
			Error: too large a number.
			$>
---------------------------------------------------------------------------------------------------------------

		!!! Uyarı: Bu alıştırmayı doğrulamak için kullandığınız (kap veya kaplar)/(container veya containerlar) artık bu modülün geri kalanında kullanılamayacaktır.
Not:
	input.txt'yi tarihsel olarak bulunan coin miktarının data seti gibi düşün.
	Bu data seti programı çalıştırırken veriyoruz (./btc input.txt).
	Bu seti satır satır okuyup, ekrana çıktı vermek için kontrol ediyoruz.
	Bu kontrolden önce bizim data.csv dosyamızda bulunan coin fiyatlarının günlük değerleri bulunuyor.
	Bu değerleri bizim bir container'a/array'e atamamız gerekiyor.
	Bu işlemide tamamladıktan sonra artık tarihsel olarak coin miktarlarının ekrana bastırılma işlemini gerçekleştiriyoruz.

	input.txt'te verilen tarih, data.csv'de yok ise, verilen tarihden önceki günün fiyatı alınıyor.
	input.txt'teki coin miktarı 0 ila 1000 arasında olmalıdır.
	Bu değer float veya int olabilir.
	Bu durumlar haricinde, tarihin yanlış girilmesi(absürt bir tarih) veya verilen coin miktarının sınırları dışında verilmesi durumunda istisna fırlatılır.


->??Std::map visualization
->??Red tree
->??std::map container'ı, elemanları doğal bir sıralama düzenine göre saklar. Bu sıralama, anahtarların std::less varsayılan karşılaştırma fonksiyonunu kullanarak gerçekleştirilir.
->??->>cpp_m06_ex00 - cpp_m01_ex04
Eva Rules:

*/
int main( int argc, char **argv ){

	if (argc != 2)
	{
		std::cout << RED "Error, not enought inputs!" END << std::endl;
		return (1);
	}
	if (!Bitcoin::checkFile(argv[1]) || !Bitcoin::checkFile(Bitcoin::getDataName()))
		return (1);
	Bitcoin::setFileName(argv[1]);
	Bitcoin::setContainer();
	Bitcoin::printContainer();
	std::cout << Bitcoin::getFileName() << std::endl;

/*
	std::map<std::string, double> test;
	test.insert(std::make_pair("ahmet", 42));

	std::pair<std::string, double> firstElement =  *test.begin();
	std::cout << firstElement.first << " - " << firstElement.second << std::endl;
*/
}
