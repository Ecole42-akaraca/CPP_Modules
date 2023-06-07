#ifndef ICHARACTER_HPP
 #define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;
/*
	Bu class saf sanal yöntemlere(pure virtual methods) sahip olduğundan dolayı bir soyut sınıf olarak ele alınır.
	Yani bu class saf sanal yöntemlere sahip bir arayüz(interface) gibi davranır.

	ICharacter class'ı soyut bir sınıf olduğundan dolayı implement(bu classın altında class türetilmelidir) edilmesi gerekiyor.
	Bir abstract sınıfın (abstract class) sanal yıkıcı (virtual destructor) sahip olması, o sınıfın bir arayüz (interface class) olarak adlandırılmasına engel değildir.
	Sanal yıkıcıya sahip bir abstract sınıf, arayüz olarak kullanılabilir çünkü sanal yıkıcıların bir arayüz sınıfında olması mümkündür.
	Ancak sanal yıkıcıların bir arayüz sınıfı için genellikle gereksiz olduğu düşünülebilir, çünkü bir arayüz sınıfı genellikle saf sanal işlevler içerir ve hiçbir veri üyesi yoktur, dolayısıyla bir yıkıcıya ihtiyaç yoktur.
	Bundan dolayı ICharacter class'ı bir interface class'dır.
*/
class ICharacter{

	public:
		virtual	~ICharacter(){}
		virtual std::string const & getName() const = 0;
		virtual void equip( AMateria *m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter &target ) = 0;
};

#endif
