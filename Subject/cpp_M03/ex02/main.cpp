#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	ScavTrap Emanuel("Emanuel");
	ScavTrap Jack("Jack");

	Emanuel.attack("Jack");
	Jack.takeDamage(Emanuel.getDamage());

	Jack.attack("Emanuel");
	Emanuel.takeDamage(Jack.getDamage());

	Emanuel.beRepaired(10);
	Jack.beRepaired(5);
	Emanuel.guardGate();

	std::cout << "----------------------" << std::endl;

	FragTrap Michel("Michel");
	FragTrap John("John");

	Michel.attack("John");
	John.takeDamage(Michel.getDamage());

	John.attack("Michel");
	Michel.takeDamage(John.getDamage());

	Michel.beRepaired(10);
	John.beRepaired(5);
	Michel.highFivesGuys();

	return (0);
}
