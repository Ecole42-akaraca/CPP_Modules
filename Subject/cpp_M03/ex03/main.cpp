#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamonTrap.hpp"

/*
General Rules / Genel Kurallar:
	-> Write class names in UpperCamelCase format.
			for: Files names, classes, functions, member functions, attributes as required in the guidelines.
			   : Dosya isimleri, sınıf isimleri, fonksiyonlar, üye isimleri, yönergelerde belirtilen nitelik isimleri.
		Example: firstName, name, secondName

	-> Unless specified otherwise, every output messages must be ended by a new-line character and displayed to the standard output.
		: Aksi belirtilmediği sürece, her çıktı mesajı yeni bir satır karakteri ile sonlandırılmalıdır ve standart çıktıda görüntülenmelidir.

	-> From Module 02 to Module 08, your classes must be designed in the Orthodox Canonical Form, except when explicitely stated otherwise.
		: Modül 02'den 08'e kadar, sınıflar Orthodox yapısında olmalıdır.
		: Default constructor, Copy constructor, Destructor, Copy assignment operator

	-> -Wshadow -Wno-shadow compiler flags:
		https://stackoverflow.com/questions/2958457/gcc-wshadow-is-too-strict
		https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
		-> -Wshadow
			:-Wshadow derleyici bayrağı (compiler flag) C++ kodunuzdaki gölgelenen (shadowed) değişkenleri tespit etmenizi sağlar.
			Gölgelenen değişkenler, iç içe geçmiş blokların farklı düzeylerinde aynı isimle tanımlanmış değişkenlerdir.
			Bu durum, özellikle büyük projelerde hata yapmaya neden olabilir.
			Örneğin, bir değişkenin yanlışlıkla bir iç blokta yeniden tanımlanması, dış bloktaki aynı isimli değişkeni gölgeleyebilir ve yanlış sonuçlara yol açabilir.
			-Wshadow bayrağı etkinleştirildiğinde, derleyici herhangi bir gölgelenen değişken tespit ederse uyarı verir.
			Bu uyarılar, potansiyel hataları önceden belirlemenize ve kodunuzun daha güvenli hale getirilmesine yardımcı olabilir.

			örn:{

				int x = 10;
    			if (x > 5) {
    			    int x = 5; // if içerisinde yeniden oluşturulan x değişkeni, dışarıda oluşturulmuş x değişkenini gölgeler.
    			    std::cout << "inner x = " << x << std::endl; // 5 çıktısını verir.
    			}
    			std::cout << "outer x = " << x << std::endl; // 10 çıktısını verir.
			}

		-> -Wno-shadow
			:-Wno-shadow bayrağı, g++ derleyicisinde, -Wshadow bayrağından gelen uyarıları devre dışı bırakır.
			Bu bayrak, özellikle bazı durumlarda uyarıların gereksiz olduğunu düşündüğünüzde kullanışlı olabilir.

			örn:{
			
				int val = 5; //global değişken

				void foo(int val) { // fonksiyonden global değişken parametresi alınıyor.
				    std::cout << "Local val = " << val << std::endl;
				    std::cout << "Global val = " << ::val << std::endl;
				}
				int main() {
			    	foo(10);
			    	return 0;
				}
			}
			hata:{
				warning: declaration of 'val' shadows a global declaration [-Wshadow]
 				void foo(int val)
			}
			:Bu tarz bir kullanımda sadece -Wshadow kullanıldığında hata döndürecektir.
			-Wno-shadow kullanıldığında ise bu tarz hatalar gösterilemeyecektir.
		
*/
int	main( void )
{
	// DiamondTrap::ScavTrap::ClapTrap::attack();
	DiamondTrap Michel("Michel");
	DiamondTrap John("John");

	Michel.attack("John");
	John.takeDamage(Michel.getDamage());

	John.attack("Michel");
	Michel.takeDamage(John.getDamage());

	Michel.beRepaired(10);
	John.beRepaired(5);
	Michel.whoAmI();

	// ClapTrap *Base_M;
	// ClapTrap *Base_J;
	// DiamondTrap Michel("Michel");
	// DiamondTrap John("John");

	// Base_M = &Michel;
	// Base_J = &John;

	// Base_M->attack("John");
	// Base_J->takeDamage(Base_M->getDamage());

	// Base_J->attack("Michel");
	// Base_M->takeDamage(Base_J->getDamage());

	// Base_M->beRepaired(10);
	// Base_J->beRepaired(5);

	return (0);
}
