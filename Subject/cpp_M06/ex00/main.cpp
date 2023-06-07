#include "ScalarConverter.hpp"

/*
	---> C++ casts <---
	---> Conversion of scalar types / Skaler tiplerin dönüşümü <---
	Subject Çeviri:
	
	İzin verilen fonksiyonlar:
		Bir dizeden int'e, float'a veya double'a dönüştürmek için herhangi bir işlev. Bu yardımcı olacak, ancak tüm işi yapmayacak.
	
	"convert" yöntemini içerecek statik bir sınıf "ScalarConverter" yazın,
		en yaygın biçiminde bir C++ hazır bilgisinin dize temsilini parametre olarak alır.
	
	Bu hazır bilgi, aşağıdaki bir "skaler" türlerinden birine ait olmalıdır:
		-> char
		-> int
		-> float
		-> double
	
	"char" parametreleri dışında sadece ondalık gösterim kullanılacaktır.

	"char" değişmezlerine örnekler: 'c', 'a', ...

	İşleri basitleştirmek için lütfen görüntülenemeyen karakterlerin giriş olarak kullanılmaması gerektiğini unutmayın.
	Karaktere dönüştürme görüntülenemiyorsa bilgilendirici bir mesaj yazdırır.

	"int" değişmezlerine örnekler: 0, -42, 42, ...

	"float" değişmezlerine örnekler: 0.0f, -4.2f, 4.2f, ...

	Bu sözde değişmezleri de halletmelisiniz: -inff, +inff and nanf.

	"double" değişmezlerine örnekler: 0.0, -4.2, 4.2, ...

	Bu sözde değişmezleri de halletmelisiniz: -inf, +inf and nan.

	Sınıfınızın beklendiği gibi çalıştığını test etmek için program yazın.

	Önce parametre olarak iletilen hazır bilginin türünü algılamanız,
		onu dizeden gerçek türüne dönüştürmeniz,
		ardından onu açıkça(explicitly) diğer üç veri türüne dönüştürmeniz gerekir.
	Son olarak, sonuçları aşağıda gösterildiği gibi görüntüleyin.

	Bir dönüştürme anlamsızsa veya taşarsa,
		kullanıcıya tür dönüştürmenin imkansız olduğunu bildiren bir mesaj görüntüleyin.
	Sayısal limitleri ve özel değerleri işlemek için ihtiyacınız olan tüm başlıkları ekleyin.

---------------------------------------------------------------------------------------------------------------
	./convert 0
	char: Non displayable
	int: 0
	float: 0.0f
	double: 0.0

	./convert nan
	char: impossible
	int: impossible
	float: nanf
	double: nan

	./convert 42.0f
	char: '*'
	int: 42
	float: 42.0f
	double: 42.0
---------------------------------------------------------------------------------------------------------------
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED "Takes one input!" END << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::ScalarConvertingString(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << END << std::endl;
	}
	return (0);
}
