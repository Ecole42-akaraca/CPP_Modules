#ifndef AMATERIA_HPP
 #define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class	ICharacter;
/*
	Bu class saf sanal yöntemlere(pure virtual methods) sahip olduğundan dolayı bir soyut sınıf olarak ele alınır.
	Yani bu class saf sanal yöntemlere sahip bir arayüz(interface) gibi davranır.

	AMateria class'ı soyut bir sınıf olduğundan dolayı implement(bu classın altında class türetilmelidir) edilmesi gerekiyor.
	AMateria sınıfı bir soyut sınıfıdır(abstract class).
	Interface olmamasının nedeni class'a ait pure virtual olmayan methodların kod bloğunun tanımlanması gerektiğinden dolayıdır.
*/
class	AMateria{

	protected:
		std::string type;

	public:
		AMateria();
		AMateria( const AMateria &ref );
		AMateria( std::string const &type );
		AMateria &operator=( const AMateria &ref );
		virtual ~AMateria();

		std::string const &getType( ) const; // Returns the materia type

		virtual AMateria *clone( ) const = 0;
		virtual void use( ICharacter &target );
};

#endif
