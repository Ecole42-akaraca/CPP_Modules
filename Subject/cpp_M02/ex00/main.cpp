#include "Fixed.hpp"

/*
Fixed Point(Sabit Nokta) tüm sayıları belirli bir faktöre ölçeklenmiş tamsayılar olarak ele almaktır.
Floatfield biçim bayrağını sabit olarak ayarlamak için kullanılır.
Floatfield sabit olarak ayarlandığında, kayan noktalı değerler sabit nokta gösterimi kullanılarak yazılır.
Sabit noktalı sayı, virgülden sonra sabit sayıda basamak olduğu anlamına gelir.
Kayan noktalı sayı, ondalık noktadan sonra değişen sayıda haneye izin verir.
Kayan noktalı sayılar daha genel amaçlıdır, çünkü çok küçük veya çok büyük sayıları aynı şekilde temsil edebilirler, ancak ondalık basamağın gittiği yer için fazladan depolamaya gerek vardır.
Kayan noktanın bir dezavantajı olarak görülür.

Kayan noktalı sayı için örnek(float):
	54.125

->	Tam bölünüyorsa 0, bulunduğu sayıdan daha eksiğini tam bölen bir sayıya bölünüyorsa 1 değerini alır.
Tam kısım için binarysini bulma:
	54 / 2 = 27	-> 0
	27 / 2 = 13	-> 1
	13 / 2 = 6	-> 1
	6 / 2 = 3	-> 0
	3 / 2 = 1	-> 1
				-> 1
	54'ün binary gösterimi -> 110110'dır.

->	Tam kısım 2^0 2^1 2^2 2^3 ... şeklinde gösterilir.
->	Kesirli kısım ise 2^(-1) 2^(-2) 2^(-3) ... şeklinde gösterilir.
->	Tam ve Kesirli gösterimi ise: ... 2^3 2^2 2^1 2^0 . 2^(-1) 2^(-2) 2^(-3) ... şeklindedir.
->	Binary olarak aldığı değerler üstteki örneğe göre sırasıyla: ... 8 4 2 1 . (0.5) (0.25) (0.125) ... şeklindedir. 

->	2 ile çarpımı sonucunda 1'den küçük ise 0, değilse 1 değerini alır.
	Eğer çarpımın sonucunda 1 veya 1'den büyük bir sayı çıkarsa kesirli(küsürat) kısmı alınarak işleme devam edilir.
	Bu işlem 1.0 değerini elde edene kadar devam eder.
Kesirli kısım için binarysini bulma:
	0.125 * 2 = 0.250	-> 0
	0.250 * 2 = 0.500	-> 0
	0.500 * 2 = 1.0		-> 1
	125'in binary gösterimi -> 001'dir.

54.125 sayısının binary gösterimi -> 110110.001'dir.
->	Floating Point'te solda 1 adet 1 kalana kadar kaydırma işlemi vardır.
	Bu kuralı bu sayıya uygularsak: 1.10110001 x 2^5 elde edilir.
	Eğerki sayımızda tam sayı olmasaydı ve noktanın sağında sadece 1 olsayı bu durumda sağa kaydırma işlemi yapılırdı ve solda en az bir kalana kadar bu işleme devam edilirdi.
		örn: 0.001001 binarysine sahip olduğumuzu varsayalım,
		bu durumda kaydırdığımız sayımız: 1.001 x 2^(-3) olurdu.

->	Basamak sayısını 127 ile toplamamız gerekmektedir.
	->	Üs alanının tüm bitleri 0'a ayarlanırsa, kayan noktalı sayı 0,0'dır.
		Üs alanının tüm bitleri 1'e ayarlanırsa ve kesir kısmının tüm bitleri 0'a ayarlanırsa, kayan noktalı sayı sonsuzdur.
		Üs alanının tüm bitleri 1'e ayarlanırsa ve kesir bölümünün tüm bitleri 0'a eşit değilse, kayan noktalı sayı NaN'dir.
		Yani, tek kesinlikte üs alanını temsil etmek için 8 bitimiz ve 2 özel değerimiz var, yani temelde 256 - 2 = 254 üs olarak temsil edilebilecek değerimiz var.
		Böylece, -126 ila 127'yi üs içinde etkili bir şekilde temsil edebiliriz, yani 254 değer (126 + 127 + 1), 0 için 1 eklenir.

		Exponent Value(üs)		Mantissa(kesir)		Represents(temsili değeri)
			11111111				All zeros				inf
			11111111				Not all zeros			not a number (NAN)
			00000000				All zeros				zero
			00000000				Not all zeros			subnormal (very small)

	5 + 127 = 132 (10'luk tabanda)değerini elde etmiş oluruz. Binary olarak: 10000100'dir.
	Elde edilen bu binary, floating point'in üssünü temsil eder.
	Kesirli kısmını temsil eden binary ise: 1.10110001'deki noktanın sağındaki binary değeridir yani 10110001'dir.
	Yani 54.125 sayısının floating pointteki gösterimi: 1000010010110001'dir.
	Sayının pozitif/negatif temsili için floating point binarysinin başına: pozitif için 0, negatif için 1 koyulur.
	Yani son olarak binary gösterimimiz: 01000010010110001'dir.

											İşaret Biti(Sign) 	- 	Üs Değeri(Exponent)	- 	Kesir Değeri(Mantissa) 	- 	Exponent Bias
	32 bit single precision (float) için:		1 bit					8 bits				23 bits(+1 not stored)		2^(8 - 1) - 1 = 127
	64 bit double precision (double) için:		1 bit					11 bits				52 bits(+1 not stored)		2^(11 - 1) - 1 = 1023
	128 bit quadruple precision için:			1 bit					15 bits				112 bits(+1 not stored)		2^(15 - 1) - 1 = 16383

Fixed Point:
->	Subjectte fractionalbits(kesirli bitler) değeri 8 olarak verilmiş.
	Gelen sayı tam sayı ise örn: 20, bu sayıyı 8 bit kaydırınca elde edilen değer 5120'dir.
	Yani 2^8 katı, 256 katıdır.

	0000000000010100 -> 20 sayısının binary gösterimi
	0001010000000000 -> 8 bit sola kaydırılmış binary gösterimi

	Bu şekilde elde edilen bu binary değeri ile int değer karşılaştırması daha kolay yapılmaktadır.
	Elde edilen bu binary değeri karşılaştırma işlemlerinde kullanılmaktadır.
	Kaydırılmış halde tutulan değişkenin çıktısı alınmak istendiğinde 8 bit sağa kaydırılmış yani 256'ya bölünmüş halde verilecektir.
	
	Eğer ki bu değişken üzerinde --x, x--, ++x, x++ gibi arttırma veya azaltma operatörleri kullanılırsa, kesir değerinde artma gerçekleşecektir.
	x = 20 olsun ve x++; kullanıldığını varsayalım, x'in değeri 21 değil, 20.0039 olacaktır.
	Bunun nedeni arttırdığımız değer değişkenin saf hali değil, kaydırılmış halidir.
	Yani 20*256 + 1 olarak işleme alınmaktadır.

->	Kesirli sayı için örn: Sayımız 23.15 olsun;
	0000000000010111 -> 23 sayısının binary gösterimi

	Kesirli kısım için binary;
	0.15 * 2 = 0.30 -> 0
	0.30 * 2 = 0.60 -> 0
	0.60 * 2 = 1.20 -> 1
	0.20 * 2 = 0.40 -> 0
	0.40 * 2 = 0.80 -> 0
	0.80 * 2 = 1.60 -> 1
	0.60 * 2 = 1.20 -> 1 => döngüye giriyor.
	Binary gösterimine 001001... diyebiliriz.

	10111.001001 -> 23.15 sayının binary gösterimi bu şekilde, bu sayıyı solda 1 adet 1 kalıncaya kadar kaydırdığımızda;
	10111.001001 -> 1.0111001001 * 2^4 olur.
	127 + 4 = 131 -> binarysi 10000011'dir.
	23.15 sayının binarysi: 100000110111001001'dir.
	İşaret'i dahil edersek: 0100000110111001001'dir. Tam olarak bu binary değerine sahip değildir, son kısım kendini tekrarlamaktadır.
	Bu binary değerini integer(tam sayı) gibi kaydırmadığımızdan dolayı, 23.15 değerini 256 ile çarpıp, değere yuvarlama işlemi yapılır.

	float sayılar için: 23.15 * (1 << 8),  tam sayılar için: 20 << 8
*/
int main()
{
	Fixed a;
	Fixed b( a ); // copy constructor.
	Fixed c;

	c = b; // copy assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}