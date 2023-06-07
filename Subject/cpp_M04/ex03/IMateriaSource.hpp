#ifndef IMATERIASOURCE_HPP
 #define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class	AMateria;
/*
	Bu class saf sanal yöntemlere(pure virtual methods) sahip olduğundan dolayı bir soyut sınıf olarak ele alınır.
	Yani bu class saf sanal yöntemlere sahip bir arayüz(interface) gibi davranır.

	IMateriaSource class'ı soyut bir sınıf olduğundan dolayı implement(bu classın altında class türetilmelidir) edilmesi gerekiyor.
	Bir abstract sınıfın (abstract class) sanal yıkıcı (virtual destructor) sahip olması, o sınıfın bir arayüz (interface class) olarak adlandırılmasına engel değildir.
	Sanal yıkıcıya sahip bir abstract sınıf, arayüz olarak kullanılabilir çünkü sanal yıkıcıların bir arayüz sınıfında olması mümkündür.
	Ancak sanal yıkıcıların bir arayüz sınıfı için genellikle gereksiz olduğu düşünülebilir, çünkü bir arayüz sınıfı genellikle saf sanal işlevler içerir ve hiçbir veri üyesi yoktur, dolayısıyla bir yıkıcıya ihtiyaç yoktur.
	Bundan dolayı IMateriaSource class'ı bir interface class'dır.
*/
class IMateriaSource{

	public:
		virtual ~IMateriaSource(){}
		virtual void learnMateria( AMateria * ) = 0;
		virtual AMateria *createMateria( std::string const &type ) = 0;
};

#endif
 