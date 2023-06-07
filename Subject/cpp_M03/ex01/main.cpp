#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
*/
int	main( void )
{

	ScavTrap Jack("Jack");
	ScavTrap Emanuel("Emanuel");

	Jack.attack("Emanuel");
	Emanuel.takeDamage(Jack.getDamage());

	Jack.guardGate();

	Emanuel.attack("Jack");
	Jack.takeDamage(Emanuel.getDamage());

	Jack.beRepaired(5);
	Emanuel.beRepaired(4);


//Virtual yapısının kullanım örneği, ClapTrap.hpp içindeki takeDamage'i virtual olarak kullan/kullanma
	// ClapTrap *Base;
	// ScavTrap Jack("Jack");
	// ScavTrap Emanuel("Emanuel");

	// Base = &Jack;

	// Base->attack("Emanuel");
	// Base->takeDamage(10);

	return (0);
}
